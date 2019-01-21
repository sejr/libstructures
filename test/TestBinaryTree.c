#include <stdio.h>
#include <assert.h>
#include "../libstructures/BinaryTree.h"

int main()
{
    BinaryTreeNode *root = BinaryTreeNode_init(1);
    root->left = BinaryTreeNode_init(2);
    root->right = BinaryTreeNode_init(3);
    root->right->right = BinaryTreeNode_init(4);
    root->right->right->left = BinaryTreeNode_init(5);

    BinaryTreeNode_print(root);
}