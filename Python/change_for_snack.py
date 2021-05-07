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
  S0047 - Implement a function that returns multiple values.
  S0048 - Implement a function that receives input parameters.
  S0082 - Implement conditional control flow constructs."""
'''
Write the function computeChange that receives a dictionary with the following possible keys:

'H' - half dollar
'Q' - quarter
'D' - dime
'N' - nickel
'P' - penny

Each key will have an associated integer value representing a quantity. The dictionary will represent a gathering
of change (coins). Your function will compute the total amount of change and determine whether or not there is
enough money to purchase items at a fast-food restaurant. If you have $2.50 or more you can buy BOTH fries
and a soda.  If you have at least $1.50 but less than $2.50 can buy FRIES. If you have at least $1.00 but less than $1.50
you can get a SODA. If you have less than $1.00 you get NOTHING.

For example, you may receive a dictionary such as {'Q':3, 'D':7, 'P':14} which would compute to $1.59. (3 quarters,
7 dimes, 14 pennies)

If any quantity in the dictionary is less than zero, the function will return a single value of zero (0), otherwise
the function should return two values: 
                                       1. Total money in the form of a Float (dollar representation with two decimal places)  
                           e.g. 1.59
                                       2. A string representing what could be purchased (if anything). Use
                                       one of the following strings:
                                            'NOTHING'
                                            'SODA'
                                            'FRIES'
                                            'BOTH'

return the total money as the first value, followed by the string representing the purchase as the second value


'''
HALF_DOLLAR = 0.50
QUARTER = 0.25
DIME = 0.10
NICKEL = 0.05
PENNY = 0.01
BOTH = 2.50
FRIES = 1.50
SODA = 1.00


def computeChange(change):
  cash = 0
  can_purchase = ""
  for coin in change:
    # Coin count negative
    if change[coin] < 0:
      return 0

    if coin == 'H':
      cash += HALF_DOLLAR * change[coin]

    elif coin == 'Q':
      cash += QUARTER * change[coin]

    elif coin == 'D':
      cash += DIME * change[coin]
    
    elif coin == 'N':
      cash += NICKEL * change[coin]

    elif coin == 'P':
      cash += PENNY * change[coin]

  if cash >= BOTH:
    can_purchase = "BOTH"
  elif cash >= FRIES:
    can_purchase = "FRIES"
  elif cash >= SODA:
    can_purchase = "SODA"
  else:
    can_purchase = "NOTHING"

  return round(cash, 2), can_purchase
