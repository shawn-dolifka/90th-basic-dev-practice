"""
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0023 - Declare and implement data types.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0052 - Implement a function that returns a single value.
  S0048 - Implement a function that receives input parameters.
  S0081 - Implement a looping construct.
  S0082 - Implement conditional control flow constructs."""
'''
# A palindrome is a number or a text phrase that reads the same backwards or forwards.
# For example each of the following five digit integers is a palindrome: 12321, 55555, 45554, and 11611.
# Write a function palindrome that that takes in a ***five-digit*** integer and determine whether it is a palindrome

if it is a palindrome, the function should return the string:  "palindrome"
if it is not a palindrome, the function should return the string: "NOT a palindrome"
'''

YES = "palindrome"
NO = "NOT a palindrome"

def palindrome(number):
  i = 0
  j = 4
  
  # zfill will pad a number with leadings zeroes to maintain all 5 characters
  string_num = str(number).zfill(5)
  
  while i != j:
    if string_num[i] != string_num[j]:
      return NO
    i += 1
    j -= 1

  return YES
