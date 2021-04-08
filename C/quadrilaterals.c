/*
This question is intended to evaluate the following topics:
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0029 - Utilize arithmetic operators (PEMDAS +, -, *, /, %) in mathematical equations.
  S0034 - Declare and implement appropriate data types for program requirements.
  S0035 - Declare and/or implement of arrays and multi-dimensional arrays.
  S0033 - Utilize assignment operators to update a variable.
  S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
  S0050 - Implement a function that doesn't return a value.
  S0048 - Implement a function that receives input parameters.
  S0081 - Implement a looping construct.
  S0108 - Utilize post and pre increment/decrement operators.
  S0082 - Implement conditional control flow constructs.
  S0156 - Utilize a struct composite data type.*/
/******************************************************************************

Write a function classify_quads that receives:
    a two-dimensional array of integers,
    an int representing number of rows,
    and a pointer to a struct (defined in the TestCode.h) shown below.

   struct QuadStruct {
  int rect;
  int para;
  int quad;
  int invalid;
}; 

Each row in the array represents the degree angles of a quadrilateral (four-side shape). Where 
indices 0 and 2 are opposite angles, and 1 and 3 are opposite angles as depicted in diagram
below.

        0___________________________________1
        /                                  /
       /                                  /
     3/__________________________________/2


A valid quadrilateral's angles add up to 360.

Example  {{90,90,90,90},
          {160,70,30, 100},
          {110,70,10, 170}}

You are provided a struct with the following integer variables:

- rect - represents a rectangle (having all 90 degree angle) 
- para - represents a parallelogram where both opposite angles are equal and is not
         a rect.
- quad - represents a valid quadrilateral that's not a rect or para
- invalid - any row whose angles do not add up to 360
          - any angle less than or equal to zero (0)
          - any angle greater than or equal to 360

The function should initialize all members of the QuadStruct structure to zero, then
should iterate through the two-dimensional array and process each row
to determine the type of quadrilateral represented in each row, then increment
the appropriate variable inside the struct representing the type of quadrilateral.
Example, if the angles represent a rectangle with all 90 degrees, the "rect" member
will be incremented by 1

*******************************************************************************/

#include <stdio.h>
#include "TestCode.h"

void classify_quads(int quads[][4], int rows, struct QuadStruct *qds)
{
  qds->rect = 0;
  qds->para = 0;
  qds->quad = 0;
  qds->invalid = 0;

  for (int i = 0; i < rows; i++)
  {
    // Get value of all 4 angles
    int angle0 = quads[i][0], 
        angle1 = quads[i][1],
        angle2 = quads[i][2],
        angle3 = quads[i][3];

    int angle_sum = angle0 + angle1 + angle2 + angle3;

    // Angles don't sum to 360
    if (angle_sum != 360)
    {
      qds->invalid++;
    }

    // Any angle is less than or equal to 0
    else if (angle0 < 1 || angle1 < 1 || angle2 < 1 || angle3 < 1)
    {
      qds->invalid++;
    }

    // Any angle is greater than or equal to 360
    else if (angle0 > 359 || angle1 > 359 || angle2 > 359 || angle3 > 359)
    {
      qds->invalid++;
    }

    // Found a rectangle
    else if (angle0 == 90 && angle1 == 90 && angle2 == 90 && angle3 == 90)
    {
      qds->rect++;
    }
    // Found a parallelogram
    else if (angle0 == angle2 && angle1 == angle3)
    {
      qds->para++;
    }
    // It's a quadrilateral
    else
    {
      qds->quad++;
    }
  }
}
