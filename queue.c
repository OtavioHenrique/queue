#include <stdio.h>
#include <stdlib.h>
#define finalAdvance(i) (i = (i+1) % queue->max)

typedef int dataType;

typedef struct queue {
    int max;
    int total;
    int begin;
    int final;
    dataType *items;
} *Queue;

Queue startQueue(int max) {
    Queue newQueue = malloc(sizeof(Queue));
    newQueue->max = max;
    newQueue->total = 0;
    newQueue->begin = 0;
    newQueue->final = 0;
    newQueue->items = malloc(max * sizeof(dataType));

    return newQueue;
}

int isEmpty(Queue queue) {
    if(queue->total == 0) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(Queue queue) {
    if(queue->total == queue->max) {
        return 1;
    } else {
        return 0;
    }
}

int insertItem(Queue queue, dataType newData) {
    if(isFull(queue)) {
        puts("The queue is full.");
        abort();
    }

    queue->items[queue->final] = newData;
    finalAdvance(queue->final);
    queue->total++;
}

int removeItem(Queue queue) {
    if(isEmpty(queue)) {
        puts("The queue is empty");
        abort();
    }

    dataType removedItem = queue->items[queue->final];
    finalAdvance(queue->begin);
    queue->total--;
    return removedItem;
}

void destroyQueue(Queue *queue) {
    free((*queue)->items);
    free(*queue);
    *queue = NULL;
}

int main(void) {
    int maxItems = 3;
    Queue queue = startQueue(maxItems);

    printf("Is empty: %d\n", isEmpty(queue));
    printf("Is full: %d\n", isFull(queue));

    printf("Inserting item 1...\n");
    insertItem(queue, 1);

    printf("Is empty: %d\n", isEmpty(queue));
    printf("Is full: %d\n", isFull(queue));

    printf("Inserting item 2...\n");
    insertItem(queue, 2);

    printf("Inserting item 3...\n");
    insertItem(queue, 3);

    printf("Is empty: %d\n", isEmpty(queue));
    printf("Is full: %d\n", isFull(queue));

    dataType removedItem = removeItem(queue);
    printf("Removed item: %i\n", removedItem);

    printf("Is empty: %d\n", isEmpty(queue));
    printf("Is full: %d\n", isFull(queue));

    printf("Removing all items...\n");
    removeItem(queue);
    removeItem(queue);

    printf("Is empty: %d\n", isEmpty(queue));
    printf("Is full: %d\n", isFull(queue));

    destroyQueue(&queue);
}
