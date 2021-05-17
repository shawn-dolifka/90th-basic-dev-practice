#include "binary_tree.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>


/*
 * You are not expected to modify this file. You might have to if you decide to change the implementation of the
 * stack from the linked-list implementation.
 */


int attach_node_to_left_of(p_node attach_to, p_node left_node);
int attach_node_to_right_of(p_node attach_to, p_node right_node);

int create_tree(p_tree* pp_tree) {
    p_tree const new_tree = (p_tree) malloc(sizeof(tree));
    if (NULL != new_tree) {
        new_tree->root = NULL;
        new_tree->size = 0;
        new_tree->stack = stack_create();
        if (!new_tree->stack) {
            assert(DESTROY_TREE_SUCCESS == destroy_tree(new_tree));
            return CREATE_TREE_ERROR;
        }
        *pp_tree = new_tree;
        return CREATE_TREE_SUCCESS;
    }
    return CREATE_TREE_ERROR;
}

int destroy_tree(p_tree const tree_ptr) {
    if (!tree_ptr || !tree_ptr->stack)
        return DESTROY_TREE_ERROR;

    stack_destroy(tree_ptr->stack);
    memset(tree_ptr, 0, sizeof(tree));
    free(tree_ptr);
    return DESTROY_TREE_SUCCESS;
}

int tree_attach_root(p_tree const tree_ptr, p_node new_root) {
    if (!tree_ptr || !new_root || tree_ptr->root)
        return CREATE_TREE_ERROR;

    tree_ptr->root = new_root;
    push(tree_ptr->stack, new_root);
    tree_ptr->size++;
    return CREATE_TREE_SUCCESS;
}

int tree_attach_left(p_tree const tree_ptr, p_node const attach_to, p_node left_node) {
    if (!tree_ptr || !attach_to || !left_node)
        return ATTACH_NODE_ERROR;

    attach_node_to_left_of(attach_to, left_node);
    push(tree_ptr->stack, left_node);
    tree_ptr->size++;
    return ATTACH_NODE_SUCCESS;
}

int tree_attach_right(p_tree const tree_ptr, p_node const attach_to, p_node right_node) {
    if (!tree_ptr || !attach_to || !right_node)
        return ATTACH_NODE_ERROR;

    attach_node_to_right_of(attach_to, right_node);
    push(tree_ptr->stack, right_node);
    tree_ptr->size++;
    return ATTACH_NODE_SUCCESS;

}

p_node create_node(int const value) {
    p_node const new_node = (p_node) malloc(sizeof(node));
    if (NULL != new_node) {
        new_node->key = value;
        new_node->left = NULL;
        new_node->right = NULL;
    }

    return new_node;
}

int destroy_node(p_node const target) {
    if (target) {
        if ((NULL == target->left) && (NULL == target->right)) {
            memset(target, 0, sizeof(node));
            free(target);
            return DESTROY_NODE_SUCCESS;
        }
    }
    return DESTROY_NODE_ERROR;
}

void attach_node(p_node* pp_attach_pointer, p_node const node) {
    if (!*pp_attach_pointer)
        *pp_attach_pointer = node;
}

int attach_node_to_left_of(p_node attach_to, p_node const left_node) {
    if (!attach_to->left && left_node) {
        attach_node(&attach_to->left, left_node);
        return ATTACH_NODE_SUCCESS;
    }
    return ATTACH_NODE_ERROR;
}

int attach_node_to_right_of(p_node attach_to, p_node const right_node) {
    if (!attach_to->right && right_node) {
        attach_node(&attach_to->right, right_node);
        return ATTACH_NODE_SUCCESS;
    }
    return ATTACH_NODE_ERROR;
}
