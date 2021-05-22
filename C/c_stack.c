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
  S0078 - Push and pop a Stack.
  S0062 - Create and destroy a Stack.
  S0053 - Implement a function that returns a memory reference.
  S0048 - Implement a function that receives input parameters.
  S0079 - Validate expected input.
  S0090 - Allocate memory on the heap (malloc).
  S0097 - Create and use pointers.
  S0091 - Unallocating memory from the heap (free).
  S0081 - Implement a looping construct.
  S0108 - Utilize post and pre increment/decrement operators.
  S0082 - Implement conditional control flow constructs.
  S0156 - Utilize a struct composite data type.
  S0160 - Utilize the standard library.*/
#include <stdio.h>
#include <string.h>
#include "TestCode.h"


/*
This task will implement a simple stack using a linked list. A numNode struct is defined in the 
TestCode.h file to facilitate the creation of the stack.

Write the function createStack that received two parameters:

    actions: an int array - this array contains values in the even indices 0,2,4 etc that indicate which type of 
                          action to do with the stack:
                1 - pop the stack
                2 - push onto the stack
                3 - empty the stack

                The odd indices will only apply for push actions. If the action received is action
                push (2), then the following index contains the value to push onto the stack. The
                odd indices have no effect on pop (1) or empty stack (3)
                
                So if the function receives:  [2, 7, 2, 2, 1, 0, 3, 0], then you would push 7 onto
                the stack, then push 2 onto the stack, then pop the stack, then empty the stack.

    numActions: the total number of actions supplied in the array

The function should iterate the actions array and determine what actions should occur on the stack.  Use a 'switch'
statement to determine which action to take on the stack and provide the implementation for popping, pushing, and 
emptying the stack accordingly.

If any action provided is not 1, 2, or 3, then return NULL.

Assume that the array will always have an even number of elements. 

The function will return a pointer that points to the top of the stack.

*/

#include <stdlib.h>

typedef struct numNode numNode, *numNode_ptr;

// Push value onto stack
void push(numNode_ptr *stack_top, int number)
{
  if ((*stack_top) == NULL)
  {
    numNode *top = (numNode_ptr)malloc(sizeof(numNode));
    top->num = number;
    top->next = NULL;
    (*stack_top) = top;
  }
  else
  {
    numNode_ptr new_top = (numNode_ptr)malloc(sizeof(numNode));
    new_top->num = number;
    new_top->next = (*stack_top);
    (*stack_top) = new_top;
  }
}

// Pop value from stack
void pop(numNode_ptr* stack_top)
{
  if ((*stack_top) != NULL)
  {
    numNode_ptr popped = (*stack_top);
    (*stack_top) = (*stack_top)->next;
    free(popped);
  }
}

// Empty the stack
void empty(numNode_ptr* stack)
{
  while ((*stack) != NULL)
  {
    pop(stack);
  }
}

numNode * createStack(int actions[], int numActions)
{
  numNode_ptr top = NULL;
  // Array size is double the number of actions
  for (int i = 0; i < (numActions * 2); i+=2)
  {
    int stack_action = actions[i];
    int value = actions[i+1];
    switch (stack_action)
    {
    // Pop
    case 1:
      pop(&top);
      break;
    
    // Push
    case 2:
      push(&top, value);
      break;
    
    // Empty stack
    case 3:
      empty(&top);
      break;
    
    // Invalid action
    default:
      return NULL;
    }
  }
  
  return top;
}
