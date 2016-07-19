import csv
import json
import urllib2
from datetime import datetime

str1 = "EN"
_input_name = 0
_input_pre = 1
_input_lat = 4
_input_lng = 5
_input_elv = 6

_api_key = 'b8d63ed671a6c200e3239e7376f0b0d9'
_base_url = 'https://api.forecast.io/forecast/'


def get_forecast(lat, lng):
    url = _base_url + _api_key + '/' + lat + ',' + lng
    data = json.load(urllib2.urlopen(url))
    dataset = data.get("hourly").get("data")
    return dataset


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
        dataset = get_forecast(row[_input_lat], row[_input_lng])
        name = row[_input_name]
        lat = row[_input_lat]
        lng = row[_input_lng]
        elv = row[_input_elv]
        for row1 in dataset:
            tdata = datetime.fromtimestamp(row1.get("time"))
            curr_time = datetime.now().date().day
            dy_ffst = datetime.fromtimestamp(row1.get("time")).strftime('%d')
            dt = int(dy_ffst)
            dyffst = (dt - curr_time)
            wndspd = row1.get("windSpeed")
            wnddrctn = row1.get("windBearing")
            temp = row1.get("temperature")
            total_list.append([name, str1, dyffst, tdata, wndspd, wnddrctn, temp, lat, lng, elv])
    print total_list
    write_to_csv(total_list)
    input_file.close()


if __name__ == '__main__':
    main()
