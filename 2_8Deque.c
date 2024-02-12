// Write a c program to implement Deque.

#include <stdio.h>
#include <conio.h>
#define MAXSIZE 5
int deque[MAXSIZE];
int front = -1, rear = -1;
void insertFront(int);
void insertRear(int);
void deleteFront();
void deleteRear();
void display();
int main() {
    int choice, num;
    do {
        printf("\n1. Insert at Front");
        printf("\n2. Insert at Rear");
        printf("\n3. Delete from Front");
        printf("\n4. Delete from Rear");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert at front: ");
                scanf("%d", &num);
                insertFront(num);
                break;
            case 2:
                printf("Enter the element to insert at rear: ");
                scanf("%d", &num);
                insertRear(num);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);
    getch();
    return 0;
}
void insertFront(int num) {
    if ((front == 0 && rear == MAXSIZE - 1) || (front == rear + 1)) {
        printf("Deque is full. Cannot insert.\n");
    } else {
        if (front == -1)
            front = rear = 0;
        else if (front == 0)
            front = MAXSIZE - 1;
        else
            front--;
        deque[front] = num;
        printf("Element %d inserted at front.\n", num);
    }
}
void insertRear(int num) {
    if ((front == 0 && rear == MAXSIZE - 1) || (front == rear + 1)) {
        printf("Deque is full. Cannot insert.\n");
    } else {
        if (front == -1)
            front = rear = 0;
        else if (rear == MAXSIZE - 1)
            rear = 0;
        else
            rear++;
        deque[rear] = num;
        printf("Element %d inserted at rear.\n", num);
    }
}
void deleteFront() {
    if (front == -1) {
        printf("Deque is empty. Cannot delete from front.\n");
    } else {
        printf("Deleted element from front: %d\n", deque[front]);
        if (front == rear)
            front = rear = -1;
        else if (front == MAXSIZE - 1)
            front = 0;
        else
            front++;
    }
}
void deleteRear() {
    if (front == -1) {
        printf("Deque is empty. Cannot delete from rear.\n");
    } else {
        printf("Deleted element from rear: %d\n", deque[rear]);

        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = MAXSIZE - 1;
        else
            rear--;
    }
}
void display() {
    int i;
    if (front == -1) {
        printf("Deque is empty.\n");
    } else {
        printf("Elements in the Deque: ");
        if (front <= rear) {
            for (i = front; i <= rear; i++)
                printf("%d ", deque[i]);
        } else {
            for (i = front; i < MAXSIZE; i++)
                printf("%d ", deque[i]);
            for (i = 0; i <= rear; i++)
                printf("%d ", deque[i]);
        }
        printf("\n");
    }
}
