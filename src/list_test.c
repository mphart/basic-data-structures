#include <stdio.h>
#include <assert.h>
#include "list.h"

int main(){
    // initialize test variables
    list list1;
    list list2;
    list* listptr = &list1;

    // assign the lists
    initList(listptr, 12, sizeof(int));
    for(int i = 0; i < 12; i++){
        addToList(listptr, i);
    }
    initList(&list2, 10, sizeof(int));
    for(int i = 1; i <= 10; i++){
        addToList(&list2, i*i);
    }

    // ---------BEGIN TESTS---------

    printListDebug(listptr);
    // append
    printf("Appending element 0\n");
    addToList(listptr, 0);
    printListDebug(listptr);
    // add at index
    printf("Adding elements 0, 0 at indexes 5, 0\n");
    addToListAtIndex(listptr, 0, 5);
    addToListAtIndex(listptr, 0, 0);
    printListDebug(listptr);
    // get
    assert(getFromList(listptr,5) == 4);
    printf("Element at index 5: %d\n", getFromList(listptr,5));
    // add all
    printf("Appending list 2 to list 1\n");
    addAllToList(listptr, &list2);
    printListDebug(listptr);
    assert(list1.length = list2.length + 15);
    // add all at index
    printf("Inserting list 2 into index 9 of list 1\n");
    addAllToListAtIndex(listptr, &list2, 9);
    printListDebug(listptr);
    assert(list1.length = list2.length + 25);
    // set
    printf("setting index 3 to value -1\n");
    setInList(listptr, -1, 3);
    printListDebug(listptr);
    assert(list1.data[3] == -1);
    // remove
    printf("removing element at index 10\n");
    removeFromList(listptr, 10);
    printListDebug(listptr);
    assert(list1.length == 34);
    // remove all
    printf("Removing all items from list 2\n");
    removeAllFromList(&list2);
    removeAllFromList(&list2);
    printListDebug(&list2);
    assert(list2.length == 0);
    // remove all at index
    printf("Removing all items from list 1 from index 10 on\n");
    removeAllFromListAtIndex(listptr, 8);
    printListDebug(listptr);
    assert(listptr->length == 8);
    // index of
    int indexOfZero = listIndexOf(listptr, 0);
    int indexOfTwenty = listIndexOf(listptr, 20);
    assert(indexOfZero == 0);
    assert(indexOfTwenty == -1);
    // contains
    assert(!containedInList(listptr, 20));

    // ---------END OF TESTS---------

    free(list1.data);
    free(list2.data);
    listptr = NULL;
    return 0;
}