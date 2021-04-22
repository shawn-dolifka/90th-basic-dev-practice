/*
This question is intended to evaluate the following topics:
  A0179 - Implement file management operations.
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0034 - Declare and implement appropriate data types for program requirements.
  S0031 - Utilize logical operators to formulate boolean expressions.
  S0035 - Declare and/or implement of arrays and multi-dimensional arrays.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0036 - Declare and implement a char * array (string).
  S0033 - Utilize assignment operators to update a variable.
  S0042 - Open and close an existing file.
  S0043 - Read, parse, write (append, insert, modify) file data.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0052 - Implement a function that returns a single value.
  S0048 - Implement a function that receives input parameters.
  S0079 - Validate expected input.
  S0097 - Create and use pointers.
  S0081 - Implement a looping construct.
  S0108 - Utilize post and pre increment/decrement operators.
  S0082 - Implement conditional control flow constructs.
  S0160 - Utilize the standard library.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "TestCode.h"

/* DO NOT RUN YOUR SOLUTION IN COMMAND LINE - RUN SOLUTION VIA VISUAL STUDIO DEBUGGER */

/*
This problem will read and stats voting results from four possible states (Texas, California, New York, Florida). 
The voting results are stored in an ascii file with the following information: County number and voter turnout percentage. 
Each line represents this data in a comma delimited format and each value is an integer. The files are located in
the same directory as your source code.

The following is an example of one line entry in the file:

487,54

487 is the county number
54 is the turnout percentage

Write a function findStats that accepts an int representing the state and a two-element int array 
(each element initialized to zero) that will hold a county number and turnout percentage of the 
county with the highest turnout.

The function’s first parameter:
1 – Texas (indicates to use texas.txt file)
2 – California (indicates to use california.txt file)
3 – New York (indicates to use newyork.txt file)
4 - Florida (indicates to use florida.txt file)

The function should open the appropriate file. Read the data a line at a time and find the
county with the highest voting percentage turnout. Place the county number in the first element
of the array, voting percentage in the second element of the array, each as integers.

If invalid first parameter (out of range), function returns ERROR_INVALID_DATA

If any voting percentage in file is < 0 or > 100, function returns ERROR_INVALID_DATA

If file fails to open, function returns ERROR_FILE_INVALID

If file read is successful, function returns ERROR_SUCCESS

Assume all files, once opened, contain valid format

Assume no duplicate high values in a file
*/

int findStats(int state, int stats[])
{
  FILE *the_file;

  // Check which file to open
  switch (state)
  {
  // Texas 
  case 1:
    the_file = fopen("texas.txt", "r");
    break;
  
  // California 
  case 2:
    the_file = fopen("california.txt", "r");
    break;

  // New York
  case 3:
    the_file = fopen("newyork.txt", "r");
    break;
  
  // Florida
  case 4:
    the_file = fopen("florida.txt", "r");
    break;

  // Invalid state code
  default:
    return ERROR_INVALID_DATA;
  }

  // Check if the file didn't open
  if (the_file == NULL)
  {
    return ERROR_FILE_INVALID;
  }
  
  // Array for file lines
  char line[100];

  // Token for strtok
  char* token;

  // Counter for strtok
  int i = 0;

  // Store county and percentage temporarily
  int temp[] = {0,0};

  while (fgets(line, sizeof(line), the_file))
  { 
    token = strtok(line, ",");
    while (token != NULL)
    {
      temp[i] = atoi(token);
      token = strtok(NULL, ",");
      i++;
    }

    // Voter turnout les than 0 or greater than 100
    if (temp[1] < 0 || temp[1] > 100)
    {
      return ERROR_INVALID_DATA;
    }

    // Found a county with higher voter turnout
    if (temp[1] > stats[1])
    {
      stats[0] = temp[0];
      stats[1] = temp[1];
    }

    // Reset the counter for the next line
    i = 0;
  }

  return ERROR_SUCCESS;
}
