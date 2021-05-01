/*
This question is intended to evaluate the following topics:
    A0019 - Integrate functionality between multiple software components.
    A0018 - Analyze a problem to formulate a software solution.
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
    S0082 - Implement conditional control flow constructs.
    S0158 - Create and use header files.
    S0159 - Type cast a variable to a different data type.
    S0160 - Utilize the standard library.
*/
/* Task #1

Write a header file called celsius.h with appropriate header guards that contains a function prototype called 
getCelsius. Create a source file called celsius.c with the implementation of the getCelsius function. The function 
should have a single integer as a parameter that represents a temperature in fahrenheit.  The function will convert 
the provided temperature to celsius and return it as a double.

The formula for conversions is:

(f - 32) * .5556    where f is the provided fahrenheit temp.

Task #2

Write the function processTemps that receives two parameters (your given code may or may not need updated):
    1. A two-dimensional array of integers
    2. An integer representing the number of rows in the array.

The function processes an array of temperatures for a given month. The array will consist of two columns representing 
the low temperature (index [0]) and high temperature (index [1]) for a given day. The number of rows will depend on the 
month and will have a valid range from 28 through 31. 

In this function:
    1. include your celsius.h file so it can be used to covert each temperature in the array to celsius
    2. Update the temps parameter to accommodate the number of columns.
    3. Change each value inside the array from fahrenheit to celsius. The value returned from your function must be 
       type cast to an int before updating the array.
    4. Find the lowest and highest celsius temperature recorded for the provide month.
    5. Return the difference between the highest and lowest temperature. For example, if the high for the month was 47 
       and the low 20, the function will return 27.

If any row value is less than 28 or greater than 31, the function should do no processing and return -1.

If any low temperature for a given day is higher than the high temperature for that same day, the function should do no 
further processing and return -1. 
*/

#include <stdio.h>
#include <limits.h>
#include "celsius.h"

int processTemps(int temps[][2], int rows)
{
    // Check if number of rows is valid
    if (rows < 28 || rows > 31)
    {
        return -1;
    }
    int lowest = INT_MAX, highest = INT_MIN;
    int low = 0, high = 0;
    for (int i = 0; i < rows; i++)
    {
        low = (int)getCelsius(temps[i][0]);
        high = (int)getCelsius(temps[i][1]);

        // Check if the low temp is greater than the high temp
        if (low > high)
        {
            return -1;
        }

        // Low temp index 0
        temps[i][0] = low;
        // High temp index 1
        temps[i][1] = high;

        // Check if the low is lower than current
        if (low < lowest)
        {
            lowest = low;
        }
        // Check if the high is greater than current
        if (high > highest)
        {
            highest = high;
        }
    }
    return highest - lowest;
}
