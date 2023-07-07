#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef struct {
    int customer_id;
    int arrival_time;
} Call;

typedef struct {
    int front, rear;
    int size;
    Call calls[MAX_QUEUE_SIZE];
} Queue;

Queue* createQ() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->front = queue->size = 0;
    queue->rear = MAX_QUEUE_SIZE - 1;
    return queue;
}

int is_full(Queue* queue) {
    if(queue->size == MAX_QUEUE_SIZE)
        return 1;
    return 0;
}

int is_empty(Queue* queue) {
    if(queue->size == 0)
        return 1;
    return 0;
}

void enqueue(Queue* queue, Call call) {
    if (is_full(queue)==1) {
        printf("Queue is full. Cannot add more calls.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->calls[queue->rear] = call;
    queue->size++;
    printf("Call from customer %d added to queue at time %d.\n", call.customer_id, call.arrival_time);
}

void dequeue(Queue* queue) {
    if (is_empty(queue)==1) {
        printf("Queue is empty. No calls to service.\n");
        return;
    }
    Call call = queue->calls[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;
    printf("Servicing call from customer %d at time %d.\n", call.customer_id, call.arrival_time);
}

int main() {
    Queue* queue = createQ();
    int choice;
    Call call;

    while (1) {
        printf("1. Add call\n");
        printf("2. Service call\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer id: ");
                scanf("%d", &call.customer_id);
                printf("Enter arrival time: ");
                scanf("%d", &call.arrival_time);
                enqueue(queue, call);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}