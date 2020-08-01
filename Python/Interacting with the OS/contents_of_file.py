import os
import csv

# Create a file with data in it
def create_file(filename):
  with open(filename, "w") as file:
    file.write("name,color,type\n")
    file.write("carnation,pink,annual\n")
    file.write("daffodil,yellow,perennial\n")
    file.write("iris,blue,perennial\n")
    file.write("poinsettia,red,perennial\n")
    file.write("sunflower,yellow,annual\n")

# Read the file contents and format the information about each row
def contents_of_file(filename):
  return_string = ""

  # Call the function to create the file 
  create_file(filename)
  line_count = 0
  # Open the file
  with open(filename) as file:
    # Read the rows of the file
    rows = csv.reader(file)
    # Process each row
    for row in rows:
      name, color, type_r = row
      # Format the return string for data rows only
      if line_count != 0:
          return_string += "a {} {} is {}\n".format(color, name, type_r)
      line_count += 1
  return return_string

#Call the function
print(contents_of_file("flowers.csv"))