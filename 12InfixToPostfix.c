// Write a c program to convert a infix expression to postfix using stack.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXSIZE 100

struct Stack {
    int top;
    char items[MAXSIZE];
};

void push(struct Stack *s, char item);
char pop(struct Stack *s);
int isOperator(char ch);
int precedence(char op);
void infixToPostfix(char infix[], char postfix[]);

int main() {
    char infix[MAXSIZE], postfix[MAXSIZE];

    printf("Enter the infix expression: ");
    fgets(infix, MAXSIZE, stdin);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

void push(struct Stack *s, char item) {
    if (s->top == MAXSIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++s->top] = item;
}

char pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return '\0'; // Return a default value or handle the underflow condition appropriately
    }
    return s->items[s->top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '$');
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
        case '$':
            return 3; // Highest precedence
        default:
            return -1; // For operands
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack stack;
    stack.top = -1;

    int i, j;
    char ch;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (stack.top != -1 && stack.items[stack.top] != '(') {
                postfix[j++] = pop(&stack);
            }

            if (stack.top == -1) {
                printf("Invalid expression: Unmatched parentheses\n");
                return;
            }

            // Pop the '(' from the stack
            pop(&stack);
        } else if (isOperator(ch)) {
            while (stack.top != -1 && stack.items[stack.top] != '(' &&
                   precedence(stack.items[stack.top]) >= precedence(ch)) {
                postfix[j++] = pop(&stack);
            }

            // If operators have equal precedence, check associativity
            while (stack.top != -1 && stack.items[stack.top] != '(' &&
                   precedence(stack.items[stack.top]) == precedence(ch) &&
                   stack.items[stack.top] != '^' && ch != '^') {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (stack.top != -1) {
        if (stack.items[stack.top] == '(') {
            printf("Invalid expression: Unmatched parentheses\n");
            return;
        }
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}
