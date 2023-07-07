#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

struct process{
    int process_id;
    double burst_time;
};
typedef struct process Process;

struct queue{
    int front, rear;
    int size;
    Process processes[MAX_QUEUE_SIZE];
};
typedef struct queue* Queue;

Queue create_queue() {
    Queue queue = (Queue) malloc(sizeof(struct queue));
    queue->front = queue->size = 0;
    queue->rear = MAX_QUEUE_SIZE - 1;
    return queue;
}

int is_full(Queue queue) {
    if(queue->size == MAX_QUEUE_SIZE)
        return 1;
    return 0;
}

int is_empty(Queue queue) {
    if(queue->size == 0)
        return 1;
    return 0;
}

void enqueue(Queue queue, Process process) {
    if (is_full(queue)==1) {
        printf("Queue is full. Cannot add more processes.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->processes[queue->rear] = process;
    queue->size++;
    printf("Process %d added to queue with burst time %lf.\n", process.process_id, process.burst_time);
}

void dequeue(Queue queue) {
    if (is_empty(queue)==1) {
        printf("Queue is empty. No processes to run.\n");
        return;
    }
    Process process = queue->processes[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;
    printf("Process %d remmoved from queue with burst time %lf\n", process.process_id, process.burst_time);
}

void display(Queue queue) {
    printf("Processes in queue: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->processes[i].process_id);
    }
    printf("\n");
}

void main(){
    Queue queue = create_queue();
    int choice;
    Process p;

    while (1) {
        printf("1. Add process\n");
        printf("2. Run process\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter process id: ");
                scanf("%d", &p.process_id);
                printf("Enter burst time: ");
                scanf("%lf", &p.burst_time);
                enqueue(queue,p);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:display(queue);
                    break;
            case 4:exit(0);
                    break;
            default:
                printf("Invalid choice\n");
        }
    }
}
