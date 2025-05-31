/**
 * FIFO Queue implementation in C
 * Uses an array as an implementation
 * 
 * @author Mason Hart
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

const QUEUE_SIZE_REFACTOR = 2;

typedef struct {
    int maxSize;   // maximum size of the queue before resizing
    int length;    // number of elements in the queue
    int* data;    // array of the elements
    int elementSize;  // size of a single element
} queue;


// initialize the queue to allocate ELEMENTSIZE * 
int initQueue(queue *q, int initSize, int elementSize){
    q->maxSize = initSize;
    q->elementSize = elementSize;
    q->length = 0;
    q->data = malloc(elementSize * q->maxSize);
}

int addToQueue(queue *q, int element){
    
}