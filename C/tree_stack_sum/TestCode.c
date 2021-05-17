/*
This question is intended to evaluate the following topics:
  A0061 - Create and implement functions to meet a requirement.
  A0019 - Integrate functionality between multiple software components.
  A0018 - Analyze a problem to formulate a software solution.
  S0397 - Create and use complex Data Structures.
  S0034 - Declare and implement appropriate data types for program requirements.
  S0031 - Utilize logical operators to formulate boolean expressions.
  S0035 - Declare and/or implement of arrays and multi-dimensional arrays.
  S0032 - Utilize relational operators to formulate boolean expressions.
  S0033 - Utilize assignment operators to update a variable.
  S0066 - Add and remove nodes from a Linked List.
  S0052 - Implement a function that returns a single value.
  S0078 - Push and pop a Stack.
  S0062 - Create and destroy a Stack.
  S0055 - Create and destroy a Linked List.
  S0053 - Implement a function that returns a memory reference.
  S0048 - Implement a function that receives input parameters.
  S0079 - Validate expected input.
  S0097 - Create and use pointers.
  S0081 - Implement a looping construct.
  S0108 - Utilize post and pre increment/decrement operators.
  S0082 - Implement conditional control flow constructs.
  S0156 - Utilize a struct composite data type.*/
#include "TestCode.h"
#include "stack.h"

#include <stdio.h>

/*
KSATs:  
"A0018" "2" 
"A0019" "2"
"A0698","2"
"A0735","3"
"S0081","3"
"S0082","3"
"S0053","3"
"S0055","3"
"S0034","3"
"S0035","3"
"S0108","3"
"S0051","3"
"S0052","3"
"S0048","3"
"S0031","3"
"S0032","3"
"S0062","2"
"S0066","3"
"S0078","2"
"S0079","2"
"S0097","3"
"S0156","3"
"S0033", "3"
*/

/** 
 * Write a function calculate_tree_sum that receives a pointer to a tree structure(found in binary_tree.h).
 * A visualization of the tree structure can be found in the resources directory
 * The calculate_tree_sum function will calculate the sum of the elements within the tree by traversing the nodes and putting them into a stack.
 * You will also implement stack management functions for the stack structure(found in stack.h).
 * Create your stack functions in stack.c.
 * You can find the function signatures in stack.h. 
 * (You are allowed to modify these if you want to implement these differently)
 * 
 * If the parameter tree_ptr or its root is NULL, return TREE_ERROR
 * If the unable to create the stack, return TREE_ERROR
 * 
 * *** IMPORTANT: You are not allowed to use recursion and you may not traverse the stack that is used in the tree structure
 *
 * Be sure to free every resource that you created, i.e., the function should end with the same amount of resources
 * allocated as you began with.
 * 
 * @param tree_ptr a pointer to the tree that you will calculate the sum of all nodes for
 * @return the sum of all nodes in the tree. If there is an error, return TREE_ERROR instead
 */

/*
Go into binary_tree.c and change the push functions from '&new_node' to 'new_node'
Pass the pointer to the function, not the address of the pointer. Unless there's a 
good reason why the push() funtion in the tree passes the address of the node instead
of a pointer to the node, the template code is implemented in a way to over-complicate
what should have been a lot simpler.

*/

int calculate_tree_sum(const p_tree tree_ptr) {
    if (tree_ptr == NULL || tree_ptr->root == NULL)
    {
      return TREE_ERROR;
    }

    if (tree_ptr->stack == NULL)
    {
      return TREE_ERROR;
    }
    int tree_sum = 0;
    while (!STACK_IS_EMPTY(tree_ptr->stack))
    {
      void *void_node_ptr = NULL;
      pop(tree_ptr->stack, &void_node_ptr);
      p_node tree_node_ptr = (p_node)void_node_ptr;
      tree_sum += tree_node_ptr->key;
    }
    
    return tree_sum;
}
