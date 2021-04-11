/*
This question is intended to evaluate the following topics:
    A0019 - Integrate functionality between multiple software components.
    A0018 - Analyze a problem to formulate a software solution.
    S0030 - Utilize bitwise operators to manipulate binary values.
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
    S0081 - Implement a looping construct.
    S0108 - Utilize post and pre increment/decrement operators.
    S0082 - Implement conditional control flow constructs.
    S0160 - Utilize the standard library.
*/
/*
Write the function bitwiseOps that receives two char * strings representing a binary number.
All characters in the string should be either a '1' or '0'. Each string should be exactly
16 characters long.
The function will convert each binary representation to its equivalent decimal(base 10) by
creating int variables and storing the values of the conversions to those variables. 
So, for example, if the string passed is '0000000000001111', this will be converted to 15 and
saved in a variable.

After conversion, do the following:
   1. if both values are even numbers, use the bitwise & operator to and the values
      together and return the results.
   2. if both values are odd numbers, use the bitwise | operator to or the values
      together and return the results.
   3. otherwise, if both values are  > 255 then use the bitwise ^ operator to xor the
      values together and return the results.
   4. if none of the above apply, add the two values together and return the results.

If either of the provided strings is less or greater than 16 characters, the function will
return a -1.

If any of the characters in the string is other than a '1' or '0', the function will return
a -2.

*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include "TestCode.h"

// atoi() isn't working in practice container
int convert(char digit)
{
    // Digit is 1
    if ((int)digit == (int)'1')
    {
        return (int)digit - 48;
    }
    // Digit is 0
    else if ((int)digit == (int)'0')
    {
        return (int)digit - (int)digit;
    }
    // Digit is not 0 or 1
    else
    {
        return -1;
    }
}

int bitwiseOps(const char *first, char* second)
{
    int LENGTH_1 = strlen(first), LENGTH_2 = strlen(second);

    // Check that both strings are 16 in length
    if (LENGTH_1 != 16 || LENGTH_2 != 16)
    {
        return -1;
    }

    // atoi() isn't working, so cast char as int for comparison
    // (int)'1' = 49 and (int)'0' = 48
    //int one = (int)'1', zero = (int)'0';

    // Check that strings only contain 0 or 1
    for (int i = 0; i < LENGTH_1; i++)
    {
        // Get int value of the char 0 and char 1 in numbers
        int first_digit = convert(first[i]), 
        second_digit = convert(second[i]);
        
        if ((first_digit > 1 || first_digit < 0) ||
            (second_digit > 1 || second_digit < 0))
            {
                return -2;
            }
    }

    int first_num = 0, second_num = 0, digit = 0;

    for (int i = (LENGTH_1-1); i > 0; i--)
    {
        first_num += convert(first[i]) * pow(2, digit);
        second_num += convert(second[i]) * pow(2, digit);
        digit++;
    }

    // Both values are even
    if (first_num % 2 == 0 && second_num % 2 == 0)
    {
        return first_num & second_num;
    }

    // Both values are odd
    if (first_num % 2 != 0 && second_num % 2 != 0)
    {
        return first_num | second_num;
    }

    // Both values are > 255
    if (first_num > 255 && second_num > 255)
    {
        return first_num ^ second_num;
    }

    return first_num + second_num;
}


