#!/usr/bin/env python3

# Will be used to process supplier fruit description data from supplier-data/descriptions directory
import os
import datetime

from reports import generate_report
from emails import generate_email, send_email

def process_data(directory):
  # Create a list
  name_list = []
  weight_list = []
  for filename in os.listdir(directory):
    # Create a string to open the file
    file_location = directory + "/" + filename
    # Open the file
    with open(file_location, 'r+', encoding="utf-8") as file:
      name = file.readline().strip()
      weight = file.readline().strip()
      name_list.append('name: ' + name)
      weight_list.append('weight: ' + weight)
  paragraph = ""
  for i in range(len(name_list)):
    if name_list[i]:
      paragraph += name_list[i] + '<br />' + weight_list[i] + '<br /><br />'
#  print(paragraph)
  return paragraph

if __name__ == "__main__":
  user = os.getenv('USER')
  directory = '/home/{}/supplier-data/descriptions'.format(user)
  paragraph = process_data(directory)
  date = datetime.date.today().strftime("%B %d, %Y")
  attachment = "/tmp/processed.pdf"
  title = "Processed Update on " + str(date)
  generate_report(attachment, title, paragraph)
  sender = 'automation@example.com'
  recipient = '{}@example.com'.format(user)
  subject = 'Upload Completed - Online Fruit Store'
  body = 'All fruits are uploaded to our website successfully. A detailed list is attached to this email.'
  message = generate_email(sender, recipient, subject, body, attachment)
  send_email(message)

