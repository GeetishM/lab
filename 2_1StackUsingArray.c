// Write a c program to implement a stack using array.

#include <stdio.h>
#include <conio.h>

#define MAX 20

int top, status;

void push(int stack[], int item) {
    if (top == (MAX - 1))
        status = 0;
    else {
        status = 1;
        ++top;
        stack[top] = item;
    }
}

int pop(int stack[]) {
    int ret;
    if (top == -1) {
        ret = 0;
        status = 0;
    } else {
        status = 1;
        ret = stack[top];
        --top;
    }
    return ret;
}

void display(int stack[]) {
    int i;
    printf("\nThe Stack is: ");
    if (top == -1)
        printf("empty");
    else {
        for (i = top; i >= 0; i--)
            printf("\n|%3d |", stack[i]);
    }
    printf("\n");
}

int main() {
    int stack[MAX], item, ch;
    //clrscr();
    top = -1;

    do {
        do {
            printf("\nMAIN MENU");
            printf("\n1. PUSH (Insert) in the Stack");
            printf("\n2. POP (Delete) from the Stack");
            printf("\n3. Exit (End the Execution)");
            printf("\nEnter Your Choice: ");
            scanf("%d", &ch);
            if(ch < 1 || ch > 3)
            printf("\nInvalid choice! Please enter a valid option!");
        } while (ch < 1 || ch > 3);

        switch (ch) {
            case 1:
                printf("\nEnter the Element to be pushed: ");
                scanf("%d", &item);
                push(stack, item);
                if (status) {
                    printf("\nAfter Pushing ");
                    display(stack);
                    if (top == (MAX - 1))
                        printf("\nThe Stack is Full");
                } else
                    printf("\nStack overflow on Push");
                break;

            case 2:
                item = pop(stack);
                if (status) {
                    printf("\nThe Popped item is %d. After Popping: ", item);
                    display(stack);
                } else
                    printf("\nStack underflow on Pop");
                break;

            case 3:
                printf("\nEND OF EXECUTION");
                break;
        }
    } while (ch != 3);

    getch();
    return 0;
}

