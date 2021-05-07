/*
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0034 - Declare and implement appropriate data types for program requirements.
  S0035 - Declare and/or implement of arrays and multi-dimensional arrays.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0052 - Implement a function that returns a single value.
  S0048 - Implement a function that receives input parameters.
  S0099 - Use pointer arithmetic to traverse an array.
  S0097 - Create and use pointers.
  S0081 - Implement a looping construct.
  S0108 - Utilize post and pre increment/decrement operators.
  S0082 - Implement conditional control flow constructs.
  S0160 - Utilize the standard library.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TestCode.h"



/*
In statistics, the mode of a set of values is the value that occurs most often or with the greatest frequency.
Write a function that accepts as arguments the following:
 - An array of integers
 - An integer that indicates the number of elements in the array

 The function should determine the mode of the array. That is, it should determine which value in the array occurs most often.
 If the array has no mode (none of the values occur more than once), the function should return -1
 (Assume the array will always contain nonnegative values).

 ***IMPORTANT*** In this function, use pointer notation instead of array notation

*/

int getMode(int *array, int size)
{
  int max_value = 0, max_count = 0, count = 0;

  for (int i = 0; i < size; i++)
  {
    count = 0;
    for (int j = 0; j < size; j++)
    {
      if (*(array + j) == *(array + i))
      {
        count++;
      }

      if (count > max_count)
      {
        max_count = count;
        max_value = *(array + i);
      }
    }
  }

  if (max_count == 1)
  {
    return -1;
  }
  return max_value;
}
