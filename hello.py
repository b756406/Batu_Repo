from datetime import datetime

value_start = datetime.now()
value_end = 1470041138

value_end_as_datetime = datetime.fromtimestamp(value_end)

delta = value_end_as_datetime.date() - value_start.date()

print delta.days

# print value_start_as_datetime.date()

# value_with_date_str = datetime.strftime(value_end_as_datetime, "%Y%m%d")

# value_with_date = datetime.strptime(value_with_date_str, "%Y%m%d")

# print value_with_date
