import os
def create_python_script(filename):
  comments = "# Start of a new Python program"
  # Open a file with the w mode
  with open(filename, "w") as file:
    # Add the comments at the start of the code
    file.write(comments)
  # Get the size of the file
  filesize = os.path.getsize(filename)
  return(filesize)

print(create_python_script("program.py"))
