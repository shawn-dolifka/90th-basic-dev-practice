"""
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0030 - Utilize bitwise operators to manipulate binary values.
  S0023 - Declare and implement data types.
  S0029 - Utilize arithmetic operators (PEMDAS +, -, *, /, %) in mathematical equations.
  S0031 - Utilize logical operators to formulate boolean expressions.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0082 - Implement conditional control flow constructs."""
'''

Write the function convertAndShift that receives a 16-character string in the form of a binary number
consisting of 1's and 0's. The function will convert the binary string to a integer value. For example,
if the string received is '0000000010101010', this value would be converted to the integer 170.

After conversion, if the integer value is an even number, use the << Binary Left Shift operator to shift
the value's bits two (2).  Otherwise, use the >> Binary Right Shift operator to shift the value's bits one (1).

If the resulting value of either of the shifts is > 200, apply the ~ Binary Ones Complement to the value.

When complete, the function will return the value.

If the provided string is not exactly 16 characters long, the function will return the string "INVALID_LENGTH"

Subsequently, if any of the characters in the provided string is not a 1 or 0, the function will return the 
string "INVALID_VALUE"

'''


def convertAndShift(bStr):
  # Check if length is exactly 16
  length = len(bStr)
  if length != 16:
    return "INVALID_LENGTH"

  for i in range(length):
    if (bStr[i] != '0') and (bStr[i] != '1'):
      return "INVALID_VALUE"

  binary_number = int(bStr,2)
  
  if binary_number % 2 == 0:
    binary_number <<= 2
  else:
    binary_number >>= 1

  if binary_number > 200:
    return ~binary_number

  return binary_number
