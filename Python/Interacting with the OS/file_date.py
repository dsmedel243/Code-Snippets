import os
import datetime

def file_date(filename):
  # Create the file in the current directory
  os.mkdir(filename)
  timestamp = os.path.getmtime(filename)
  # Convert the timestamp into a readable format, then into a string
  new = datetime.datetime.fromtimestamp(timestamp)
  # Return just the date portion 
  # Hint: how many characters are in “yyyy-mm-dd”? 
  return ("{0:%y%y}-{0:%m}-{0:%d}".format(new))

print(file_date("newfile.txt")) 
# Should be today's date in the format of yyyy-mm-dd
