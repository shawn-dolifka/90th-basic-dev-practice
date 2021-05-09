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
    S0048 - Implement a function that receives input parameters.
    S0079 - Validate expected input.
    S0081 - Implement a looping construct.
    S0108 - Utilize post and pre increment/decrement operators.
    S0082 - Implement conditional control flow constructs.
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/*
Write the function checkHand that receives a 5-element integer array that represents a
fictitious poker hand. The valid values for this array are the numbers 1 through 13. 
For this game of poker there are only three types of hands worth noting:  
three of a kind, four of a kind, or a straight.  A straight involves all 5 cards being 
in a sequence such as 3, 4, 5, 6, 7 etc.

The function will evaluate the array to determine the best hand.  The precedence of 
hands is:

1. straight (best)
2. four of a kind
3. three of a kind
4  nothing (worst)

The function will return one of the following strings based on analysis: 
    "straight", "four", "three", "nothing", or "invalid"

The function will return "invalid" if any of the values are < 1 or > 13.


*/

int compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

enum{FALSE=0,TRUE};

char* checkHand(int hand[])
{
    const int SIZE = 5;
    int cards[13] = {0};
    
    // Count cards and look for invalid cards
    for (int i = 0; i < SIZE; i++)
    {
        if (hand[i] < 1 || hand[i] > 13)
        {
            return "invalid";
        }
        cards[hand[i]]++;
    }

    int have_straight = TRUE;
    qsort(hand, SIZE, sizeof(int), compare);

    // Check for a straight
    for (int i = 0; i < (SIZE-1); i++)
    {
        if (hand[i] + 1 != hand[i+1])
        {
            have_straight = FALSE;
        }   
    }

    if (have_straight)
    {
        return "straight";
    }

    // Check count of each card for matches
    for (int i = 0; i < 13; i++)
    {
        if (cards[i] == 3)
        {
            return "three";
        }
        if (cards[i] == 4)
        {
            return "four";
        }
    }
    return "nothing";
}
