/*
This question is intended to evaluate the following topics:
    A0019 - Integrate functionality between multiple software components.
    A0018 - Analyze a problem to formulate a software solution.
    S0034 - Declare and implement appropriate data types for program requirements.
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
*/
#include <stdio.h>
#include <string.h>
#include "TestCode.h"


/*
Correct syntax in computer programming requires all opening container characters such as parenthesis '(', braces '{', brackets '[ have a closing
 matching container character ')','}', ']'. For valid syntax, when a closing character is encountered, it means a matching opening container
character exists. There cannot be any other opening container characters between the closing and opening one.

There must be also the same number of opening container character types as closing container character types.

The following is valid syntax example:

if (x == y) { scores[(x + 1)] = 50; }

The following is an invalid syntax example:

if (x == y) { scores[(x + 1]) = 50; }  // for the ] there is a previous ( before the matching [

The following is an invalid syntax example:

if (x == y) { scores[(x + 1)] = 50;   // there is no matching } for the opening {

Write a function called validateSyntax that receives a string of code and an empty char array. 
The function should use the passed char array to implement a rudimentary stack that 
keeps track of the opening/closing container characters. 

if the code string received is empty, the function should return ERROR_INVALID_DATA

If the code string received has valid syntax, the function should return ERROR_SUCCESS, 

if the code string received has invalid, the function should return ERROR_INVALID_BLOCK

*/


int validateSyntax(char * code, char stack[])
{
    int size = strlen(code);
    if (size < 1)
    {
        // ERROR_INVALID_DATA
        return 13;
    }

    // Index of element on top of stack
    int top = 0;
    // Number of items on stack
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        // Avoid negative indexing on stack
        if (top < 0)
        {
            top = 0;
        }
        switch (code[i])
        {
        // Open parenthesis
        case '(':
            stack[count] = '(';
            count++;
            top = count - 1;
            break;
        // Open curly brace
        case '{':
            stack[count] = '{';
            count++;
            top = count - 1;
            break;
        // Open square bracket
        case '[':
            stack[count] = '[';
            count++;
            top = count - 1;
            break;

        // Close paranthesis
        case ')':
            // Found matching parenthesis
            if (stack[top] == '(')
            {
                stack[top] == '\0';
                count--;
                top = count - 1;
            }
            break;
        // Close curly brace
        case '}':
            // Found matching curly brace
            if (stack[top] == '{')
            {
                stack[top] == '\0';
                count--;
                top = count - 1;
            }
            break;
        // Close square bracket
        case ']':
            // Found matching square bracket
            if (stack[top] == '[')
            {
                stack[top] == '\0';
                count--;
                top = count - 1;
            }
            break;

        default:
            break;
        }
    }

    if (count == 0)
    {
        // ERROR_SUCCESS
        return 0;
    }
    else
    {
        // ERROR_INVALID_BLOCK
        return 9;
    }
    return 0;
}
