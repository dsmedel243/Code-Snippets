#! /usr/bin/env python3

import os
import requests

user = os.getenv('USER')
directory = '/home/{}/supplier-data/descriptions'.format(user)
list1 = ["name", "weight", "description", "image_name"]


for filename in os.listdir(directory):
  # Create a dictionary
  dictionary1 = {}

  # Create a string to open the file
  file_location = directory + "/" + filename

  # Open the file
  with open(file_location, 'r+', encoding="utf-8") as file:
    dictionary1[list1[0]] = file.readline().strip()
    dictionary1[list1[1]] = file.readline().strip().strip(" lbs")
    dictionary1[list1[2]] = file.readline().strip().replace(u'\u2019',u'')
    dictionary1[list1[3]] = (filename.strip(".txt")) + ".jpeg"
#  print(dictionary1)
  try: 
    response = requests.post("http://104.154.86.59/fruits/", json=dictionary1)
    print(response.request.url)
    print(response.status_code)
    response.raise_for_status()
  except HTTPError as http_err:
    print("HTTP error occurred: {}".format(http_err))
  except Exception as err:
    print("Other error: {0}".format(err))
  else:
    print('Success!')
