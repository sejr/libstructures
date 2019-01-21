# libstructures

## Motivation

The goal here is to provide a library of common data structures that is easy to ramp up productivity and difficult to use incorrectly. You should probably avoid using the library at this point because there's nothing here, and the stuff that *is* here is poorly (if at all) tested.

That said, you're welcome to submit Issues and Pull Requests to help improve the quality of this library.

## Data Structures

### LinkedList

A linked list is a very simple structure with two primary components; some `data` associated with a linked list node, and a pointer to the address of the `next` node in the list. This is the foundation for many other data structures.

<p align="center">
    <img src="https://upload.wikimedia.org/wikipedia/commons/6/6d/Singly-linked-list.svg">
</p>

This library provides a bare-bones `LinkedListNode` structure, as well as a wrapper, `LinkedList`, that offers additional functionality (at the cost of requiring additional space). For example, when calculating the length of a linked list, you typically have to iterate through every element in the list and increment some counter. 

This is true with `LinkedListNode`, but with `LinkedList`, we retain a `length` data member and update it any time a node is inserted or removed. Thus, the time complexity required to calculate the list length goes from `O(n)` to `O(1)`.

```c
int main() {
    int data = 1;
    LinkedListNode *node = LinkedListNode_init(data);
    LinkedListNode_print(node); // Node { data: 1, next: 0x0 }
    
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
