/*
This question is intended to evaluate the following topics:
    A0019 - Integrate functionality between multiple software components.
    A0018 - Analyze a problem to formulate a software solution.
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
    S0160 - Utilize the standard library.
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "TestCode.h"

/*
  For this task, you will receive two pointers to NULL terminated strings: 
           a 'sentence', and a 'word'. The objective will be to delete (in place) the first 
           occurrence of 'word' in the sentence. 

 Expected Return Values:
        - the task is successful: should return ERROR_SUCCESS (0).
        - provided parameters are bad: should return ERROR_INVALID_PARAMETER (87)
        - the provided 'word' is not part of 'sentence': should return ERROR_NOT_FOUND (1168)
*/

int deleteWord(const char* sentence, const char* word)
{
    if (word == NULL)
    {
        return 87;
    }

    if (strstr(sentence, word) == NULL)
    {
        return 1168;
    }

    char *i, *j, *k;
    if ((j = k = strstr(sentence, word)) != NULL)
    {
        size_t length = strlen(word);
        while ( (k = strstr(i = k + length, word) ) != NULL)
        {
            while(i < k)
            {
                *j++ = *i++;
            }
        }
        while ((*j++ = *i++) != '\0'){continue;}
        return 0;
    }
}



