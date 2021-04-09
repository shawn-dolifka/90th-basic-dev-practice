"""
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0382 - Create a class constructor or destructor
  S0023 - Declare and implement data types.
  S0029 - Utilize arithmetic operators (PEMDAS +, -, *, /, %) in mathematical equations.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0048 - Implement a function that receives input parameters.
  S0081 - Implement a looping construct.
  S0110 - Implement error handling.
  S0082 - Implement conditional control flow constructs."""
"""
Create a class called RationalNumber for performing arithmetic with fractions.

Use integer variables to represent the data of the class: the numerator and the denominator.
Provide a constructor that enables an object of this class to be initialized when it is declared. The
constructor should contain default values (i.e., 0/1) in case no initializers are provided, and should store the
fraction in reduced form (i.e., the fraction 2/4 would be stored in the object as 1/2)

Provide the following methods in RationalNumber:
    add -              adds two RationalNumbers. The result should be stored in reduced form.
    subtract -         subtracts two RationalNumbers. The result should be stored in reduced form.
    multiply -        multiplies two RationalNumbers. The result should be stored in reduced form.
    divide -           divides two RationalNumbers. The result should be stored in reduced form.
    printFraction -    returns RationalNumbers as a string in the form a/b, where a is the numerator and b is the denominator, ex. "1/2" or "11/25".
    printDecimal -     returns RationalNumbers in floating-point format rounded to 2 decimal numbers, ex 1.00 or 2.51.

Do not use a module instead of implementing the above features.
"""


class RationalNumber:
  def __init__(self, numerator = 0, denominator = 1):
    gcd = self.reduce(numerator,denominator)
    self.numerator = int(numerator / gcd)
    self.denominator = int(denominator / gcd)

  def make_self(self, numerator = 0, denominator = 1):
    return RationalNumber(numerator, denominator)
  
  def reduce(self,a,b):
    while b:
      a,b = b, a % b
    return a

  # Perform addition
  def add(self, RationalNumber):

    return_sum = self.make_self()

    if self.denominator != RationalNumber.denominator:

      # Get a common denominator
      multiple = self.denominator * RationalNumber.denominator
      # Add both numerators together
      new_numerator = (self.numerator * RationalNumber.denominator) + (RationalNumber.numerator * self.denominator)

      # Find the Greatest Common Denominator
      gcd = self.reduce(multiple,new_numerator)

      # Reduce the numerator and denominator by GDC
      return_sum.denominator = int(multiple / gcd)
      return_sum.numerator = int(new_numerator / gcd)
    else:
      new_numerator = self.numerator + RationalNumber.numerator
      new_denominator = self.denominator
      gcd = self.reduce(new_denominator,new_numerator)
      return_sum.numerator = int(new_numerator / gcd)
      return_sum.denominator = int(new_denominator / gcd)
    return return_sum

  # Perform subtraction
  def subtract(self, RationalNumber):

    return_sub = self.make_self()

    if self.denominator != RationalNumber.denominator:
      multiple = self.denominator * RationalNumber.denominator
      new_numerator = (self.numerator * RationalNumber.denominator) - (RationalNumber.numerator * self.denominator)
      gcd = self.reduce(multiple, new_numerator)
      return_sub.denominator = int(multiple / gcd)
      return_sub.numerator = int(new_numerator / gcd)
    else:
      new_numerator = self.numerator - RationalNumber.numerator
      new_denominator = self.denominator
      gcd = self.reduce(new_denominator,new_numerator)
      return_sub.numerator = int(new_numerator / gcd)
      return_sub.denominator = int(new_denominator /gcd)
    return return_sub

  # Perform multiplication
  def multiply(self, RationalNumber):
    return_multi = self.make_self()
    new_numerator = self.numerator * RationalNumber.numerator
    new_denominator = self.denominator * RationalNumber.denominator
    gcd = self.reduce(new_numerator,new_denominator)
    return_multi.numerator = int(new_numerator / gcd)
    return_multi.denominator = int(new_denominator / gcd)
    return return_multi

  # Perform division
  def divide(self, RationalNumber):
    return_div = self.make_self()
    new_numerator = self.numerator * RationalNumber.denominator
    new_denominator = self.denominator * RationalNumber.numerator
    gcd = self.reduce(new_numerator,new_denominator)
    return_div.numerator = int(new_numerator / gcd)
    return_div.denominator = int(new_denominator / gcd)
    return return_div

  # Print as fraction
  def printFraction(self):
    #print(str(self.numerator) + "/" + str(self.denominator))
    return str(self.numerator) + "/" + str(self.denominator)

  # Print as decimal
  def printDecimal(self):
    return float(format(self.numerator/self.denominator, '.2f'))
