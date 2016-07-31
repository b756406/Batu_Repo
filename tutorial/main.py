# coding=utf-8
import gc
from flask import Flask, request, render_template, flash, url_for, redirect, session
from wtforms import *
from flask_sqlalchemy import SQLAlchemy
from sqlalchemy.exc import IntegrityError
import hashlib
import random
from model import User
from database import db

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'mysql://root:b@localhost/tutorialdb'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
app.secret_key = 'super secret key'

db.init_app(app)
db_exits = False



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
        myUser = User.query.all()
    return "Homepage"


def get_names(name):
    myUser = User.query.all()
    list_names = []
    i = 0
    for user_name in myUser:
        list_names.append(str(user_name.username))
        print list_names[user_name]
    while i < len(list_names):
        if name == list_names[i]:
            return list_names[i]
            print list_names[i]
        i += 1


def get_passwd(passwd):
    myUser = User.query.all()
    list_pswds = []
    j = 0
    for user_pswd in myUser:
        list_pswds.append(str(user_pswd.password))
    while j < len(list_pswds):
        if "'" + passwd + "'" == list_pswds[j]:
            return list_pswds[j]
            print list_pswds[j]
        j += 1


@app.route("/login/", methods=['GET','POST'])
def login_page():
    error= ''
    try:
        if request.method == "POST":
            # get_names(request.form['username'])
            # get_passwd(request.form['password'])
            if request.form['username'] == get_names(request.form['username']):
                if request.form['password'] == get_passwd(request.form['password']):
                    return render_template('homepage.html')
        else:
            return render_template("login.html", error=error)
    except Exception as e:
        return (str(e))
    return render_template('login.html', myUser=myUser)
@app.route("/homepage")
def homepage():
    #user = User.query.filter_by(id=1).first()
    users = User.query.all()
    list = []
    for user in users:
        list.append(str(user.username))
    l = 0
    print type(list[3])
    while l < len(list):
        if 'batuhan' == list[l]:
            print list[l]
            print len(list)
        else:
            print "Not have that name"
        l += 1
    #return render_template("homepage.html")
    return "test"


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
                return redirect('homepage')
            except IntegrityError:
                print "Kullanici zaten kayitli"

        session['logged_in'] = True

    except Exception as e:
        return (str(e))
    return render_template("register.html", form=form)


if (__name__) == '__main__':
    app.secret_key = 'super secret key'
    app.run(use_reloader=False)