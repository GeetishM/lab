// Write a c program to reverse a string using stack.

#include <stdio.h>
#include <conio.h>
#define Max 20

struct {
    int top;
    char a[Max];
} typedef stack;

void push(stack *, char);
char pop(stack *);

int main() {
    stack s;
    char c;
    char a[Max];
    //clrscr();
    s.top = -1;

    printf("Enter a string: ");
    scanf("%s", a);

    int i = 0;
    while (a[i] != '\0') {
        push(&s, a[i]);
        i++;
    }
    printf("Reversed string: ");
    while ((c = pop(&s)) != -1) {
        printf("%c", c);
    }
    return 0;
}

void push(stack *s, char ele) {
    if (s->top == Max - 1) {
        printf("Overflow");
        return;
    }
    s->top = s->top + 1;
    s->a[s->top] = ele;
}

char pop(stack *s) {
    if (s->top == -1)
        return -1;
    char t = s->a[s->top];
    s->top = s->top - 1;
    return t;
}
