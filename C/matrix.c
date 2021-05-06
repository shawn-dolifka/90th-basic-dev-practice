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
  S0081 - Implement a looping construct.
  S0108 - Utilize post and pre increment/decrement operators.
  S0082 - Implement conditional control flow constructs.*/
#include <stdio.h>
#include <string.h>
#include "TestCode.h"


/*
Write the processMatrix function that receives a two-dimensional array. The size of the array
will be such that the there are always 5 columns but the number of rows may vary and this
value is also provided to the function.

This function needs to iterate through the entire array and do the following:

1. if both indices of the array are even numbers [0][0], [2][2] etc, then the value stored
at that index should be multiplied by two and stored back into that index

2. if both indices of the array are odd numbers [1][1], [3][3] etc, then the value stored
at that index should be divided by two and stored back into that index (take note this is integer division)

3. All other elements should be unchanged.

4. All values in the array should be added together after the updates are made and the function should
return the total.

*/

#define COLS 5

int processMatrix(int matrix[][COLS], int rows)
{
  int total = 0;

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      // Both indexes are even numbers
      if ( (i % 2 == 0) && (j % 2 == 0) )
      {
        matrix[i][j] *= 2;
      }
      // Both indexes are odd
      else if ( (i % 2 != 0) && (j % 2 != 0) )
      {
        matrix[i][j] /= 2;
      }
      else{continue;}
    }
  }

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      total += matrix[i][j];
    }
  }

  return total;
}
