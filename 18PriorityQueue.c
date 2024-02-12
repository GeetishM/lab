// Write a c program to implement Priority Queue.

#include <stdio.h>
#include <conio.h>
#define MAXSIZE 5
struct PriorityQueue {
    int data[MAXSIZE];
    int priority[MAXSIZE];
    int front;
    int rear;
};
void enqueue(struct PriorityQueue *pq, int item, int prio);
void dequeue(struct PriorityQueue *pq);
void display(struct PriorityQueue pq);
int main() {
    struct PriorityQueue pq;
    pq.front = pq.rear = -1;
    int choice, item, prio;
    do {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                printf("Enter the priority: ");
                scanf("%d", &prio);
                enqueue(&pq, item, prio);
                break;
            case 2:
                dequeue(&pq);
                break;
            case 3:
                display(pq);
                break;
            case 4:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    getch();
    return 0;
}
void enqueue(struct PriorityQueue *pq, int item, int prio) {
    if (pq->rear == MAXSIZE - 1) {
        printf("Priority Queue is full. Cannot enqueue.\n");
    } else {
        int i;
        for (i = pq->rear; i >= 0 && prio > pq->priority[i]; i--) {
            pq->data[i + 1] = pq->data[i];
            pq->priority[i + 1] = pq->priority[i];
        }
        pq->data[i + 1] = item;
        pq->priority[i + 1] = prio;
        pq->rear++;
        if (pq->front == -1) {
            pq->front = 0;
        }
        printf("Element %d with priority %d enqueued.\n", item, prio);
    }
}
void dequeue(struct PriorityQueue *pq) {
    if (pq->front == -1) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
    } else {
        int item = pq->data[pq->front];
        int prio = pq->priority[pq->front];
        pq->front++;
        if (pq->front > pq->rear) {
            pq->front = pq->rear = -1;
        }
        printf("Dequeued element %d with priority %d.\n", item, prio);
    }
}
void display(struct PriorityQueue pq) {
    if (pq.front == -1) {
        printf("Priority Queue is empty.\n");
    } else {
        printf("Priority Queue elements:\n");
        for (int i = pq.front; i <= pq.rear; i++) {
            printf("Element: %d, Priority: %d\n", pq.data[i], pq.priority[i]);
        }
    }
}
