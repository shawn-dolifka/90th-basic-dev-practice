/*
This question is intended to evaluate the following topics:
  A0179 - Implement file management operations.
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0034 - Declare and implement appropriate data types for program requirements.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0033 - Utilize assignment operators to update a variable.
  S0042 - Open and close an existing file.
  S0046 - Determine location of content within a file.
  S0045 - Determine the size of a file.
  S0043 - Read, parse, write (append, insert, modify) file data.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0052 - Implement a function that returns a single value.
  S0079 - Validate expected input.
  S0097 - Create and use pointers.
  S0108 - Utilize post and pre increment/decrement operators.
  S0082 - Implement conditional control flow constructs.
  S0160 - Utilize the standard library.*/
/*

Write the function searchFile that receives two parameters:
  1. fname - a char * representing a file name of a file to read
  2. str - a char * representing a string to search for in the file

The function should initially determine the size of the file. If the
file size in bytes is > 150, the function will read through the file
"fname" and find all occurrences of the string in "str". The function
will return the count of the number of "str" occurrences in the file.

The function should return -1 if the file size is <= 150.

if the file in "fname" does not exist, the function should return -2

*/
#include "TestCode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchFile(char *fname, char *str) 
{
  FILE* fp = fopen(fname, "r");
  if (fp == NULL)
  {
    return -2;
  }

  // Set the file position of the stream to the end of file
  fseek(fp, 0L, SEEK_END);
  long int file_size = ftell(fp);
  if (file_size <= 150)
  {
    return -1;
  }

  // Return the file position of the stream to the beginning.
  // Must be returned to the beginning or fgets will start at EOF.
  fseek(fp, 0L, SEEK_SET);
  char line[100] = {0};
  int matches = 0;

  while (fgets(line, sizeof(line), fp) != NULL)
  {
    const char *temp = line;
    while (temp = strstr(temp, str))
    {
      matches++;
      temp++;
    }
  }
  fclose(fp);
  return matches;
}
