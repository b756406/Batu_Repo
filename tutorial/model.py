from database import db


class User(db.Model):
    id = db.Column(db.Integer, autoincrement=True, primary_key=True)
    username = db.Column(db.String(80))
    password = db.Column(db.String(80))
    email = db.Column(db.String(120))
    apikey = db.Column(db.String(75))
    count = db.Column(db.Integer)

    def __init__(self, username, password, email, apikey, count):
        self.username = username
        self.password = password
        self.email = email
        self.apikey = apikey
        self.count = count
