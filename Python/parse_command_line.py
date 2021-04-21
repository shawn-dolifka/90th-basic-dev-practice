"""
This question is intended to evaluate the following topics:
  A0061 - Create and implement functions to meet a requirement.
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0026 - Utilize standard library modules.
  S0023 - Declare and implement data types.
  S0029 - Utilize arithmetic operators (PEMDAS +, -, *, /, %) in mathematical equations.
  S0038 - Read, parse, write (append, insert, modify) file data.
  S0039 - Create and delete a file.
  S0033 - Utilize assignment operators to update a variable.
  S0042 - Open and close an existing file.
  S0014 - Skill in parsing command line arguments using built-in functionality.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0048 - Implement a function that receives input parameters.
  S0080 - Demonstrate the skill to implement exception handling.
  S0081 - Implement a looping construct."""
'''

Write a python script that parses one or more command line items. The items may be
convertible to either an int or float. If not, assume it is a string.

For example, you should be able to run your file from the command line like:

testfile.py 1 3 4.7 hello 5.4 2 hi

In the above example, there are seven arguments to parse and process.

The script should create a variable to store a running total of an integer.

The running total will be increased accordingly as you parse each
argument from the command line:
   1. If the argument is convertible to an int, add the int to the total
   2. Otherwise, if the argument is convertible to a float, round the float
      to an int and add it to total.
   3. If the argument is convertible to neither an int or float, obtain the
      length of the string and add the length to the total.
      
After all command line arguments have been parsed, write the single total to a file
called output.txt

'''

import sys

total = 0

# First argument is always the name of the file
for argument in sys.argv[1:]:
   if '.' in argument:
      num = float(argument)
      num = round(num,0)
      total += int(num)
      continue
   try:
      int(argument)
   except ValueError:
      total += len(argument)
      continue
   else:
      total += int(argument)
   
file = open("output.txt", "w")
file.write(str(total))
file.close()
