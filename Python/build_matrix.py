"""
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
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
  S0081 - Implement a looping construct.
  S0082 - Implement conditional control flow constructs."""
'''
Write the function buildMatrix that receives two integer values representing two dimensions of an array. (rows and columns) The
function will create a two-dimensional array of the provided sizes and populate each element of the array
with the product of each elements indices. For example if you were passed a 2 and a 3, the function will create a 2 X 3
Two-dimensional array.  The element [0][0] will contain the digit 0, the element [0][1] will contain the digit 0, the element [1][2] will contain the digit 2 etc. 

[0, 0, 0, 0, 0, 0]
[0, 1, 2, 3, 4, 5]
[0, 2, 4, 6, 8, 10]
[0, 3, 6, 9, 12, 15]
[0, 4, 8, 12, 16, 20]
[0, 5, 10, 15, 20, 25]

For any perfectly square two-dimensional array that has an odd number of rows, set the center element to 1.  For example, a two-dimensional 5 X 5
array will have element [2][2] set to 1.

[0, 0, 0, 0, 0]
[0, 1, 2, 3, 4]
[0, 2, 1, 6, 8]
[0, 3, 6, 9, 12]
[0, 4, 8, 12, 16]

The function will return the two-dimensional array once it's built and populated.

If either row, or column is one or less, return an empty list.

'''

def buildMatrix(rows, cols):
  if rows < 2 or cols < 2:
    return []
  
  # Declare 2D array with for loop or the lists won't be independent from each other.
  matrix = [ [0] * cols for x in range(rows)]
  i = j = 0

  while i < rows:
    while j < cols:
      matrix[i][j] = i * j
      j += 1
    i += 1
    j = 0

  if rows % 2 != 0 and rows == cols:
    matrix[rows // 2][cols // 2] = 1
  
  return matrix
