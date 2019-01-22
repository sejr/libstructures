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

void BinaryTreeNode_free(BinaryTreeNode *node)
{
    if (node->left)
        BinaryTreeNode_free(node->left);
    if (node->right)
        BinaryTreeNode_free(node->right);
    free(node);
}

BinaryTreeNode *BinaryTreeNode_clone(BinaryTreeNode *node)
{
    BinaryTreeNode *clone = BinaryTreeNode_init(node->data);
    if (node->left)
        clone->left = BinaryTreeNode_clone(node->left);
    if (node->right)
        clone->right = BinaryTreeNode_clone(node->right);
    return clone;
}

BinaryTreeNode *BinaryTreeNode_setLeft(
    BinaryTreeNode *parent,
    BinaryTreeNode *child)
{
    BinaryTreeNode *newParent = BinaryTreeNode_clone(parent);
    // BinaryTreeNode_free(newParent->left);
    newParent->left = BinaryTreeNode_clone(child);
    return newParent;
}

BinaryTreeNode *BinaryTreeNode_setRight(
    BinaryTreeNode *parent,
    BinaryTreeNode *child)
{
    BinaryTreeNode *newParent = BinaryTreeNode_clone(parent);
    // BinaryTreeNode_free(newParent->right);
    newParent->right = BinaryTreeNode_clone(child);
    return newParent;
}

int BinaryTreeNode_equals(BinaryTreeNode *a, BinaryTreeNode *b)
{
    if (a->data != b->data)
        return 0;

    int left = 1;
    int right = 1;
    if (a->left && b->left)
        left = BinaryTreeNode_equals(a->left, b->left);
    if (a->right && b->right)
        right = BinaryTreeNode_equals(a->right, b->right);

    return left && right;
}

int BinaryTreeNode_height(BinaryTreeNode *node)
{
    int height = 1;
    int leftHeight = height;
    int rightHeight = height;
    if (node->left)
        leftHeight += BinaryTreeNode_height(node->left);
    if (node->right)
        rightHeight += BinaryTreeNode_height(node->right);

    if (leftHeight > rightHeight)
    {
        return leftHeight;
    }
    else
    {
        return rightHeight;
    }
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