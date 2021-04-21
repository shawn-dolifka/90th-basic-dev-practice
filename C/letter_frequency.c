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
  S0048 - Implement a function that receives input parameters.
  S0079 - Validate expected input.
  S0081 - Implement a looping construct.
  S0108 - Utilize post and pre increment/decrement operators.
  S0082 - Implement conditional control flow constructs.
  S0160 - Utilize the standard library.*/
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * The function letterFrequency takes as input a one-line strings
 * and determines the total occurrences of each letter of the alphabet in the line.
 *
 * Case sensitivity is not an issue i.e. "A" and "a" are the considered the same for this question
 * If a non-alpha character is encountered it should be ignored, adding nothing to any count.
 *
 * @param sentence      The input string to process
 * @param frequencyTable  An already allocated buffer in which to place the output
 *
 * Expected Return Values:
 *    - The task is successful: 1
 *    - Bad input is provided: 0
 */

int letterFrequency(const char* sentence, int* frequencyTable)
{
  // Invalid input
  if (sentence == NULL)
  {
    return 0;
  }

  int size = strlen(sentence);

  // Invalid input
  if (size < 1)
  {
    return 0;
  }

  for (int i = 0; i < size; i++)
  {
    if isalpha(sentence[i])
    {
      char letter = tolower(sentence[i]);
      // a = 97 and index 0 is a
      // Subtract 97 to get the corresponding index for a characer
      frequencyTable[(int)letter - 97]++;
    }
  }
  return 1;
}
