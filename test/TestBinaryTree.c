#include <stdio.h>
#include <assert.h>
#include "../libstructures/BinaryTree.h"

void printSingleNode(BinaryTreeNode *node)
{
    printf("BinaryTreeNode { address: %p, data: %d }\n", node, node->data);
}

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

    // Alternatively...
    BinaryTreeNode *anotherRoot = BinaryTreeNode_setRight(
        BinaryTreeNode_setLeft(
            BinaryTreeNode_init(2),
            BinaryTreeNode_setRight(
                BinaryTreeNode_setLeft(
                    BinaryTreeNode_init(7),
                    BinaryTreeNode_init(2)),
                BinaryTreeNode_setRight(
                    BinaryTreeNode_setLeft(
                        BinaryTreeNode_init(6),
                        BinaryTreeNode_init(5)),
                    BinaryTreeNode_init(11)))),
        BinaryTreeNode_setRight(
            BinaryTreeNode_init(5),
            BinaryTreeNode_setLeft(
                BinaryTreeNode_init(9),
                BinaryTreeNode_init(4))));

    // Now we can print our tree!
    // BinaryTreeNode_print(anotherRoot);

    // And check for equality:
    assert(root != anotherRoot);
    assert(BinaryTreeNode_equals(root, anotherRoot) == 1);

    // Easily get tree height from perspective of any node
    assert(BinaryTreeNode_height(root) == 4);

    // Traversal APIs as you would expect
    printf("\nPRE-ORDER TRAVERSAL:\n");
    BinaryTreeNode_preorderTraversal(root, printSingleNode);

    printf("\nIN-ORDER TRAVERSAL:\n");
    BinaryTreeNode_inorderTraversal(root, printSingleNode);

    printf("\nPOST-ORDER TRAVERSAL:\n");
    BinaryTreeNode_postorderTraversal(root, printSingleNode);
}