#!/usr/bin/env python3

import sys
import subprocess

# Open file based on the second argument written in the terminal
with open(sys.argv[1]) as file:
  # Put all the lines of the file in the lines variable
  lines = file.readlines()
  for line in lines:
    # Replace all "jane" to "jdoe" in the line
    new_line = line.replace("jane", "jdoe").strip()
    line = line.strip()
    # Use the mv command to rename the files in the file system
    subprocess.run(["mv", line, new_line])
