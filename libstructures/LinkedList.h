#ifndef LIBSTRUCTURES_LINKEDLIST_H
#define LIBSTRUCTURES_LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Default structure for LinkedListNode.
 */
typedef struct LinkedListNode
{
    int data;
    struct LinkedListNode *next;
} LinkedListNode;

/**
 * @brief Options that can be customized when defining a LinkedListNode.
 * To use this, call `LinkedListNode_initWithOptions`.
 */
typedef struct LinkedListNodeOptions
{
    int data;
    int debug;
    LinkedListNode *parent;
} LinkedListNodeOptions;

/**
 * @brief A container structure representing an entire linked list, which
 * will expose methods for interacting with the list as a whole.
 */
typedef struct LinkedList
{
    int length;
    LinkedListNode *head;
    LinkedListNode *tail;
} LinkedList;

/**
 * @brief Creates a LinkedListNode with provided data.
 * 
 * @param data arbitrary 32-bit data.
 * @return LinkedListNode* newly-created linked list node.
 */
LinkedListNode *LinkedListNode_init(int data)
{
    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    if (node != NULL)
    {
        node->data = data;
        node->next = NULL;
    }
    else
    {
        // If the memory allocation does not succeed, we alert the user.
        fprintf(stderr, "Error allocating memory for LinkedListNode");
    }

    return node;
}

/**
 * @brief Retrieves the length of a linked list starting at the passed node.
 * 
 * @param head LinkedListNode we want to start counting from.
 * @return int Number of nodes after (and including) head.
 */
int LinkedListNode_length(LinkedListNode *head)
{
    int length = 1;
    LinkedListNode *temp = head;
    while (temp->next)
    {
        length += 1;
        temp = temp->next;
    }
    return length;
}

/**
 * @brief Prints a human-readable representation of the LinkedListNode.
 * 
 * @param node the node to be printed
 */
void LinkedListNode_print(LinkedListNode *node)
{
    printf("Node { data: %d, next: %p }", node->data, node->next);
}

/**
 * @brief Creates a LinkedListNode, customized with a variety of different
 * options as specified in the `LinkedListNodeOptions` structure.
 * 
 * @param options 
 * @return LinkedListNode* 
 */
LinkedListNode *LinkedListNode_initWithOptions(LinkedListNodeOptions *options)
{
    LinkedListNode *node = malloc(sizeof(LinkedListNode));
    if (node != NULL)
    {
        // Setting node data.
        node->data = options->data;
        node->next = NULL;

        // If we have indicated that this node is being created in some type
        // of debug mode, then we indicate its successful creation.
        if (options->debug)
        {
            printf("Creation successful: LinkedListNode<%d>", node->data);
        }

        // If a parent node has been provided, we want `parent->next` to point
        // to our newly-created node.
        if (options->parent != NULL)
        {
            LinkedListNode *parent = options->parent;
            parent->next = node;
        }
    }
    else
    {
        // If the memory allocation does not succeed, we alert the user.
        fprintf(stderr, "Error allocating memory for LinkedListNode");
    }

    return node;
}

/**
 * @brief Initializer for the LinkedListNodeOptions type.
 * 
 * @param data Data to be used in the new list node
 * @param debug Whether we need debug printing or not
 * @param parent Optional parent for the new node
 * @return LinkedListNodeOptions* 
 */
LinkedListNodeOptions *LinkedListNodeOptions_init(
    int data,
    int debug,
    LinkedListNode *parent)
{
    LinkedListNodeOptions *options = malloc(sizeof(LinkedListNodeOptions));
    if (options != NULL)
    {
        options->data = data;
        options->debug = debug;
        options->parent = parent;
    }
    else
    {
        // If the memory allocation does not succeed, we alert the user.
        fprintf(stderr, "Error allocating memory for LinkedListNodeOptions");
    }

    return options;
}

LinkedList *LinkedList_init(LinkedListNode *head)
{
    LinkedList *list = malloc(sizeof(LinkedList));
    if (list != NULL)
    {
        int length = LinkedListNode_length(head);
        list->length = length;
        list->head = head;

        // To retrieve the tail of the list we have to iterate through
        // the entire list once.
        LinkedListNode *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        list->tail = temp;
    }
    else
    {
        // If the memory allocation does not succeed, we alert the user.
        fprintf(stderr, "Error allocating memory for LinkedList");
    }

    return list;
}

/**
 * @brief Appends a single node to a LinkedList.
 * 
 * @param list the list to which we are adding a node
 * @param node the node to be added
 * @return int length of the new list
 */
int LinkedList_append(LinkedList *list, LinkedListNode *node)
{
    LinkedListNode *temp = list->tail;
    temp->next = node;
    list->tail = list->tail->next;
    list->length += 1;
    return list->length;
}

/**
 * @brief Calls some function on every element in the LinkedList
 * 
 * @param list the LinkedList to be processed
 * @param fn some function that takes a LinkedListNode and returns void
 */
void LinkedList_forEach(LinkedList *list, void (*fn)(LinkedListNode *))
{
    LinkedListNode *temp = list->head;

    while (temp->next)
    {
        (*fn)(temp);
        temp = temp->next;
    }

    // Don't forget to call the function on the last element in the list!
    (*fn)(temp);
}

#endif