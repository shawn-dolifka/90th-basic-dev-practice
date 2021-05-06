/*
This question is intended to evaluate the following topics:
  A0087 - Create and implement a sort routine.
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0029 - Utilize arithmetic operators (PEMDAS +, -, *, /, %) in mathematical equations.
  S0034 - Declare and implement appropriate data types for program requirements.
  S0035 - Declare and/or implement of arrays and multi-dimensional arrays.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0052 - Implement a function that returns a single value.
  S0048 - Implement a function that receives input parameters.
  S0097 - Create and use pointers.
  S0081 - Implement a looping construct.
  S0108 - Utilize post and pre increment/decrement operators.
  S0082 - Implement conditional control flow constructs.
  S0098 - Implement a function pointer to call another function.*/
#include <stdio.h>


/*


** NOTE: THE SOLUTION FOR THIS PROBLEM IS BASED ON A SPECIFICALLY DEFINED ALGORITHM EXPLAINED BELOW. ALTHOUGH THE AUTOMATED TESTS
** MAY BE SUCCESSFUL, YOUR SOLUTION WILL RECEIVE A MANUAL REVIEW FOR FINAL DETERMINATION OF PASS/FAIL

Bubble Sort
--------------
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.

Example:
First Pass:
( 5 1 4 2 8 ) -> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
( 1 5 4 2 8 ) ->  ( 1 4 5 2 8 ), Swap since 5 > 4
( 1 4 5 2 8 ) ->  ( 1 4 2 5 8 ), Swap since 5 > 2
( 1 4 2 5 8 ) -> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.

Second Pass:
( 1 4 2 5 8 ) -> ( 1 4 2 5 8 )
( 1 4 2 5 8 ) -> ( 1 2 4 5 8 ), Swap since 4 > 2
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) ->  ( 1 2 4 5 8 )

Third Pass:
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )

Fourth Pass:
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) -> ( 1 2 4 5 8 )
*/



/*
The function bubbleSort receives a pointer to a function�either function ascending or function descending�as an argument, in addition to an integer array and the size of the array.
The parameter compare is a pointer to the comparison function that determines sorting order.
The function returns an integer pointer to the sorted array.
*/

typedef enum {FALSE = 0, TRUE} boolean;
typedef int(*compare)(int a, int b);

int* bubbleSort(int elements[], size_t length, compare function)
{
  int temp = 0;
  // Track if a swap occurs
  int swapped = FALSE;
  for (int i = 0; i < (length-1); i++)
  {
    for (int j = 0; j < (length - i - 1); j++)
    {
      if ( function(elements[j],elements[j+1]) )
      {
        temp = elements[j];
        elements[j] = elements[j+1];
        elements[j+1] = temp;
        swapped = TRUE;
      }
    }
    // If no numbers were swapped, the array is already sorted
    if (!swapped)
    {
      break;
    }
  }
  return elements;
}


// @brief Determine whether elements are out of order for an ascending order sort
// @return Boolean indicating whether the two elements should be swapped
int ascending(int a, int b)
{
  if (a > b)
  {
    return TRUE;
  }
  return FALSE;         
}

// @brief Determine whether elements are out of order for a descending order sort
// @return Boolean indicating whether the two elements should be swapped
int descending(int a, int b)
{
  if (a < b)
  {
    return TRUE;
  }
  return FALSE;      
}
