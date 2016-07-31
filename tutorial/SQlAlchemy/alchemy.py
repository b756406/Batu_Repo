# coding=utf-8
from flask import Flask
from sqlalchemy.exc import IntegrityError
from flask_sqlalchemy import SQLAlchemy
import hashlib, random
from database import db
from model import User

# Create sql alchemy database object.
app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'mysql://root:b@localhost/tutorialdb'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
app.secret_key = 'super secret key'
db.init_app(app)


def get_names(name):
    myUser = User.query.all()
    list_names = []
    i = 0
    for user_name in myUser:
        list_names.append(user_name.username)
        print list_names[user_name]
    while i < len(list_names):
        if name == list[i]:
            return name
        i += 1
        print list_names


def get_passwd(passwd):
    myUser = User.query.all()
    list_pswds = []
    j = 0
    for user_pswd in myUser:
        list_pswds.append(user_pswd.password)
    while j < len(list_pswds):
        if passwd == list_pswds[j]:
            return passwd
        j += 1
    print list_pswds

app.run(use_reloader=False)
