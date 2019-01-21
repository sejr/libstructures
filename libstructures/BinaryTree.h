#ifndef LIBSTRUCTURES_BINARYTREE_H
#define LIBSTRUCTURES_BINARYTREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

BinaryTreeNode *BinaryTreeNode_init(int data)
{
    BinaryTreeNode *node = malloc(sizeof(BinaryTreeNode));
    if (node != NULL)
    {
        node->data = data;
        node->left = NULL;
        node->right = NULL;
    }
    else
    {
        // If the memory allocation does not succeed, we alert the user.
        fprintf(stderr, "Error allocating memory for LinkedListNode");
    }

    return node;
}

void printDepth(int depth)
{
    const int SPACE_COUNT = 4;
    for (int i = 0; i < SPACE_COUNT * depth; i++)
    {
        printf(" ");
    }
}

void _BinaryTreeNode_print(BinaryTreeNode *node, int depth)
{
    printf("BinaryTreeNode {\n");
    printDepth(depth + 1);
    printf("data: %d", node->data);

    if (node->left)
    {
        printf("\n");
        printDepth(depth + 1);
        printf("left: ");
        _BinaryTreeNode_print(node->left, depth + 1);
    }
    else
    {
        printf("\n");
        printDepth(depth + 1);
        printf("left: NULL");
    }

    if (node->right)
    {
        printf("\n");
        printDepth(depth + 1);
        printf("right: ");
        _BinaryTreeNode_print(node->right, depth + 1);
    }
    else
    {
        printf("\n");
        printDepth(depth + 1);
        printf("right: NULL");
    }

    printf("\n");
    printDepth(depth);
    printf("}");
}

void BinaryTreeNode_print(BinaryTreeNode *node)
{
    _BinaryTreeNode_print(node, 0);
}

#endif