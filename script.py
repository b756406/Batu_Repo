import json
import datetime
import urllib2
import csv

str = "EN"
with open('input.csv', 'r') as dosya:
    veri = dosya.read().split(';')

isim = [veri[0], veri[7],  veri[14], veri[21], veri[28], veri[35], veri[42], veri[49], veri[56], veri[63]]
lat  = [veri[4], veri[11], veri[18], veri[25], veri[32], veri[39], veri[46], veri[53], veri[60], veri[67]]
long = [veri[5], veri[12], veri[19], veri[26], veri[33], veri[40], veri[47], veri[54], veri[61], veri[68]]
elev = [veri[6], veri[13], veri[20], veri[27], veri[34], veri[41], veri[48], veri[55], veri[62], veri[69]]

i = 0
j = 0
counter = 0

datas = []
timedata = []
day_offset = []
windSpeed = []
windDirection = []
temperature = []
while counter < 10:
    url = 'https://api.forecast.io/forecast/b8d63ed671a6c200e3239e7376f0b0d9/{0},{1}'.format(lat[i], long[j])
    data = json.load(urllib2.urlopen(url))
    datas.append(data)
    tdata = datetime.datetime.fromtimestamp(data.get("currently").get("time")).strftime('%c')
    timedata.append(tdata)
    doffset = datetime.datetime.fromtimestamp(data.get("currently").get("time")).strftime('%d')
    day_offset.append(doffset)
    wndspd = datas[i].get("currently").get("windSpeed")
    windSpeed.append(wndspd)
    wnddrctn = datas[i].get("currently").get("windBearing")
    windDirection.append(wnddrctn)
    temp = datas[i].get("currently").get("temperature")
    temperature.append(temp)
    i += 1
    j += 1
    counter += 1


count = 0
c = 0
csv_list = []
with open('file.csv', 'w') as file:

    while count < 10:
        csv_list.append(isim[c])
        csv_list.append('EN')
        csv_list.append(timedata[c])
        csv_list.append(day_offset[c])
        csv_list.append(windSpeed[c])
        csv_list.append(windDirection[c])
        csv_list.append(temperature[c])
        csv_list.append(lat[c])
        csv_list.append(long[c])
        csv_list.append(elev[c])
        csv_list.append('\n')
        file.write(csv_list)
        c += 1
        count += 1


print csv_list