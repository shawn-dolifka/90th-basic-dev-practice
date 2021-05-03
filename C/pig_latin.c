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
  S0053 - Implement a function that returns a memory reference.
  S0090 - Allocate memory on the heap (malloc).
  S0097 - Create and use pointers.
  S0081 - Implement a looping construct.
  S0108 - Utilize post and pre increment/decrement operators.
  S0082 - Implement conditional control flow constructs.
  S0160 - Utilize the standard library.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TestCode.h"

/*
Write a function encodePigLatinPhrase that encodes English-language phrases into pig Latin.

Pig Latin is a form of coded language often used for amusement.
Many variations exist in the methods used to form pig-Latin phrases.
For simplicity, use the following algorithm:
To form a pig-Latin phrase from an English-language phrase:
  1- fragment the phrase into words.
  2- To translate each English word into a pig-Latin word, place the first letter of the English word at the end of the English word and add the letters "ay".

 Thus the word "jump" becomes "umpjay", the word "the" becomes "hetay" and the word "computer" becomes "omputercay".
 Blanks between words remain as blanks.

 Assume the following:
 - The English phrase consists of words separated by blanks, there are no punctuation marks, and all words have two or more letters.
 - If the English phrase is just white space(s), the pig latin phrase is the empty string ""
 - The pig latin phrase is of max length of 80 characters

 The function encodePigLatinPhrase takes a string of english phrase and return a string of Pig Latin Phrase
*/



char* encodePigLatinPhrase(char* englishPhrase)
{
  if (*englishPhrase == '\0')
  {
    return "";
  }

  int phrase_length = strlen(englishPhrase);

  // If the phrase is all spaces, then strspn will equal the length of the phrase
  if (strspn(englishPhrase, " ") == phrase_length)
  {
    return "";
  }

  char* pigLatinPhrase = (char*)calloc(80, sizeof(char));

  /* Strtok modifies the string passed to it. Memory mus be allocated for 
     the phrase passed to use strtok on it. First, create memory on the heap
     for englishPhrase, then copy englishPhrase into the heap's memory. If the
     phrase is not in heap memory, strtok will fail. */
  char* heap_phrase = (char*)calloc(phrase_length, sizeof(char));
  strcpy(heap_phrase, englishPhrase);

  char first_letter[2] = "\0";
  const char delim[2] = " ";
  char* token = strtok(heap_phrase, delim);
  while (token != NULL)
  {
    int token_length = strlen(token);

    // If token is only 1 char long, don't concat anything after it.
    if (token_length > 1)
    {
      strcat(pigLatinPhrase, token+1);
    }
    strncpy(first_letter, token, 1);
    strncat(pigLatinPhrase, first_letter, 2);
    strcat(pigLatinPhrase, "ay");
    token = strtok(NULL, delim);
    if (token != NULL)
    {
      strcat(pigLatinPhrase, " ");
    }
  }
  free(heap_phrase);
  return pigLatinPhrase;
}




