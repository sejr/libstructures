# libstructures

> Safe, portable data structures in C

## Motivation

The goal is to provide a safe interface for interacting with data structures you are likely to encounter in an introductory course.

## Data Structures

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
    int data = 1;
    LinkedListNode *node = LinkedListNode_init(data);
    LinkedList *list = LinkedList_init(node);
    assert(list->length == 1);
    assert(list->head->data == 1);
    assert(list->tail->data == 1);

    LinkedList_append(list, LinkedListNode_init(2));
    assert(list->length == 2);
    assert(list->head->data == 1);
    assert(list->tail->data == 2);
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
    BinaryTreeNode *root = BinaryTreeNode_init(1);
    root->left = BinaryTreeNode_init(2);
    root->right = BinaryTreeNode_init(3);
    root->right->right = BinaryTreeNode_init(4);
    root->right->right->left = BinaryTreeNode_init(5);

    // Prints the binary tree in human-readable format
    BinaryTreeNode_print(root);
}
```
