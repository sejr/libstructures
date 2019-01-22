#ifndef LIBSTRUCTURES_BINARYTREE_H
#define LIBSTRUCTURES_BINARYTREE_H

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Default structure for representing a binary tree node.
 */
typedef struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

/**
 * @brief Initializes a binary tree node with some data stored in an integer.
 * 
 * @param data the data to be stored in the node.
 * @return BinaryTreeNode* address of the newly-created node.
 */
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

/**
 * @brief Recursively frees a node and its children.
 * 
 * @param node the node we want to free.
 */
void BinaryTreeNode_free(BinaryTreeNode *node)
{
    if (node->left)
        BinaryTreeNode_free(node->left);
    if (node->right)
        BinaryTreeNode_free(node->right);
    free(node);
}

/**
 * @brief A helper function that enables immutability by allowing us
 * to recursively copy a binary tree node and its children into a new object.
 * 
 * @param node the node to be cloned.
 * @return BinaryTreeNode* address of the cloned node.
 */
BinaryTreeNode *BinaryTreeNode_clone(BinaryTreeNode *node)
{
    BinaryTreeNode *clone = BinaryTreeNode_init(node->data);
    if (node->left)
        clone->left = BinaryTreeNode_clone(node->left);
    if (node->right)
        clone->right = BinaryTreeNode_clone(node->right);
    return clone;
}

/**
 * @brief Sets the left child for some parent node.
 * 
 * @param parent the node we want to serve as the parent.
 * @param child the node to be inserted on the left side.
 * @return BinaryTreeNode* Returns the parent node with child as its left child.
 */
BinaryTreeNode *BinaryTreeNode_setLeft(
    BinaryTreeNode *parent,
    BinaryTreeNode *child)
{
    BinaryTreeNode *newParent = BinaryTreeNode_clone(parent);
    // BinaryTreeNode_free(newParent->left);
    newParent->left = BinaryTreeNode_clone(child);
    return newParent;
}

/**
 * @brief Sets the right child for some parent node.
 * 
 * @param parent the node we want to serve as the parent.
 * @param child the node to be inserted on the right side.
 * @return BinaryTreeNode* Returns the parent with child as its right child.
 */
BinaryTreeNode *BinaryTreeNode_setRight(
    BinaryTreeNode *parent,
    BinaryTreeNode *child)
{
    BinaryTreeNode *newParent = BinaryTreeNode_clone(parent);
    // BinaryTreeNode_free(newParent->right);
    newParent->right = BinaryTreeNode_clone(child);
    return newParent;
}

/**
 * @brief Checks for shallow (value-based) equality between two binary trees.
 * 
 * @param a root of the first binary tree.
 * @param b root of the second binary tree.
 * @return int 1 if the values in the trees are equal; 0 otherwise.
 */
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

/**
 * @brief Returns the height of the binary tree starting at some root node.
 * 
 * @param node the root from which we want to compute the height.
 * @return int height of the binary tree.
 */
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

/**
 * @brief Helper function to enable human-readable  printing of binary trees.
 * 
 * @param depth value representing how "nested" a node is within a tree.
 */
void _printDepth(int depth)
{
    const int SPACE_COUNT = 4;
    for (int i = 0; i < SPACE_COUNT * depth; i++)
    {
        printf(" ");
    }
}

/**
 * @brief Helper function that prints a tree, given some depth.
 * 
 * @param node the node to be printed.
 * @param depth the depth at which to print the node.
 */
void _BinaryTreeNode_print(BinaryTreeNode *node, int depth)
{
    printf("BinaryTreeNode {\n");
    _printDepth(depth + 1);
    printf("data: %d", node->data);

    if (node->left)
    {
        printf("\n");
        _printDepth(depth + 1);
        printf("left: ");
        _BinaryTreeNode_print(node->left, depth + 1);
    }
    else
    {
        printf("\n");
        _printDepth(depth + 1);
        printf("left: NULL");
    }

    if (node->right)
    {
        printf("\n");
        _printDepth(depth + 1);
        printf("right: ");
        _BinaryTreeNode_print(node->right, depth + 1);
    }
    else
    {
        printf("\n");
        _printDepth(depth + 1);
        printf("right: NULL");
    }

    printf("\n");
    _printDepth(depth);
    printf("}");
}

/**
 * @brief High-level API to print a binary tree node and its children.
 * 
 * @param node the node we want to print.
 */
void BinaryTreeNode_print(BinaryTreeNode *node)
{
    _BinaryTreeNode_print(node, 0);
}

/**
 * @brief Performs a pre-order traversal and executes some function on each
 * node in the binary tree.
 * 
 * @param root the root node of the tree.
 * @param fn the function to be called on each node.
 */
void BinaryTreeNode_preorderTraversal(
    BinaryTreeNode *root,
    void (*fn)(BinaryTreeNode *))
{
    BinaryTreeNode *temp = root;
    (*fn)(temp);
    if (root->left)
    {
        BinaryTreeNode_preorderTraversal(root->left, (*fn));
    }
    if (root->right)
    {
        BinaryTreeNode_preorderTraversal(root->right, (*fn));
    }
}

/**
 * @brief Performs an in-order traversal and executes some function on each
 * node in the binary tree.
 * 
 * @param root the root node of the tree.
 * @param fn the function to be called on each node.
 */
void BinaryTreeNode_inorderTraversal(
    BinaryTreeNode *root,
    void (*fn)(BinaryTreeNode *))
{
    BinaryTreeNode *temp = root;
    if (root->left)
    {
        BinaryTreeNode_inorderTraversal(root->left, (*fn));
    }
    (*fn)(temp);
    if (root->right)
    {
        BinaryTreeNode_inorderTraversal(root->right, (*fn));
    }
}

/**
 * @brief Performs a post-order traversal and executes some function on each
 * node in the binary tree.
 * 
 * @param root the root node of the tree.
 * @param fn the function to be called on each node.
 */
void BinaryTreeNode_postorderTraversal(
    BinaryTreeNode *root,
    void (*fn)(BinaryTreeNode *))
{
    BinaryTreeNode *temp = root;
    if (root->left)
    {
        BinaryTreeNode_postorderTraversal(root->left, (*fn));
    }
    if (root->right)
    {
        BinaryTreeNode_postorderTraversal(root->right, (*fn));
    }
    (*fn)(temp);
}

#endif