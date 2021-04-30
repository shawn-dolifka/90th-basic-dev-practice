#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "TestCode.h"

// Refer to README.md for the instructions

// Don't forget to add Typedef to the Header file.
// Original problem doesn't Typedef numNode.

numNode *createNode(int value)
{
    numNode* result = malloc(sizeof(numNode));
    if (result != NULL)
    {
        result->val = value;
        result->left = NULL;
        result->right = NULL;
    }
    return result;
}

void insertNum(numNode **root_ptr, int value)
{
    numNode *root = *root_ptr;

    // Tree is empty
    if (root == NULL)
    {
        (*root_ptr) = createNode(value);
        return;
    }
    // Duplicate value in tree
    if (value == root->val)
    {
        return;
    }
    // Value less than root
    if (value < root->val)
    {
        return insertNum(&(root->left), value);
    }
    // Value greater than root
    else
    {
        return insertNum(&(root->right), value);
    }
}

struct numNode* buildBST(int nums[], int size)
{
    numNode* root = createNode(nums[0]);
    for (int i = 1; i < size; i++)
    {
        insertNum(&root, nums[i]);
    }
    return root;
}


int destroyBST(struct numNode *root)
{
    int count = 1;
    if (root == NULL)
    {
        return 0;
    }

    count += destroyBST(root->left);
    count += destroyBST(root->right);
    free(root);

    return count;
}


