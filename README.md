<p align="center">
    <img src="./assets/logo.svg" height="50px">
</p>

## Motivation

**libstructures** is a modern library that implements common data structures. Our goal is to help developers build safer systems in C by making the library easy to learn and difficult to misuse. At this point in time, however, this library is not production ready.

You are welcome to submit Issues and Pull Requests to help improve the quality of this library.

___

## Data Structures

### Overview

For each data structure, we provide an immutable implementation as well as a mutable one. By default (i.e. by convenience), all data structures are immutable. For example, `LinkedList` is an immutable linked list, and `MutableLinkedList`, as its name implies, is mutable. Each collection structure (e.g. `LinkedList`, `BinaryTree`, `Graph`) also has its own Node structure, which can be immutable or (by appending the `Mutable` prefix) mutable.

### LinkedList

A linked list is a very simple structure with two primary components; some `data` associated with a linked list node, and a pointer to the address of the `next` node in the list. This is the foundation for many other data structures.

<p align="center">
    <img src="https://upload.wikimedia.org/wikipedia/commons/6/6d/Singly-linked-list.svg">
</p>

This library provides a bare-bones `LinkedListNode` structure, as well as a wrapper, `LinkedList`, that offers additional functionality (at the cost of requiring additional space). For example, when calculating the length of a linked list, you typically have to iterate through every element in the list and increment some counter.

This is true with `LinkedListNode`, but with `LinkedList`, we retain a `length` data member and update it any time a node is inserted or removed. Thus, the time complexity required to calculate the list length goes from `O(n)` to `O(1)`.

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

    LinkedList_append(list, LinkedListNode_init(99));
    assert(list->length == 2);
    assert(list->head->data == 12);
    assert(list->tail->data == 99);

    LinkedList_append(list, LinkedListNode_init(37));
    assert(list->length == 3);
    assert(list->head->data == 12);
    assert(list->tail->data == 37);
}
```

### Binary Tree

A binary tree is similar to a linked list, except that instead of a single `next` pointer,
a binary tree instead has two logical children, which are its `left` and `right` nodes.

<p align="center">
    <img src="https://upload.wikimedia.org/wikipedia/commons/f/f7/Binary_tree.svg">
</p>

The top-level node, which has no _parent_, is known as the root node. If a node has no
children, then it is known as a _leaf_ node.

```c
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
```
