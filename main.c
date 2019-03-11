#include <stdio.h>
#include "queue.h"

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
