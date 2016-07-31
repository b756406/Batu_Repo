import hashlib, random
import gc
from flask_sqlalchemy import SQLAlchemy
from sqlalchemy.exc import IntegrityError
from model import User
from database import db


def get_names(name):
    myUser = User.query.all()
    list_names = []
    i = 0
    for user_name in myUser:
        list_names.append(user_name.username)
    while i < len(list_names):
        if name == list[i]:
            return name
        i += 1


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

print get_names('hakan')
print get_passwd('hakan123')