<p align="center">
    <img src="./assets/logo.svg" height="50px">
</p>

## Motivation

> **At this point in time, this library is not production ready.** GitHub Issues and Pull Requests are not just welcome, but encouraged. Thanks for your interest!

**libstructures** is a modern library that provides a suite of common data structures. Our goal is to help developers build safer systems in C by making the library easy to learn and difficult to misuse.

### Primary Goals

- **`libstructures` should be safe.** The header files in this library define *immutable* data structures that should prevent data races in multithreaded C programs.

- **`libstructures` should be portable.** While our target use-case is with low-level systems that require thread-safety, it should be easy to integrate this library with any C project. Every data structure exists within a single C header file. To incorporate these data structures into your project, just copy and paste the header files you need.

- **`libstructures` should be approachable.** As great as this library could be, its safety guarantees are useless if it is used incorrectly. We try to reduce the chance of this happening by explicitly defining APIs for all valid operations. At some point we will investigate ways to introduce compile-time errors when this library is used incorrectly.

---

# Features

For each data structure, we plan to provide an immutable implementation as well as a mutable one. By default (i.e. by convenience), all data structures are immutable. For example, `LinkedList` is an immutable linked list, and `MutableLinkedList`, as its name implies, is mutable. Each collection structure (e.g. `LinkedList`, `BinaryTree`, `Graph`) also has its own Node structure, which can be immutable or (by appending the `Mutable` prefix) mutable.

## Available Data Structures

- [Linked List](#linked-list)
- [Binary Tree](#binary-tree)

---

# Linked List

> A Linked list is a linear collection of data elements, whose order is not given by their physical placement in memory. Instead, each element points to the next. It is a data structure consisting of a collection of nodes which together represent a sequence. In its most basic form, each node contains: data, and a reference (in other words, a link) to the next node in the sequence. This structure allows for efficient insertion or removal of elements from any position in the sequence during iteration. [Wikipedia](https://en.wikipedia.org/wiki/Linked_list)

<p align="center">
    <img src="https://upload.wikimedia.org/wikipedia/commons/6/6d/Singly-linked-list.svg">
</p>

This library provides a bare-bones `LinkedListNode` structure, as well as a wrapper, `LinkedList`, that offers additional functionality (at the cost of requiring additional space). `LinkedListNode` is a simple structure with two primary components: some `data` associated with the node, and a pointer to the address of the `next` node in the list. This is the foundation for many other data structures.

## Usage

```c
int main()
{
    int data = 12;
    LinkedListNode *node = LinkedListNode_init(data);
    LinkedListNode_print(node); // Node { data: 12, next: 0x0 }

    LinkedList *list = LinkedList_init(node);
    assert(list->length == 1);
    assert(list->head->data == 12);
    assert(list->tail->data == 12);

    LinkedList *newList = LinkedList_append(list, LinkedListNode_init(99));
    assert(newList->length == 2);
    assert(newList->head->data == 12);
    assert(newList->tail->data == 99);

    LinkedList *final = LinkedList_append(newList, LinkedListNode_init(37));
    assert(final->length == 3);
    assert(final->head->data == 12);
    assert(final->tail->data == 37);
}
```

# Binary Tree

A binary tree is similar to a linked list, except that instead of a single `next` pointer,
a binary tree instead has two logical children, which are its `left` and `right` nodes.

<p align="center">
    <img src="https://upload.wikimedia.org/wikipedia/commons/f/f7/Binary_tree.svg">
</p>

The top-level node, which has no _parent_, is known as the _root_ node. If a node has no
_children_, then it is known as a _leaf_ node.

## Usage

```c
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
```
