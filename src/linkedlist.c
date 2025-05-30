/**
 * Linked List implementation in C
 * For now, only contains ints
 * 
 * @author Mason Hart
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>


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

#ifdef LINKED_LIST_TEST
int main(){

    linkedlist ll;
    linkedlist* llptr = &ll;

    for(int i = 0; i < 12; i++){
        addToLinkedList(llptr, i);
    }

    printLinkedListDebug(llptr);


    return 0;
}
#endif

// initialize the linked list
int initLinkedList(linkedlist *ll){
    ll->head = NULL;
    ll->tail = NULL;
    ll->length = 0;
    ll->elementSize = sizeof(node);
}

// gets the element at INDEX from LIST
int getFromLinkedList(linkedlist *list, int index){
    // check bounds
    if(index < 0 || index > list->length){
        return NULL; // index out of bounds
    }
    // use fastest path
    node* current;
    if(index < list->length / 2){
        current = list->head;
        for(int i = 0; i < index; i++){
            current = current->next;
        }
    } else {
        current = list->tail;
        for(int i = list->length-1; i > index; i--){
            current = current->prev;
        }
    }
    return current->payload;
}

// add ELEMENT to the end of the LIST
int addToLinkedList(linkedlist *list, int element){
    // create new node
    node *newNode = malloc(list->elementSize);
    newNode->payload = element;
    // edge case: head is null (list is empty)
    if(list->head == NULL){
        list->head = malloc(list->elementSize);
        list->head->payload = element;
        list->tail = list->tail;
    } // list has one element (head == tail)
    else if(list->tail->prev == NULL){
        list->tail = newNode;
        list->head->next = list->tail;
        list->tail->prev = list->head;
    } // list has at least two elements
    else {
        list->tail->prev->next = list->tail;
        list->tail = newNode;
    }
    list->length++;
    return 1;
}

// add an item at INDEX of LIST
int addToLinkedListAtIndex(linkedlist *list, int element, int index){

}

// append list2 to list1
int addAllToLinkedList(linkedlist *list1, linkedlist *list2){

}

// add list2 at INDEX of list1
int addAllToLinkedListAtIndex(linkedlist *list1, linkedlist *list2, int index){

}

// prints the linked list
void printLinkedList(linkedlist *ll){
    if(ll->length > 0){
        printf("[");
        node* current = ll->head;
        for(int i = 0; i < ll->length-1; i++){
            printf("%d, ", current->payload);
            current = current->next;
        }
        printf("%d]\n", ll->tail->payload);
    } else {
        printf("[]\n");
    }
}

// prints the linked list verbose
void printLinkedListDebug(linkedlist *ll){
    printf(
        "----------LINKED LIST----------"
        "HEAD: %d  next: %d  prev: %d"
        "TAIL: %d  next: %d  prev: %d",
        ll->head->payload, ll->head->next->payload, ll->head->prev->payload,
        ll->tail->payload, ll->tail->next->payload, ll->tail->prev->payload
    );
    printLinkedList(ll);
    printf("-------------------------------");
}