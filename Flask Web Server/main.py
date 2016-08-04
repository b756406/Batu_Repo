# coding=utf-8
import gc
from flask import Flask, request, render_template, url_for, redirect, session,flash, jsonify
from wtforms import *
from flask_sqlalchemy import SQLAlchemy
from sqlalchemy.exc import IntegrityError
import hashlib
import random
from model import User
from database import db
from functools import wraps
import json
import urllib2
from json import dumps


app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'mysql://root:b@localhost/tutorialdb'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
app.secret_key = 'super secret key'
db.init_app(app)
db_exits = False
_api_key = 'b8d63ed671a6c200e3239e7376f0b0d9'
_base_url = 'https://api.forecast.io/forecast/'


def login_required(f):
    @wraps(f)
    def wrap(*args, **kwargs):
        if 'logged_in' in session:
            return f(*args, **kwargs)
        else:
            return redirect(url_for('login_page'))
    return wrap


def database_values():
    list = []
    users = User.query.all()
    for user in users:
        list.append(user.username)
        list.append(user.password)
        list.append(user.email)
        list.append(user.apikey)
        list.append(user.count)
        list.append('\n')
    print list
    return json.dumps(list)


def get_forecast(lat, lng):
    url = _base_url + _api_key + '/' + lat + ',' + lng + '?units=si'
    data = json.load(urllib2.urlopen(url))
    return data


def generate_key():
    key = hashlib.sha224(str(random.getrandbits(256))).hexdigest();
    return key


def create_database():
    db_exists = True
    from model import User
    db.create_all()

    """def __repr__(self):
        return '<User %r>' % self.username"""


@app.route("/")
def index():
    if db_exits is False:
        create_database()
    else:
        session.pop['logged_in', None]
    return render_template('index.html')


@app.route("/login/", methods=['GET','POST'])
def login_page():
    error= ''
    try:
        if request.method == "POST":
            username = request.form['username']
            password = request.form['password']
            user = User.query.filter_by(username=username).filter_by(password=password).first()
            if user:
                session['logged_in'] = True
                session['username'] = request.form['username']
                return redirect(url_for('homepage'))
            else:
                return render_template("login.html", error=error)
        else:
            return render_template("login.html", error=error)
    except Exception as e:
        return (str(e))


@app.route("/data", methods=['GET'])
def get_data():
    username = session['username']
    user = User.query.filter_by(username=username).first()
    api_key = user.apikey
    lat = request.args.get('lat')
    lng = request.args.get('lng')
    print "API KEY: {0}, LAT: {1}, LNG: {2}".format(api_key, lat, lng)
    dataset = get_forecast(lat, lng)
    user.count -= 1
    db.session.add(user)
    db.session.commit()
    return jsonify(dataset)


@app.route('/logout')
def logout():
    session.clear
    return redirect('/')


@app.route("/homepage", methods=['GET', 'POST'])
@login_required
def homepage():
    username = session['username']
    user = User.query.filter_by(username=username).first()
    _LAT=39.909462
    _LNG=32.767071
    # api_key = generate_key()
    if user:
        print user.count
    if request.method == 'POST':
        if int(user.count) == 0:
            error = "You can't send any more requests. Please try premium version."
            return render_template('/homepage.html', error=error, url=custom_url)
        else:
            lat = request.form['latitude']
            lng = request.form['longitude']
            if lat != '' and lng != '':
                custom_url = "/data?key={0}&lat={1}&lng={2}".format(user.apikey, lat, lng)
                return render_template('/homepage.html', url=custom_url, count=user.count)
            else:
                error = "Empty fields."
                return render_template('homepage.html', error=error)
    else:
        custom_url = "/data?key={0}&lat={1}&lng={2}".format(user.apikey, _LAT, _LNG)
        return render_template('/homepage.html', url=custom_url, count=user.count)


@app.route("/admin", methods=['GET', 'POST'])
def admin():
    jsonarray = database_values()
    """
        if request.form['id'] == '' :
            print "test"
            User.query.filter_by(username=request.form['username']).update(count=request.form['count'])
            db.session.commit()
            print "Committed"
            return redirect(url_for('admin'))
        else:
            User.query.filter_by(id=request.form['id']).delete()
            db.session.commit()
            print "Deleted"
            return redirect(url_for('admin'))
    return render_template('admin.html', jsonarray=jsonarray)
    """
    return render_template('admin.html', jsonarray=jsonarray)


@app.route("/admin/change_credit", methods=['POST'])
def change_credit():
    if request.method == 'POST':
        db.session.query(User).filter_by(username=request.form['username']).update({"count": request.form['count']})
        db.session.commit()
        # print "Committed"
        return redirect(url_for('admin'))


@app.route("/admin/delete_user", methods=['POST'])
def delete_user():
    if request.method == 'POST':
        User.query.filter_by(id=request.form['id']).delete()
        db.session.commit()
        print "Deleted"
        return redirect(url_for('admin'))


@app.route("/about")
@login_required
def about_us():
    return render_template('about.html')


@app.route("/projects")
@login_required
def our_projects():
    return render_template('projects.html')


class RegistrationForm(Form):
    fusername = TextField('Username', [validators.Length(min=4, max=20)])
    femail = TextField('Email', [validators.Length(min=6, max=50)])
    fpassword = PasswordField('Password', [validators.Required(),
                                          validators.EqualTo('confirm', message="Passwords must match.")])
    confirm = PasswordField('Repeat Password')


@app.route("/register/", methods=['GET','POST'])
def register_page():
    try:
        form = RegistrationForm(request.form)
        if request.method == "POST" and form.validate():
            reg_username = form.fusername.data
            reg_password = form.fpassword.data
            reg_email = form.femail.data
            reg_access_key = generate_key()
            reg_count = 750
            try:
                user_register = User(reg_username, reg_password, reg_email, reg_access_key, reg_count)
                db.session.add(user_register)
                db.session.commit()
                User.query.all()
                print "Kullanici kaydedildi."
                return redirect(url_for('login_page'))
            except IntegrityError:
                print "Kullanici zaten kayitli"
    except Exception as e:
        return (str(e))
    return render_template("register.html", form=form)


if (__name__) == '__main__':
    app.secret_key = 'super secret key'
    app.run(use_reloader=False)