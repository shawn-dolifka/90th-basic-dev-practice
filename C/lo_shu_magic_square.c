/*
This question is intended to evaluate the following topics:
    A0019 - Integrate functionality between multiple software components.
    A0018 - Analyze a problem to formulate a software solution.
    S0029 - Utilize arithmetic operators (PEMDAS +, -, *, /, %) in mathematical equations.
    S0034 - Declare and implement appropriate data types for program requirements.
    S0031 - Utilize logical operators to formulate boolean expressions.
    S0035 - Declare and/or implement of arrays and multi-dimensional arrays.
    S0032 - Utilize relational operators to formulate boolean expressions.
    S0033 - Utilize assignment operators to update a variable.
    S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
    S0052 - Implement a function that returns a single value.
    S0048 - Implement a function that receives input parameters.
    S0081 - Implement a looping construct.
    S0108 - Utilize post and pre increment/decrement operators.
    S0082 - Implement conditional control flow constructs.
*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include"TestCode.h"


/*
  The Lo Shu Magic Square is a grid with 3 rows and 3 columns like the example shown below:
   4 9 2
   3 5 7
   8 1 6

   The Lo Shu Magic Square has the following properties:
    1- The grid contains the numbers 1 through 9 exactly.
    2- The sum of each row, each column, and each diagonal all add up to the same number.
        - so, for the previous example, all rows, columns, and diagonals gives sum = 15

  Write a function isMagicSquare that accepts a two-dimensional array as an argument, and determines whether the array is a Lo Shu Magic Square.


// The isMagicSquare function accepts a two-dimensional   *
// int array as an argument, and returns 1 if the      *
// array meets all the requirements of a magic square.    *
// Otherwise, it returns 0.     

*/
enum {FALSE=0, TRUE=1};

int isMagicSquare(int values[][COLS])
{
    const int GRID_SIZE = 3;
    const int LO_SHU_SUM = 15;
    int isMagic = TRUE;
    int total = 0;

    // Sum rows
    for (int row = 0; row < GRID_SIZE; row++)
    {
        total = 0;
        for (int column = 0; column < GRID_SIZE; column++)
        {
            total += values[row][column];
        }
        if (total != LO_SHU_SUM)
        {
            return FALSE;
        }

    }

    // Sum columns
    for (int column = 0; column < GRID_SIZE; column++)
    {
        total = 0;
        for (int row = 0; row < GRID_SIZE; row++)
        {
            total += values[row][column];
        }
        if (total != LO_SHU_SUM)
        {
            return FALSE;
        }
    }

    /* Sum diagonal Top-Left to Bottom-Right
            [x][][]
            [][x][]   
            [][][x]
    */
    total = 0;
    for (int i = 0; i < GRID_SIZE; i++)
    {
        total += values[i][i];
    }
    if (total != LO_SHU_SUM)
    {
        return FALSE;
    }

    /* Sum of Top-Right to Bottom-Left
            [][][x]
            [][x][]
            [x][][]
    */
    total = 0;
    for (int i = GRID_SIZE-1; i >= 0; i--)
    {
        total += values[i][i];
    }
    if (total != LO_SHU_SUM)
    {
        return FALSE;
    }
    return TRUE;
}
