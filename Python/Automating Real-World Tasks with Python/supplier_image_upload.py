#!/usr/bin/env python3
import requests
import os

# This example shows how a file can be uploaded using
# The Python Requests module

url = "http://localhost/upload/"
user = os.getenv('USER')

# Location where the images are located
directory = '/home/{}/supplier-data/images'.format(user)

for filename in os.listdir(directory):
  # old_file = /home/{}/supplier-data/images/001.jpeg
  old_file = directory + "/" + filename
  if old_file.endswith('.jpeg'):
    # Open old_file and name it 'opened'
    with open(old_file, 'rb') as opened:
      # Post the 'opened' file to the url
      r = requests.post(url, files={'file': opened})
