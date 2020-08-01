import re

# Modify to the international format, with "+1-" in front of the phone number
def transform_record(record):
  new_record = re.sub(r"([\w ]*),([0-9-]*),([A-Za-z]*)", r"\1,+1-\2,\3", record)
  return new_record
  
#example:
# print(transform_record("Sabrina Green,802-867-5309,System Administrator")) 
# Sabrina Green,+1-802-867-5309,System Administrator

# Return words with 3 or more consecutive vowels
def multi_vowel_words(text):
  pattern = r"\w*[aeiou]{3,}\w*"
  result = re.findall(pattern, text)
  return result
  
#example:
# print(multi_vowel_words("The rambunctious children had to sit quietly and await their delicious dinner.")) 
# ['rambunctious', 'quietly', 'delicious']

# Replace hash mark with double slashes 
def transform_comments(line_of_code):
  result = re.sub(r"#+", r"//", line_of_code)
  return result
  
#example:
# print(transform_comments("### Start of program")) 
# Should be "// Start of program"

# Convert U.S. phone number format to a more formal format that looks like this: (XXX) XXX-XXXX
def convert_phone_number(phone):
  result = re.sub(r"\b([\d]{3})-([\d]{3})-([\d]{4})\b",r"(\1) \2-\3", phone)
  return result
  
#example:
# print(convert_phone_number("My number is 212-345-9999.")) 
# My number is (212) 345-9999.
