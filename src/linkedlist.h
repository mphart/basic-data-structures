/**
 * @file list.h
 * 
 * @brief Doubly-Linked List
 * 
 * @author Mason Hart
 *
 * List with each element having a pointer to the 
 * memory address of the next and previous elements in
 * memory.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H


typedef struct node node;
struct node {
    node* prev;    // the previous node in the list
    node* next;    // the next node in the list
    int payload;   // the value of this node
};

typedef struct{
    node* head;     // pointer to the first element in the list
    node* tail;     // pointer to the last element in the list
    int length;     // number of elements in the list
    int elementSize;  // size of a single element
} linkedlist;


// initialize the linked list
int initLinkedList(linkedlist *ll);

// gets the element at INDEX from LIST
int getFromLinkedList(linkedlist *list, int index);

// add ELEMENT to the end of the LIST
int addToLinkedList(linkedlist *list, int element);

// add an item at INDEX of LIST
int addToLinkedListAtIndex(linkedlist *list, int element, int index);

// append list2 to list1
int addAllToLinkedList(linkedlist *list1, linkedlist *list2);

// add list2 at INDEX of list1
int addAllToLinkedListAtIndex(linkedlist *list1, linkedlist *list2, int index);
// prints the linked list
void printLinkedList(linkedlist *ll);

// prints the linked list verbose
void printLinkedListDebug(linkedlist *ll);


#endif