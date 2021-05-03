"""
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0026 - Utilize standard library modules.
  S0024 - Declare and/or implement container data type.
  S0023 - Declare and implement data types.
  S0029 - Utilize arithmetic operators (PEMDAS +, -, *, /, %) in mathematical equations.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0052 - Implement a function that returns a single value.
  S0048 - Implement a function that receives input parameters.
  S0081 - Implement a looping construct."""
import re

"""
# Write a function count_pieces that counts the number of digits, non-digit characters (excluding white spaces),
# whitespace characters and words in a string. The function takes a string as input and returns
# a list of integers that represents the counts.
For example, "We have 8 digits.", the output list will be [1, 13, 3, 4],
1: digits (ONLY 8)
13: non-digit characters (excluding white spaces)
3: white spaces
4: words

"""


def count_pieces(testString):
    if len(testString) == 0:
      return [0,0,0,0]
    digit = nondigit = space = 0
    
    if len(testString.replace(" ", "")) == 0:
      words = 0
    else:
      words = len(testString.replace(".","").split())
    
    for i in range(len(testString)):
      if testString[i].isdigit():
        digit += 1
        continue
      if not testString[i].isdigit() and not testString[i].isspace():
        nondigit += 1
        continue
      if testString[i].isspace():
        space += 1
    
    counts = [digit, nondigit, space, words]
    return counts
