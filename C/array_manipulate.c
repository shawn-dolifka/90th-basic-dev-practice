/*
This question is intended to evaluate the following topics:
    A0087 - Create and implement a sort routine.
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
    S0099 - Use pointer arithmetic to traverse an array.
    S0097 - Create and use pointers.
    S0081 - Implement a looping construct.
    S0108 - Utilize post and pre increment/decrement operators.
    S0082 - Implement conditional control flow constructs.
*/
#include <stdio.h>
#include <stdlib.h>
#include "TestCode.h"

/*


Write the function arrayManipulate that receives two parameters:
arr - a pointer to an array of integer 
size - an int indicating the size of the array

The function must iterate over the array using an integer pointer and pointer 
arithmetic (required) to access each element of the array and to possibly change 
the contents of the array. The contents will be changed according to the following:

If the value in the element is an even number and greater than six (6), then 
square the contents of the element.  For example, if the element originally contained 
a 12, it will now contain 144.

Otherwise, if the value in the element is an odd number or it is greater than two (2), 
then double the contents in the element. For example if the element originally 
contained a 5, it will now contain 10.

Once the array has been updated and fully iterated, sort the array in ascending order 
using any sorting algorithm.

Lastly, after sorting: 
    if the array has an even number of elements, the function should return the sum 
    of the middle two elements.  For example, if the array has eight (8) elements, 
    return the sum of the contents of element three(3) and four(4). 
    
    If the array has an odd number of elements, return the contents of just the middle element.

If the size passed to the function is less than 2, the function should return a -1.

*/

int compare (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int arrayManipulate(int *arr, int size)
{
    if (size < 2)
    {
        return -1;
    }

    for (int i = 0; i < size; i++)
    {
        int number = *(arr + i);
        if (number % 2 == 0 && number > 6)
        {
            *(arr + i) = number * number;
            continue;
        }
        if (number > 2 || number % 2 != 0)
        {
            *(arr + i) = number * 2;
        }   
    }
    qsort(arr, size, sizeof(int), compare);
    if (size % 2 == 0)
    {
        int mid1 = *(arr + (size/2) );
        int mid2 = *(arr + ((size/2) - 1) );
        return mid1 + mid2;
    }
    else
    {
        int result = *(arr + (size/2));
        return result;
    }
}
