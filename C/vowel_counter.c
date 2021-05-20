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
    S0079 - Validate expected input.
    S0097 - Create and use pointers.
    S0081 - Implement a looping construct.
    S0108 - Utilize post and pre increment/decrement operators.
    S0082 - Implement conditional control flow constructs.
    S0156 - Utilize a struct composite data type.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "TestCode.h"


/*
Vowels in the English language consist of a, e, i, o, u and sometimes y. For this exercise, y 
is considered a vowel if it doesn’t start a word such as yes and yellow.  If a y is anywhere 
else in a word it is considered a vowel such as try, or cyst.

Write a function countVowels that accepts a character pointer to an array representing a 
sentence, and a struct pointer (struct defined in TestCode.h header file). The function should compute 
the total number of vowels in the sentence and return it. The function will also count the 
number of individual vowels in the sentence and increment the associated counter in the struct.  

aCount for 'a' or ‘A’ etc.

- If sentence is empty or NULL, return ERROR_EMPTY.
*/



int countVowels(const char *text, struct Vowels* v)
{
    if (text == NULL)
    {
        return ERROR_EMPTY;
    }
    if (text[0] == '\0')
    {
        return ERROR_EMPTY;
    }

    int size = strlen(text);
    const char *prev = text;

    for (int i = 1; i < size; i++)
    {
        char letter = text[i];
        if (letter == 'y' && *prev != ' ')
        {
            v->yCount++;
            prev++;
        }
        else if (letter == 'a' || letter == 'A')
        {
            v->aCount++;
            prev++;
        }
        else if (letter == 'e' || letter == 'E')
        {
            v->eCount++;
            prev++;
        }
        else if (letter == 'i' || letter == 'I')
        {
            v->iCount++;
            prev++;
        }
        else if (letter == 'o' || letter == 'O')
        {
            v->oCount++;
            prev++;
        }
        else if (letter == 'u' || letter == 'U')
        {
            v->uCount++;
            prev++;
        }
        else
        {
            prev++;
        }
    }

    int vowel_count = v->aCount + v->eCount + v->iCount + v->oCount + v->uCount + v->yCount;
    return vowel_count;
}
