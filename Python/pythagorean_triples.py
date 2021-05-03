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
  S0081 - Implement a looping construct.
  S0082 - Implement conditional control flow constructs."""
"""
Pythagorean Triples: A right triangle can have sides that are all integers. The set of three
integer values for the sides of a right triangle is called a Pythagorean triple. These three sides must
satisfy the relationship that the sum of the squares of two of the sides is equal to the square of the
hypotenuse. Write a function find_pythagorean_triples() to find all Pythagorean triples for side1, side2 and hypotenuse all no larger than 20.

Return a list of tuples, formatted as (hypotenuse, side1, side2), that contains the length of each side. This list does not need to be sorted.
"""
import math

def find_pythagorean_triples():
    triples = []
    for b in range(1, 20):
      for a in range(1, 20):
        c = math.sqrt(a*a + b*b)
        if c % 1 == 0:
          triples.append( (int(c), int(a), int(b)) )
    return triples
