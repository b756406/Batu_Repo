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


def takeMatchID():
    q = Match.query(projection=[Match.match_id], distinct=True).filter(Match.match_date == '2018-01-25')
    results = q.fetch()

    query = []
    for data in results:
        '''homename = data.team_home
        awayname = data.team_away
        name = homename + "vs" + awayname'''
        matchId = data.match_id
        query.append(matchId)
    return query

def takeBookmaker():
    q = Match.query(projection=[Match.bookmaker], distinct=True).filter(Match.match_date == '2018-01-25')
    results = q.fetch()

    bookMaker = []
    for data in results:
        bookmaker = data.bookmaker
        bookMaker.append(bookmaker)
    return bookMaker


@app.route('/statistics', methods=['GET'])
def statistic_function():
    csrf = CsrfProtect()
    csrf.init_app(app)                              #fixing the post request problem: csrf is missing!

    query = []
    bookMaker = []
    query = takeMatchID()
    bookMaker = takeBookmaker()

    return render_template('statistics.html', query=query, bookMaker=bookMaker)

@app.route('/statistics', methods=['POST'])
def stat_func():
    query=[]
    query = takeMatchID()
    liste  = []
    liste1 = []
    liste2 = []
    liste3 = []
    liste4 = []
    deger = request.form.get('matchID')  # taking the code from html to python
    deger1 = deger.encode()  # unicode to string
    deger2 = deger1.strip(' ')  # removing the whitespaces that are unnecessery

    bkmaker = request.form.get('bookmaker')  # taking the code from html to python
    bokmaker = bkmaker.encode()  # unicode to string
    bookmaker = bokmaker.strip(' ')  # removing the whitespaces that are unnecessery


    q1 = Match.query().filter(Match.match_id == deger2 and Match.bookmaker == bookmaker)
    dataset = q1.fetch()

    for veri in dataset:
        bookmakername = veri.bookmaker
        insertionDate = veri.date
        liste.append(insertionDate)
        liste1.append(float(veri.odd_home))
        liste2.append(float(veri.odd_draw))
        liste3.append(float(veri.odd_away))
        print(liste)
        print(liste1)
        print(liste2)
        print(liste3)
        print(deger2)
    maxHome = max(liste1)
    maxDraw = max(liste2)
    maxAway = max(liste3)

    return render_template('statistics.html', liste=liste, param=liste, param1=liste1, param2=liste2, param3=liste3,
                           maxHome=maxHome, maxDraw=maxDraw, maxAway=maxAway)





