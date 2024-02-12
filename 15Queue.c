//Write a c program to implement Queue using array.

#include <stdio.h>
#include <stdbool.h>
#define max 5
int front, rear, q[max];
void enqueue(void);
void dequeue(void);
void qdisplay(void);
int main(void) {
    int c;
    front = rear = -1;

    do {
        printf("1: Insert\n2: Deletion\n3: Display\n4: Exit\nEnter choice: ");
        scanf("%d", &c);

        switch (c) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                qdisplay();
                break;
            case 4:
                printf("Program ends\n");
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
    } while (c != 4);

    return 0;
}

void enqueue(void) {
    int x;
    if ((front == 0 && rear == max - 1) || (front == rear + 1)) {
        printf("Queue is overflow\n");
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        if (rear == max - 1) {
            rear = 0;
        } else {
            rear++;
        }
    }

    printf("Enter the number: ");
    scanf("%d", &x);
    q[rear] = x;

    printf("%d successfully inserted\n", x);
}

void dequeue(void) {
    int y;

    if (front == -1) {
        printf("Queue is underflow\n");
        return;
    }

    y = q[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        if (front == max - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    printf("%d successfully deleted\n", y);
}

void qdisplay(void) {
    int i, j;

    if (front == rear && front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements are:\n");

    for (i = front; i != rear; i = (i + 1) % max) {
        printf("%d\n", q[i]);
    }

    printf("%d \n", q[rear]);
}
