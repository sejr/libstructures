#include <stdio.h>
#include <assert.h>
#include "../libstructures/BinaryTree.h"

int main()
{
    BinaryTreeNode *root = BinaryTreeNode_init(2);

    // Second level
    root->left = BinaryTreeNode_init(7);
    root->right = BinaryTreeNode_init(5);

    // Third level
    root->left->left = BinaryTreeNode_init(2);
    root->left->right = BinaryTreeNode_init(6);
    root->right->right = BinaryTreeNode_init(9);

    // Fourth level
    root->left->right->left = BinaryTreeNode_init(5);
    root->left->right->right = BinaryTreeNode_init(11);

    BinaryTreeNode_print(root);
}