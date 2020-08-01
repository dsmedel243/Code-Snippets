#!/usr/bin/env python3

import sys
import os
import re

# Search for the specific error in the log file
def error_search(log_file):
  error = input("What is the error? ")
  # returned_errors will be used to list all the ERROR logs
  returned_errors = []
  with open(log_file, mode='r',encoding='UTF-8') as file:
    for log in  file.readlines():
      # Use error_patterns to filter out all the ERROR logs
      error_patterns = ["error"]
      for i in range(len(error.split(' '))):
        error_patterns.append(r"{}".format(error.split(' ')[i].lower()))
      # Check if the log file has the user-defined pattern and add it to the list
      if all(re.search(error_pattern, log.lower()) for error_pattern in error_patterns):
        returned_errors.append(log)
    file.close()
  return returned_errors

def file_output(returned_errors):
  # os.path.expanduser ('~'): returns the home directory of the system instance
  with open(os.path.expanduser('~') + '/data/errors_found.log', 'w') as file:
    # Write all the ERROR logs in the output file
    for error in returned_errors:
      file.write(error)
    file.close()

# Search for a specific error in the log file then output the error into a separate file
if __name__ == "__main__":
  log_file = sys.argv[1]
  returned_errors = error_search(log_file)
  file_output(returned_errors)
  sys.exit(0)
