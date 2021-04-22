"""
This question is intended to evaluate the following topics:
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
  S0079 - Validate expected input.
  S0081 - Implement a looping construct.
  S0110 - Implement error handling."""
"""


** NOTE: THE SOLUTION FOR THIS PROBLEM IS BASED ON A SPECIFICALLY DEFINED ALGORITHM EXPLAINED BELOW. ALTHOUGH THE AUTOMATED TESTS
** MAY BE SUCCESSFUL, YOUR SOLUTION WILL RECEIVE A MANUAL REVIEW FOR FINAL DETERMINATION OF PASS/FAIL


Write a function compute_euler_exp (x) that estimates the value of e^x (where 'e' is the Euler's number)
by using the formula: e^x = 1 + x/1! + x^2/2! + x^3/3! + ...... (Your function stops after summing 10 terms, i.e. stops at 1/9!)

If exponent passed to the compute_euler_exp function is less then 0, return "Invalid Input"
If the exponent passed to the compute_euler_exp function is not a int type, return "Invalid Input"

The returned  e^x value should be rounded to <<<5 decimal places>>>

Note that n! means the factorial of n: n! = n*(n-1)*(n-2)*.......*3*2*1
For example 5! = 5*4*3*2*1 = 120

"""

import math

def compute_euler_exp(exponent):
  try:
    if exponent < 0:
      return "Invalid Input"
  except TypeError:
      return "Invalid Input"

  euler = 1
  for i in range(1,10):
    euler += (exponent**i)/math.factorial(i)
  return round(euler, 5)
