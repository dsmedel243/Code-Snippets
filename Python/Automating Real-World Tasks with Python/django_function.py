#! /usr/bin/env python3

import os
import requests

# Path to the data
directory = "/data/feedback"
list1 = ["title", "name", "date", "feedback"]

for filename in os.listdir(directory):
  file_location = directory + "/" + filename
  
  with open(file_location) as file:
    # Contents of the file will be converted to a list
    lines = file.readlines()
    
    # Remove all the white lines in list
    lines = [i.strip() for i in lines]
    
    # Create a dictionary using two lists
    feedback_dictionary = dict(zip(list1, lines))
    
    # Post the dictionary to the company's website
    try:
      response = requests.post("http://34.71.204.108/feedback/", json=feedback_dictionary)

      response.raise_for_status()
      
    # Used for error checking
    except HTTPError as http_err:
      print("HTTP error occurred: {}".format(http_err))
    except Exception as err:
      print("Other error: {0}".format(err))
    else:
      print('Success!')
