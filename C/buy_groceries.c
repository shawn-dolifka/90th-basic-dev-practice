/*
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0029 - Utilize arithmetic operators (PEMDAS +, -, *, /, %) in mathematical equations.
  S0034 - Declare and implement appropriate data types for program requirements.
  S0031 - Utilize logical operators to formulate boolean expressions.
  S0035 - Declare and/or implement of arrays and multi-dimensional arrays.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0052 - Implement a function that returns a single value.
  S0048 - Implement a function that receives input parameters.
  S0079 - Validate expected input.
  S0081 - Implement a looping construct.
  S0108 - Utilize post and pre increment/decrement operators.
  S0082 - Implement conditional control flow constructs.*/
/* Write a function buyGroceries that accepts and int array and an int representing the size
of the array. Every two (2) indices in the array represents an item number and quantity to purchase groceries.
The function will iterate the array and determine the total cost of groceries as a floating point number
based on the item number, quantity of each item, and cost of each item. There are four valid items.

item #  item   Cost
1       eggs   3.50
2       milk   2.25
3       bread  1.99
4       sugar  4.15

For example, the function may receive an array with the following:   1 5 2 3 4 4

resulting in 5 eggs at $3.50, 3 milks at $2.25 each, and 4 sugars at $4.15 each.

Compute a grand total based on quantity and cost of each item. If there is a quantity
of 5 or more for an item, a 5% discount is applied on those items. So, for the above
example there would be a 5% discount applied to the eggs.

Once the total is computed, round the value to an integer and return it.

The size passed for the array should always be an even number > 0, if it is not, the function
should return 0.

If any item number is not a 1, 2, 3, or 4, the function should return 0.

If any quantity is 0 or less, the function should return 0.

If a valid size is passed (even number) assume array is of that size.

Assume there will be no duplicate entries for an item number.

*/



#include <stdio.h>
#include <math.h>


int buyGroceries(int stuff[], int size)
{
  // Is size greater than 0?
  if (size < 1)
  {
    return 0;
  }

  // Is the size an even number?
  if (size % 2 != 0)
  {
    return 0;
  }

  // Check if any item number isn't 1-4
  for (int i = 0; i < size; i += 2)
  {
    if (stuff[i] < 1 || stuff[i] > 4){return 0;}
  }

  // Check if any quantity is 0 or less
  for (int i = 1; i < size; i += 2)
  {
    if (stuff[i] < 1){return 0;}
  }

  double eggs_p = 0, 
  milk_p = 0, 
  bread_p = 0, 
  sugar_p = 0;

  const double EGG_PRICE = 3.50, 
  MILK_PRICE = 2.25, 
  BREAD_PRICE = 1.99,
  SUGAR_PRICE = 4.15,
  DISCOUNT = 0.95;

  // Get a count of all items in cart
  for (int i = 0; i < size; i += 2)
  {
    switch (stuff[i])
    {
      // Eggs
      case 1:
        if (stuff[i+1] >= 5)
        {
          eggs_p = EGG_PRICE * stuff[i+1] * DISCOUNT;
        }
        else
        {
          eggs_p = EGG_PRICE * stuff[i+1];
        }
        break;

      // Milk
      case 2:
        if (stuff[i+1] >= 5)
        {
          milk_p = MILK_PRICE * stuff[i+1] * DISCOUNT;
        }
        else
        {
          milk_p = MILK_PRICE * stuff[i+1];
        }
        break;

      // Bread
      case 3:
        if (stuff[i+1] >= 5)
        {
          bread_p = BREAD_PRICE * stuff[i+1] * DISCOUNT;
        }
        else
        {
          bread_p = BREAD_PRICE * stuff[i+1];
        }
        break;

      // Sugar
      case 4:
        if (stuff[i+1] >= 5)
        {
          sugar_p = SUGAR_PRICE * stuff[i+1] * DISCOUNT;
        }
        else
        {
          sugar_p = SUGAR_PRICE * stuff[i+1];
        }
        break;

      // No match, something is wrong
      default:
        return 0;
    }
  }

  double total = round(eggs_p + milk_p + bread_p + sugar_p);
  return (int)total;
}
