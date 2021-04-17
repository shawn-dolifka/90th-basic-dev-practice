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
    S0050 - Implement a function that doesn't return a value.
    S0048 - Implement a function that receives input parameters.
    S0099 - Use pointer arithmetic to traverse an array.
    S0097 - Create and use pointers.
    S0081 - Implement a looping construct.
    S0108 - Utilize post and pre increment/decrement operators.
    S0082 - Implement conditional control flow constructs.
*/
#include <stdio.h>
#include "TestCode.h"


/*
Write TWO functions Copy1 and Copy2. Both functions copy a string into a character array.
Function Copy1 uses ***array index notation*** to copy the string in s2 to the character array s1.
Function Copy2 uses ***pointers and pointer arithmetic*** to copy the string in s2 to the character array s1

Each function will take only two parameters: destination string and source string

Declare your functions to enforce the ***principle of least privilege***.
It means that neither function requires the capability of modifying the string in the second argument.

*/



// copy s2 to s1 using array notation
void copy1(char * const dest, const char * const src)
{
    int length = 0;
    int i = 0;
    while (src[i] != '\0')
    {
        length++;
        i++;
    }
    // Add 1 for null terminator
    length++;

    for (int i = 0; i < length; i++)
    {
        dest[i] = src[i];
    }
    
}

// copy s2 to s1 using pointer notation
void copy2(char *dest, const char *src)
{
    int length = 0;
    int i = 0;
    while (*(src + i) != '\0')
    {
        length++;
        i++;
    }
    // Add 1 for null terminator
    length++;

    for (int i = 0; i < length; i++)
    {
        *(dest + i) = *(src + i);
    }
}
