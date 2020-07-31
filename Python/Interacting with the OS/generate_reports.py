#!/usr/bin/env python3

import csv

# Read a CSV file and convert it into a dictionary
def read_employees(csv_file_location):
  with open(csv_file_location) as employee_file:
    # Dialect classes can be registered by name so that callers of the CSV module don't need to know the parameter settings in advance. 
    # Main purpose: Remove any leading spaces while parsing the CSV file.
    csv.register_dialect('empDialect', skipinitialspace=True, strict=True)
    employee_file = csv.DictReader(open(csv_file_location), dialect = 'empDialect')
    # Create a Dictionary and add the list from employee_file
    employee_list = []
    for data in employee_file:
      employee_list.append(data)
    return employee_list

# Receive the list of dictionaries, i.e., employee_list as a parameter and return a dictionary of department:amount.
def process_data(employee_list):
  department_list = []
  # Iterate over employee_list, and add only the departments into the department_list.
  for employee_data in employee_list:
    department_list.append(employee_data['Department'])
  department_data = {}
  # Remove the redundancy and return a dictionary.
  for department_name in set(department_list):
    department_data[department_name] = department_list.count(department_name)
  return department_data

# Create a report.txt with the count of people in each department.
def write_report(dictionary, report_file):
  with open(report_file, "w+") as f:
    for k in sorted(dictionary):
      f.write(str(k)+':'+str(dictionary[k])+'\n')
    f.close()

write_report(process_data(read_employees('/home/student-00-580a76f6de01/data/employees.csv')), '/home/student-00-580a76f6de01/test_report.txt')
#employee_list = read_employees('/home/student-00-580a76f6de01/data/employees.csv')
#print(employee_list)

#dictionary = process_data(employee_list)
#print(dictionary)

# cat report.txt
#Development:4
#Human Resources:2
#IT infrastructure:4
#Marketing:2
#Sales:3
#User Experience Research:2
#Vendor operations:2
  
