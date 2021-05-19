/*
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0029 - Utilize arithmetic operators (PEMDAS +, -, *, /, %) in mathematical equations.
  S0034 - Declare and implement appropriate data types for program requirements.
  S0031 - Utilize logical operators to formulate boolean expressions.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0036 - Declare and implement a char * array (string).
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0052 - Implement a function that returns a single value.
  S0048 - Implement a function that receives input parameters.
  S0079 - Validate expected input.
  S0097 - Create and use pointers.
  S0081 - Implement a looping construct.
  S0108 - Utilize post and pre increment/decrement operators.
  S0082 - Implement conditional control flow constructs.
  S0160 - Utilize the standard library.*/
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

/* Write the function extractAndAddNumbers that receives a string of text as a parameter. The
string of text contains one or more series of digits embedded within it. The function will
locate each series of digits, convert each series of digits to a number, and add all the numbers
together and return the total value.

For example, as string may contain:  abc1307sfaskfsjadfja34kdsfljakfslkjflksjf902

The function will return the integer: 2243 for this example

if the string is empty or there are no digits in the string, the function should return 0
*/

#define ASCII_ZERO '0'

int extractAndAddNumbers(char *text)
{
  if (text == NULL)
  {
    return 0;
  }

  if (text[0] == '\0')
  {
    return 0;
  }

  int size = strlen(text);
  int total = 0;

  for (int i = (size - 1); i > -1; i--)
  {
    if (isdigit(text[i]))
    {
      int place_value = 0;
      while (isdigit(text[i]))
      {
        total += (text[i] - ASCII_ZERO) * (int)pow(10, place_value);
        place_value++;
        i--;
      }
      
    }
  }

  return total;
}
