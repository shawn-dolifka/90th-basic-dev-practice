/*
This question is intended to evaluate the following topics:
    A0019 - Integrate functionality between multiple software components.
    A0018 - Analyze a problem to formulate a software solution.
    S0034 - Declare and implement appropriate data types for program requirements.
    S0032 - Utilize relational operators to formulate boolean expressions.
    S0033 - Utilize assignment operators to update a variable.
    S0007 - Skill in writing code in a currently supported programming language (e.g., Java, C++).
    S0050 - Implement a function that doesn't return a value.
    S0067 - Find an item in a Doubly Linked List.
    S0068 - Add and remove nodes from a Doubly Linked List.
    S0052 - Implement a function that returns a single value.
    S0056 - Create and destroy a Doubly Linked List.
    S0053 - Implement a function that returns a memory reference.
    S0048 - Implement a function that receives input parameters.
    S0090 - Allocate memory on the heap (malloc).
    S0097 - Create and use pointers.
    S0091 - Unallocating memory from the heap (free).
    S0081 - Implement a looping construct.
    S0108 - Utilize post and pre increment/decrement operators.
    S0082 - Implement conditional control flow constructs.
    S0156 - Utilize a struct composite data type.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "TestCode.h"

/*
Task #1

Write the function buildList that receives two parameters:
    names - an array of char * of people's first names
    size - the number of elements in the array

The buildList function should iterate through the "names" array and create a doubly-linked list
creating a node for each name in the "names" array. Use the nameNode class defined in the TestCode.h file to create the
doubly-linked list. Each name is added to the head of the doubly-linked list.

The function should return a pointer to the head node of the doubly-linked list when complete.

Task #2

Write the function removeNode that receives two parameters:
    head - a pointer to the first node in the doubly-linked list created in Task 1
    findName - a char * of a person's name that may be in a linked-list

The removeNode function will search the doubly-linked list for the name in "findName". If found, the node containing the
name must be removed from the doubly-linked list, ensure to cleanup any memory. If not found, do nothing.

The function should return a pointer to the head node of the doubly-linked list when complete.

Task #3

Write the function freeMemory that receives a pointer to your linked-list's head
node so you can iterate over the link list and free all allocated memory.

*/


struct nameNode* buildList(const char** names, int size)
{
    struct nameNode *head = (struct nameNode*)malloc(sizeof(struct nameNode));
    head->name = names[0];
    head->next = NULL;
    head->prev = NULL;
    //struct nameNode *current = head;
    for (int i = 1; i < size; i++)
    {
        struct nameNode *new_node = (struct nameNode*)malloc(sizeof(struct nameNode));
        // Point the head->next to the new node
        head->prev = new_node;
        new_node->name = names[i];
        new_node->next = head;
        new_node->prev = NULL;
        head = new_node;
    }

    return head;

}

struct nameNode* removeNode(struct nameNode* head, const char* findName)
{
    struct nameNode* current = head;
    while (current != NULL)
    {
        if (current->name == findName)
        {
            // Head node is the only node left
            if (current->next == NULL && current->prev == NULL)
            {
                head = NULL;
                free(current);
                return head;
            }
            // Deleting the head node
            if (current->prev == NULL)
            {
                current->next->prev = NULL;
                head = current->next;
                free(current);
                return head;
            }
            // Deleting the tail node
            if (current->next == NULL)
            {
                current->prev->next = NULL;
                free(current);
                return(head);
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            return head;
        }
        current = current->next;
    }
    return head;
}

void freeMemory(struct nameNode *head)
{
    struct nameNode* current = head;
    struct nameNode* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
