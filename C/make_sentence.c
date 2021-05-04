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
    S0053 - Implement a function that returns a memory reference.
    S0048 - Implement a function that receives input parameters.
    S0090 - Allocate memory on the heap (malloc).
    S0097 - Create and use pointers.
    S0081 - Implement a looping construct.
    S0108 - Utilize post and pre increment/decrement operators.
    S0082 - Implement conditional control flow constructs.
    S0160 - Utilize the standard library.
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/*
Write a function makeSentence that receives a char * array of characters that 
contain no spaces. Each capital letter in the string of characters represents a 
start of a word. The function should parse the string and create and return a 
new char * with spaces in between each word with only the first word capitalized. 
When complete, this will represent a sentence and should therefore end with a 
period unless the first word of the sentence begins with the word Who, What, 
Where, When, Why, or How. In this case, the sentence should end with a question 
mark.

For example:

ILikeCheese   should result in:  I like cheese.
WhereAreYou   should result in:  Where are you?
  
Assume that the provided string contains no spaces.

*/



char* makeSentence(char * str)
{
    const char WHO[4] = "Who", 
               WHAT[5] = "What", 
               WHERE[6] = "Where",
               WHEN[5] = "When", 
               HOW[4] = "How", 
               WHY[4] = "Why";
    
    int length = strlen(str);

    // How many extra blocks to add when allocating memory.
    // Always 1 extra for punctuation marks at end.
    int add_memory = 1;
    for (int i = 0; i < length; i++)
    {
        char letter = str[i];
        if (isupper(letter))
        {
            add_memory++;
        }
    }

    char * newSentence = (char*)calloc(length + add_memory, sizeof(char));
    // strCpy memory allocated
    char * strCpy = strdup(str);
    
    // Keep a count of characters for pointer arithmetic in loop
    int count = 1;

    // Keep track of how far the strCpy pointer has moved
    int mem_count = 0;

    // Don't start at index 0. It's always capitalized.
    for (int i = 1; i < length; i++)
    {
        if (isupper((int)str[i]))
        {
            strncat(newSentence, strCpy, count);
            strncat(newSentence, " ", 2);
            strCpy += count;
            mem_count += count;
            count = 0;
        }
        count++;
        if (i+1 == length)
        {
            strncat(newSentence, strCpy, strlen(strCpy));
        }
    }

    // Check if the sentence is a question
    if ( (strstr(newSentence, WHO) != NULL) ||
         (strstr(newSentence, WHAT) != NULL) ||
         (strstr(newSentence, WHERE) != NULL) ||
         (strstr(newSentence, WHEN) != NULL) ||
         (strstr(newSentence, HOW) != NULL) ||
         (strstr(newSentence, WHY) != NULL) )
         {
             strncat(newSentence, "?", 2);
         }
    // It's not a question. Add period.
    else
    {
        strncat(newSentence, ".", 2);
    }

    // Turn the capital letters lowercase
    for (int i = 1; i < strlen(newSentence); i++)
    {
        char letter = newSentence[i];
        if (isupper(letter))
        {
            newSentence[i] = tolower(letter);
        }
    }

    // Return strCpy pointer to its original address
    strCpy -= mem_count;
    // Now strCpy can be freed
    free(strCpy);
    return newSentence;
}


