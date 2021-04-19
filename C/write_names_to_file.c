/*
This question is intended to evaluate the following topics:
  A0179 - Implement file management operations.
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0029 - Utilize arithmetic operators (PEMDAS +, -, *, /, %) in mathematical equations.
  S0034 - Declare and implement appropriate data types for program requirements.
  S0031 - Utilize logical operators to formulate boolean expressions.
  S0035 - Declare and/or implement of arrays and multi-dimensional arrays.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0036 - Declare and implement a char * array (string).
  S0033 - Utilize assignment operators to update a variable.
  S0042 - Open and close an existing file.
  S0043 - Read, parse, write (append, insert, modify) file data.
  S0044 - Create and delete file.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0052 - Implement a function that returns a single value.
  S0077 - Add and remove items from a Hash Table.
  S0048 - Implement a function that receives input parameters.
  S0081 - Implement a looping construct.
  S0108 - Utilize post and pre increment/decrement operators.
  S0082 - Implement conditional control flow constructs.
  S0160 - Utilize the standard library.*/
/*

Write the function writeNames that receives four (4) parameters:
   1. fnames (char ** array)  - represents char * strings of people's first names
   2. lnames (char ** array)  - represents char * strings of people's last names
   3. sz (int) - the size of both arrays (both arrays will be same length)
   4. fileName - the name of the file to write data to.

The writeNames function will process the arrays and write each person's last name
and first name to the file name passed. Each line of the file should contain 
a person's last name, followed by a comma and a space, then the first name such as:

Smith, John\n
Jones, Sally\n
Adams, Becky(EOF)

The first names and last names align to the same index in each array.  For example, a person's first
name will be in fnames[0] and their last name in lnames[0].

Ensure when you write the names out to the files, the first letter of each name is capitalized like
the example above.

Ensure that the last line of the file does NOT contain a newline char (\n) at the end.

If the sz is 0 or less, or if the length of any of the names are zero (0), the function 
should return 0 without creating a file.
Otherwise, the function should return 1.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TestCode.h"

int writeNames(char ** fnames, char ** lnames, int sz, char *fileName)
{
  // Check for valid array size
  if (sz < 1)
  {
    return 0;
  }
  
  // Check if any first or last names are missing
  for (int i = 0; i < sz; i++)
  {
    if ( (int)strlen(fnames[i]) == 0 || (int)strlen(lnames[i]) == 0 )
    {
      return 0;
    }
  }

  FILE* out = fopen("names.txt", "w");

  for (int i = 0; i < sz; i++)
  {
    char first[20];
    char last[20];
    strcpy(first,fnames[i]);
    strcpy(last,lnames[i]);
    first[0] = toupper(first[0]);
    last[0] = toupper(last[0]);
    
    // Reached last name in array
    if (i == (sz-1) )
    {
      fprintf(out, "%s, %s", last, first);
      fclose(out);
      return 1;
    }
    fprintf(out, "%s, %s\n", last, first);
  }
}


