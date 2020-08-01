import re
# Checks if the text passed qualifies as a top-level web address
def check_web_address(text):
  pattern = r"^[a-zA-Z0-9_.+\-]*.[a-zA-Z]?[a-zA-Z][a-zA-Z]$"
  result = re.search(pattern, text)
  return result != None
  
# Checks for the time format of a 12-hour clock, as follows: the hour is between 1 and 12, with no leading zero, followed by a colon, then minutes between 00 and 59, then an optional space, and then AM or PM, in upper or lower case. 
def check_time(text):
  pattern = r"^([1-9]|1[1-2]):[0-5][0-9]\s?(AM|PM|am|pm)$"
  result = re.search(pattern, text)
  return result != None
  
# Checks the text for the presence of 2 or more characters or digits surrounded by parentheses, with at least the first character in uppercase (if it's a letter)
def contains_acronym(text):
  pattern = r"^[A-Z].*[(]\w\w*[)].*" 
  result = re.search(pattern, text)
  return result != None
  
# Check if the text passed includes a possible U.S. zip code, formatted as follows: exactly 5 digits, and sometimes, but not always, followed by a dash with 4 more digits. 
def check_zip_code (text):
  result = re.search(r" \d\d\d\d\d", text)
  return result != None
