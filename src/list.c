/**
 * List implementation in C
 * For now, only capable of storing integers
 * 
 * @author Mason Hart
*/

#include <stdio.h>
#include <memory.h>
#include <string.h>
#include "list.h"




// initialize an empty list L, with an expected SIZE number of elements of size ELEMENTSIZE
int initList(list *l, int size, int elementSize){
    l->length = 0;
    l->elementSize = elementSize;
    l->maxSize = size * LIST_SIZE_REFACTOR;
    l->maxSize = l->maxSize >= 2 ? l->maxSize : 2;  // make sure maxSize >= 2
    l->data = calloc(l->maxSize, elementSize);
    // check if memory allocation was successful
    if(l->data == NULL){
        return 0;
    } else {
        return 1;
    }
}

// returns the element at INDEX of LIST
int getFromList(list *list, int index){
    if(index < 0 || index >= list->length){
        return NULL;  // index out of bounds
    }
    return list->data[index];
}

// adds the given ELEMENT to the end of LIST
int addToList(list *list, int element){
    return addToListAtIndex(list, element, list->length);
}

// adds the given ELEMENT to LIST at INDEX
int addToListAtIndex(list *list, int element, int index){
    // check bounds
    if(index < 0 || index > list->length){
        return 0;
    }
    // check for resize
    if(list->length >= list->maxSize){
        list->maxSize *= LIST_SIZE_REFACTOR;
        list->data = realloc(list->data, list->maxSize * list->elementSize);
    }
    // check for successful memory reallocation
    if(list->data == NULL){
        return 0;
    }
    // move elements as necessary and insert the new element
    int tempLeft = list->data[index];
    for(int i = index; i < list->length; i++){
        int tempRight = list->data[i+1];
        list->data[i+1] = tempLeft;
        tempLeft = tempRight;
    }
    list->data[index] = element;
    list->length++;
    return 1;
}

// add all elements of LIST2 to the end of LIST1
int addAllToList(list *list1, list *list2){
    return addAllToListAtIndex(list1, list2, list1->length);
}

// add all elements of LIST2 to LIST1 at INDEX
int addAllToListAtIndex(list *list1, list *list2, int index){
    // check bounds
    if(index < 0 || index > list1->length){
        return 0;
    }
    // check for resize
    int combinedLength = list1->length + list2->length;
    if(combinedLength >= list1->maxSize){
        list1->maxSize = combinedLength * LIST_SIZE_REFACTOR;
        list1->data = realloc(list1->data, list1->maxSize * list1->elementSize);
    }
    // check for successful memory reallocation
    if(list1->data == NULL){
        return 0;
    }
    // add the list
    for(int i = 0; i < list2->length; i++){
        addToListAtIndex(list1, list2->data[i], index+i);
    }
    list1->length = combinedLength;
    return 1;
}

// set the item from LIST at INDEX to ELEMENT, return the replaced element
int setInList(list *list, int element, int index){
    // check bounds
    if(index < 0 || index > list->length){
        return NULL;
    }
    int returnVal = list->data[index];
    list->data[index] = element;
    return returnVal;
}

// remove the element at INDEX from LIST, return the removed element
int removeFromList(list *list, int index){
    // check bounds
    if(index < 0 || index >= list->length){
        return NULL;
    }
    // remove the element, moving items as needed
    int returnVal = list->data[index];
    for(int i = index; i < list->length-1; i++){
        list->data[i] = list->data[i+1];
    }
    list->length--;
    // check for array resize
    if(list->length < list->maxSize / LIST_SIZE_REFACTOR){
        list->maxSize /= LIST_SIZE_REFACTOR;
        // make sure the list isn't shrinking too much
        list->maxSize = list->maxSize > MINIMUM_LIST_SIZE_FOR_SHRINK ? list->maxSize : MINIMUM_LIST_SIZE_FOR_SHRINK;
        list->data = realloc(list->data, list->maxSize * list->elementSize);
    }
    return returnVal;
}

// clears all items from the LIST
int removeAllFromList(list *list){
    return removeAllFromListAtIndex(list, 0);
}

// removes all items from LIST, starting at INDEX
int removeAllFromListAtIndex(list *list, int index){
    // check bounds
    if(index < 0 || index >= list->length){
        return 0;
    }
    // remove items from the list
    int removeCount = 0;
    for(int i = index; i < list->length; i++){
        removeFromList(list, index);
        removeCount++;
    }
    list->length -= removeCount;
    return 1;
}

// returns the index of the ELEMENT if it is found, if not returns -1
int listIndexOf(list *list, int element){
    for(int i = 0; i < list->length; i++){
        if(list->data[i] == element){
            return i;
        }
    }
    return -1; // not contained in list
}

// returns 1 if the element is found, 0 otherwise
int containedInList(list *list, int element){
    return listIndexOf(list, element) == -1 ? 0 : 1;
}

// prints the LIST
void printList(list *list){
    if(list->length){
        printf("[");
        for(int i = 0; i < list->length-1; i++){
            printf("%d, ", list->data[i]);
        }
        printf("%d]\n", list->data[list->length-1]);
    } else{
        printf("[]\n");
    }
}

// prints the LIST verbose
void printListDebug(list *list){
    printf(
        "-----------------LIST DEBUG-----------------\n"
        "Cap:  %d  /  %d   (%.2f\%)\n"
        "Size:  %d per element  (%lu bytes total)\n",
        list->length, list->maxSize, 100 * (float)list->length / list->maxSize,
        list->elementSize, list->elementSize * list->maxSize
    );
    printList(list);
    printf("--------------------------------------------\n");
}
