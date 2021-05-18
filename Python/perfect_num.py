"""
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0024 - Declare and/or implement container data type.
  S0023 - Declare and implement data types.
  S0029 - Utilize arithmetic operators (PEMDAS +, -, *, /, %) in mathematical equations.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0052 - Implement a function that returns a single value.
  S0048 - Implement a function that receives input parameters.
  S0081 - Implement a looping construct.
  S0082 - Implement conditional control flow constructs."""
"""
An integer number is said to be a perfect number if the sum of its factors, including 1 (but
not the number itself), is equal to the number.

For example, 6 is a perfect number, because 6 = 1 + 2 + 3.

Do the following:
 1- Write a function perfect(number) that determines whether a parameter number is a perfect number.
    1.1- The function perfect(number) returns True if a number is perfect, False if not

 2- Use the function perfect in a another function getPerfectNumbers() that determines and returns all the perfect numbers between 1 and 1000. The perfect 
    numbers should stored and returned in a set collection
 

"""

def perfect(number):
   sum = 0
   for i in range(1, number):
      if number % i == 0:
         sum += i
   if sum == number:
      return True
   else:
      return False

def getPerfectNumbers():
   perfects = []
   for i in range(1,1001):
      if perfect(i):
         perfects.append(i)
   return set(perfects)
