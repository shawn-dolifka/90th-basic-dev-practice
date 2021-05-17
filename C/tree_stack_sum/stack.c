#include "stack.h"

#include <stdlib.h>
#include <string.h>


/* 
 * This function will take a value and push it onto the stack
 * @param stack_ptr a pointer to the stack that you will push elements onto.
 * @param stored_value a pointer to the value in a tree's node.
 * @return return STACK_OPERATION_SUCCESS if successful, return STACK_OPERATION_ERROR if error
 */
int push(p_stack stack_ptr, void* stored_value) {
    if (stack_ptr == NULL || stored_value == NULL)
    {
        return STACK_OPERATION_ERROR;
    }
    p_stack_elem node = (p_stack_elem)malloc(sizeof(stack_elem));
    if (node == NULL)
    {
        return STACK_OPERATION_ERROR;
    }
    // Check if stack is empty
    if (STACK_IS_EMPTY(stack_ptr))
    {
        node->stored_item = stored_value;
        node->next = NULL;
        stack_ptr->top = node;
        stack_ptr->size++;
        return STACK_OPERATION_SUCCESS;
    }
    // Store the tree's value
    node->stored_item = stored_value;
    // Point the new node's next to the element below it in the Stack
    node->next = stack_ptr->top;
    stack_ptr->top = node;
    stack_ptr->size++;
    return STACK_OPERATION_SUCCESS;
}

/* 
 * This function will take pop the top element off of the stack and assign the value coming off to item_value_ptr
 * @param stack_ptr a pointer to the stack that you will pop elements from.
 * @param item_value_ptr a pointer to a tree's node.
 * @return return STACK_OPERATION_SUCCESS if successful, return STACK_OPERATION_ERROR if error
 */
int pop(p_stack stack_ptr, void** item_value_ptr) {
    if (stack_ptr == NULL || STACK_IS_EMPTY(stack_ptr))
    {
        return STACK_OPERATION_ERROR;
    }
    p_stack_elem popped = stack_ptr->top;
    (*item_value_ptr) = popped->stored_item;
    stack_ptr->top = popped->next;
    free(popped);
    stack_ptr->size--;
    return STACK_OPERATION_SUCCESS;
}

/* 
 * This function will allocate a new stack.
 * @return returns a new stack
 */
p_stack stack_create() {
    
    p_stack const new_stack = (p_stack)malloc(sizeof(stack));
    new_stack->size = 0;
    new_stack->top = NULL;
    return new_stack;
}

/* 
 * This function will pop and free all elements of the stack
 * @return return STACK_OPERATION_SUCCESS if successful, return STACK_OPERATION_ERROR if error
 */
int stack_destroy(p_stack const stack_ptr) {
    
    if (stack_ptr == NULL || STACK_IS_EMPTY(stack_ptr))
    {
        return STACK_OPERATION_ERROR;
    }
    while (!STACK_IS_EMPTY(stack_ptr))
    {
        p_stack_elem delete_top = stack_ptr->top;
        if (stack_ptr->top->next != NULL)
        {
            stack_ptr->top = stack_ptr->top->next;
        }
        stack_ptr->size--;
        free(delete_top);
    }
    
    return STACK_OPERATION_SUCCESS;
}
