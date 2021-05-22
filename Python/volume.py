"""
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0026 - Utilize standard library modules.
  S0024 - Declare and/or implement container data type.
  S0023 - Declare and implement data types.
  S0029 - Utilize arithmetic operators (PEMDAS +, -, *, /, %) in mathematical equations.
  S0031 - Utilize logical operators to formulate boolean expressions.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0052 - Implement a function that returns a single value.
  S0048 - Implement a function that receives input parameters.
  S0079 - Validate expected input.
  S0082 - Implement conditional control flow constructs."""
'''
The computeVolume function will compute the volume of two different 3-dimensional items
and return the total volume of those items. The 3-dimensional items are a cuboid and a sphere.

The function will receive two parameters and these parameters could be passed in any order so
this needs to be accounted for.

1. an integer > 0 - represents a radius of a sphere
2. a three item list of whole number each > 0 containing a length, width, and height - represents a cuboid.

The formula for a sphere is 4/3 * PI * radius^3
The formula for a cuboid is length * width * height

Ensure you utilize the proper python modules for PI.

After computing the volume of the sphere, round the result to a whole number.

If any of the parameters are invalid, the function should return the string "INVALID".
  - make sure that one parameter is an integer and the other a list
  - make sure the list is exactly 3 in length
  - make sure all whole number are > 0
  
Assume all values in the list are whole numbers - you do not need to verify they are whole numbers

'''

import math
FOUR_THIRD = (4/3)
PI = math.pi

def computeVolume(item1, item2):
  # Check if both are a list
  if isinstance(item1, list) and isinstance(item2, list):
    return "INVALID"
  
  # Check if both are an int
  if isinstance(item1, int) and isinstance(item2, int):
    return "INVALID"
  
  radius = None
  cuboid_dim = None

  # Check if item 1 is valid Cuboid dimensions
  if isinstance(item1, list) and len(item1) == 3:
    cuboid_dim = item1
    radius = item2
  # Check if item 2 is valid Cuboid dimensions
  elif isinstance(item2, list) and len(item2) == 3:
    cuboid_dim = item2
    radius = item1
  else:
    return "INVALID"

  # Check if radius is greater than 0
  if radius < 1:
    return "INVALID"

  # Check if all cuboid dimensions are greater than 0
  for num in cuboid_dim:
    if num < 1:
      return "INVALID"
  
  volume = ( FOUR_THIRD * PI * math.pow(radius,3) ) \
    + (cuboid_dim[0] * cuboid_dim[1] * cuboid_dim[2])
  return round(volume)
