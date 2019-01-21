#include <stdio.h>
#include "../libstructures/LinkedList.h"

void printNode(LinkedListNode *node)
{
    LinkedListNode_print(node);
    printf("\n");
}

int main()
{
    printf("Initializing node\n");
    LinkedListNode *head = LinkedListNode_init(1);

    printf("Initializing options\n");
    LinkedListNodeOptions *options = LinkedListNodeOptions_init(2, 0, head);

    printf("Initializing another node\n");
    LinkedListNode *next = LinkedListNode_initWithOptions(options);

    printf("List length: %d\n", LinkedListNode_length(head));

    printf("Creating LinkedList\n");
    LinkedList *list = LinkedList_init(head);
    printf("LinkedList length: %d\n", list->length);

    printf("Appending a list node\n");
    LinkedList_append(list, LinkedListNode_init(3));
    printf("LinkedList length: %d\n", list->length);

    printf("Testing forEach\n");
    LinkedList_forEach(list, printNode);
}