#include <stdio.h>
#include <assert.h>
#include "../libstructures/BinaryTree.h"

int main()
{
    // Instantiating individual nodes
    BinaryTreeNode *a = BinaryTreeNode_init(9);
    BinaryTreeNode *b = BinaryTreeNode_setLeft(a, BinaryTreeNode_init(4));

    BinaryTreeNode *c = BinaryTreeNode_init(5);
    BinaryTreeNode *d = BinaryTreeNode_setRight(c, b);

    BinaryTreeNode *e = BinaryTreeNode_init(6);
    BinaryTreeNode *f = BinaryTreeNode_setLeft(e, BinaryTreeNode_init(5));
    BinaryTreeNode *g = BinaryTreeNode_setRight(f, BinaryTreeNode_init(11));

    BinaryTreeNode *h = BinaryTreeNode_init(7);
    BinaryTreeNode *i = BinaryTreeNode_setLeft(h, BinaryTreeNode_init(2));
    BinaryTreeNode *j = BinaryTreeNode_setRight(i, g);

    BinaryTreeNode *k = BinaryTreeNode_init(2);
    BinaryTreeNode *l = BinaryTreeNode_setLeft(k, j);
    BinaryTreeNode *root = BinaryTreeNode_setRight(l, d);

    // Now we can print our tree!
    BinaryTreeNode_print(root);
}