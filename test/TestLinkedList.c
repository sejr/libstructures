#include <stdio.h>
#include <assert.h>
#include "../libstructures/LinkedList.h"

void printNode(LinkedListNode *node)
{
    LinkedListNode_print(node);
    printf("\n");
}

int main()
{
    // Can initialize LinkedListNode
    LinkedListNode *head = LinkedListNode_init(1);
    assert(head != NULL);

    // Can initialize LinkedListNodeOptions
    LinkedListNodeOptions *options = LinkedListNodeOptions_init(2, 0, head);
    assert(options != NULL);

    // Can initialize LinkedListNode from LinkedListNodeOptions
    LinkedListNode *next = LinkedListNode_initWithOptions(options);
    assert(next != NULL);

    // Can get length from LinkedListNode
    int length = LinkedListNode_length(head);
    assert(length == 2);

    // Can initialize LinkedList from LinkedListNode
    LinkedList *list = LinkedList_init(head);
    assert(list->length == 2);

    // Can append LinkedListNode to LinkedList
    LinkedList_append(list, LinkedListNode_init(3));
    assert(list->length == 3);

    // Can pass a function into LinkedList_forEach
    LinkedList_forEach(list, printNode);
}