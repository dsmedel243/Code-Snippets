#!/bin/bash

# Create a text file
> new_file.txt
# Find all the files with the name Jane in the list and assign to the files variable
files="`grep " jane " ../data/list.txt | cut -d ' ' -f 3`"
# Check if the file exist by using the test command
for i in $files;do 
  if test -e $HOME$i; then 
    echo $HOME$i >> new_file.txt
  fi
done
