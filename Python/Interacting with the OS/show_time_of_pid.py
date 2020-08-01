import re

# Display the date, time, and process id that's inside square brackets
def show_time_of_pid(line):
  pattern = r"(\w+ \d+) ([[0-9]|1[0-9]|2[0-4]]:[0-5][0-9]:[0-5][0-9]) .*[[](\d+)[]]"
  result = re.search(pattern, line)
  return result[1] + " " + result[2] + " pid:" + result[3]
  
#example:
# print(show_time_of_pid("Jul 6 14:01:23 computer.name CRON[29440]: USER (good_user)")) 
# Jul 6 14:01:23 pid:29440
