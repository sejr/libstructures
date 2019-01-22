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
    assert(list->head->data == 1);
    assert(list->tail->data == 2);

    // Can append LinkedListNode to LinkedList
    LinkedList *newList = LinkedList_append(list, LinkedListNode_init(3));
    assert(newList->length == 3);
    assert(newList->head->data == 1);
    assert(newList->tail->data == 3);

    // Create anotehr list for testing!
    LinkedList *anotherList = LinkedList_append(list, LinkedListNode_init(3));
    assert(anotherList->length == 3);
    assert(anotherList->head->data == 1);
    assert(anotherList->tail->data == 3);

    // Now we can check equality between two lists!
    assert(newList != anotherList);
    assert(LinkedList_equals(newList, anotherList) == 1);

    // Can pass a function into LinkedList_forEach. This is similar to a
    // functional `map` statement, but we can't return anything at this point.
    LinkedList_forEach(newList, printNode);
    LinkedList_forEachReverse(anotherList, printNode);
}