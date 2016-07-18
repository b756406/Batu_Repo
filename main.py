import csv
import json
import urllib2
from datetime import datetime

str = "EN"
_input_name = 0
_input_pre = 1
_input_lat = 4
_input_lng = 5
_input_elv = 6

_api_key = 'b8d63ed671a6c200e3239e7376f0b0d9'
_base_url = 'https://api.forecast.io/forecast/'

def get_inputs(name, lat, lng, elv):
    with open('input.csv', 'r') as dosya:
        veri = dosya.read().split(';')
        name = [veri[0], veri[7],  veri[14], veri[21], veri[28], veri[35], veri[42], veri[49], veri[56], veri[63]]
        lat  = [veri[4], veri[11], veri[18], veri[25], veri[32], veri[39], veri[46], veri[53], veri[60], veri[67]]
        lng  = [veri[5], veri[12], veri[19], veri[26], veri[33], veri[40], veri[47], veri[54], veri[61], veri[68]]
        elv  = [veri[6], veri[13], veri[20], veri[27], veri[34], veri[41], veri[48], veri[55], veri[62], veri[69]]


def get_forecast(lat, lng):
    url = _base_url + _api_key + '/' + lat + ',' + lng
    data = json.load(urllib2.urlopen(url))
    return data


def write_to_csv(total):
    output = open("file.csv", "w")
    writer = csv.writer(output, delimiter=';')
    for row in total:
        writer.writerow(row)
    output.close()


def main():
    input_file = open("input.csv", "r")
    reader = csv.reader(input_file, delimiter=";")
    total_list = []
    for row in reader:
        name = row[_input_name]
        data = get_forecast(row[_input_lat], row[_input_lng])
        tdata = datetime.fromtimestamp(data.get("currently").get("time")).strftime('%c')
        doffset = datetime.fromtimestamp(data.get("currently").get("time")).strftime('%d')
        wndspd = data.get("currently").get("windSpeed")
        wnddrctn = data.get("currently").get("windBearing")
        temp = data.get("currently").get("temperature")
        lat = row[_input_lat]
        lng = row[_input_lng]
        elv = row[_input_elv]
        total_list.append([name, str, tdata, doffset, wndspd, wnddrctn, temp,  lat, lng, elv])

    print total_list
    write_to_csv(total_list)
    input_file.close()


if __name__ == '__main__':
    main()
