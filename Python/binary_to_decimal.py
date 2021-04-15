"""
This question is intended to evaluate the following topics:
  A0061 - Create and implement functions to meet a requirement.
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0023 - Declare and implement data types.
  S0029 - Utilize arithmetic operators (PEMDAS +, -, *, /, %) in mathematical equations.
  S0031 - Utilize logical operators to formulate boolean expressions.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0052 - Implement a function that returns a single value.
  S0048 - Implement a function that receives input parameters.
  S0080 - Demonstrate the skill to implement exception handling.
  S0079 - Validate expected input.
  S0113 - Sanitize input data.
  S0110 - Implement error handling.
  S0082 - Implement conditional control flow constructs."""
"""
# Write a function binary_to_decimal that takes an integer containing 0s and 1s (i.e., a "binary" integer)
# and returns its decimal equivalent.
# For example, the decimal equivalent of binary 1101 is 13
# If the input value is not a binary number, the function should return "Invalid Input"
"""

def binary_to_decimal(binaryNumber):
  try:
    if int(binaryNumber) < 0:
      return 'Invalid Input'
    return int(str(binaryNumber),2)
  except ValueError:
    return "Invalid Input"
  
"""
If negative numbers are going to be considered invalid, then that should
be stated in the question ahead of time.
"""
