/**
 * @file list.h
 * 
 * @brief Auto-Resizing List
 * 
 * @author Mason Hart
 *
 * Automatically resizing list
 */

#ifndef LIST_H
#define LIST_H

#define LIST_SIZE_REFACTOR 2              // factor by which the list resizes
#define MINIMUM_LIST_SIZE_FOR_SHRINK 10   // if the list has this many items, it won't shrink

typedef struct {
    int length;   // number of items in the list
    int maxSize;  // maximum number of items that can fit before resizing
    int elementSize; // size of a single element in the list
    int* data;   // pointer to the data
} list;


/**
 * initialize an empty list L, with an expected SIZE number of elements of size ELEMENTSIZE
 */
int initList(list *l, int size, int elementSize);

/**
 *  returns the element at INDEX of LIST
 */
int getFromList(list *list, int index);

/** 
 * adds the given ELEMENT to the end of LIST
 */
int addToList(list *list, int element);

/** 
 * adds the given ELEMENT to LIST at INDEX
 */
int addToListAtIndex(list *list, int element, int index);

/** 
 * add all elements of LIST2 to the end of LIST1
 */
int addAllToList(list *list1, list *list2);

/**
 *  add all elements of LIST2 to LIST1 at INDEX
 */
int addAllToListAtIndex(list *list1, list *list2, int index);

/**
 *  set the item from LIST at INDEX to ELEMENT, return the replaced element
 */
int setInList(list *list, int element, int index);

/**
 *  remove the element at INDEX from LIST, return the removed element
 */
int removeFromList(list *list, int index);

/**
 *  clears all items from the LIST
 */
int removeAllFromList(list *list);

/** 
 *  removes all items from LIST, starting at INDEX
 */
int removeAllFromListAtIndex(list *list, int index);

/**
 *  returns the index of the ELEMENT if it is found, if not returns -1
 */
int listIndexOf(list *list, int element);

/**
 *  returns 1 if the element is found, 0 otherwise
 */
int containedInList(list *list, int element);

/**
 *  prints the LIST
 */
void printList(list *list);

/**
 *  prints the LIST verbose
 */
void printListDebug(list *list);



#endif