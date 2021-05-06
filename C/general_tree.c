/*See README.md for instructions*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "TestCode.h"

/*
    Assumptions:

        1.) The array will always have an even number of items.
        2.) 'size' will always match the size of the array
        3.) No duplicate values for 'number' will be in the array
        4.) Nodes with a parent number > 0 will always have a matching parent node.

    Even indexes will hold parent_numbers.
    Odd indexes will hold numbers for each node.
    nums[0] and nums[1] will be used to create a node,
    the nums[2] and nums [3] for the next node etc. 
*/

struct TreeNode * buildTree(int nums[], int size)
{
    // Create the first TreeNode to start
    struct TreeNode *first_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    first_node->parent_number = nums[0];
    first_node->number = nums[1];
    first_node->firstChild = NULL;
    first_node->nextSibling = NULL;

    // First node is already created. Start at 2nd node
    for (int i = 2; i < size; i+=2)
    {
        int parent = nums[i], number = nums[i+1];
        struct TreeNode *new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        new_node->parent_number = parent;
        new_node->number = number;
        new_node->firstChild = NULL;
        new_node->nextSibling = NULL;

        struct TreeNode *current = first_node;
        // {0,4,4,2,4,5,4,6,0,12,0,14,14,77,14,56}
        if (parent > 0)
        {     
            // First loop through Level 1 to find the right parent number
            while (current->number != parent)
            {
                current = current->nextSibling;
            }
            
            // Proper parent found. Check if it has a first child already
            if (current->firstChild == NULL)
            {
                current->firstChild = new_node;
            }
            else
            {            
                // The parent has a firstChild already. Move to firstChild and check its siblings
                current = current->firstChild;
                while (current->nextSibling != NULL)
                {
                    current = current->nextSibling;
                }
                current->nextSibling = new_node;
            }
        }
        else
        {
            while (current->nextSibling != NULL)
            {
                current = current->nextSibling;
            }
            current->nextSibling = new_node;
        }
    }
    return first_node;
}
