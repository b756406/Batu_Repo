from flask import Flask, render_template, request, abort, session, redirect, make_response
from flask_wtf import Form
from flask_wtf import CsrfProtect

from api import app
from api.models.match import Match

from bs4 import BeautifulSoup

import logging
import re
import datetime
import requests
import ast


def takeData():
    q = Match.query(projection=[Match.match_id]).filter(Match.match_date == '2018-01-25')
    results = q.fetch()

    query = []
    for data in results:
        '''homename = data.team_home
        awayname = data.team_away
        name = homename + "vs" + awayname'''
        matchId = data.match_id
        query.append(matchId)
    return query

@app.route('/statistics', methods=['GET'])
def statistic_function():
    csrf = CsrfProtect()
    csrf.init_app(app)                              #fixing the post request problem: csrf is missing!

    query = []
    query = takeData()

    return render_template('statistics.html', query=query)

@app.route('/statistics', methods=['POST'])
def stat_func():
    query=[]
    query = takeData()
    liste  = []
    liste1 = []
    liste2 = []
    liste3 = []
    liste4 = []
    deger = request.form.get('deger')  # taking the code from html to python
    deger1 = deger.encode()  # unicode to string
    deger2 = deger1.strip(' ')  # removing the whitespaces that are unnecessery

    q1 = Match.query().filter(Match.match_id == deger2)
    dataset = q1.fetch()

    for veri in dataset:
        bookmakername = veri.bookmaker
        insertionDate = veri.date
        liste.append(insertionDate)
        liste1.append(float(veri.odd_home))
        liste2.append(float(veri.odd_draw))
        liste3.append(float(veri.odd_away))
        liste4.append(veri.date)


    return render_template('statistics.html', liste=liste, param=liste, param1=liste1, param2=liste2, param3=liste3)





