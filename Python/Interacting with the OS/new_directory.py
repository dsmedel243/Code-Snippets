import os

def new_directory(directory, filename):
  # Before creating a new directory, check to see if it already exists
  if os.path.isdir(directory) == False:
    os.mkdir(directory)

  # Change to the new directory
  os.chdir(directory)
  # Get the current working directory
  new = os.getcwd()
  # Create the new file inside of the new directory
  with open (filename, "w") as file:
    pass

  # Return the list of files in the new directory
  return os.listdir(new)

print(new_directory("PythonPrograms", "script.py"))
