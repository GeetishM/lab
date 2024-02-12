/* Write a C program to create polynomial representation using linked list and also input the value of variable x and find the value of polynomial. */

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct Node {
    float coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(float coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

struct Node* createPolynomial() {
    struct Node* head = NULL;
    struct Node* current = NULL;

    int n;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        float coeff;
        int exp;

        printf("Enter coefficient for term %d: ", i + 1);
        scanf("%f", &coeff);

        printf("Enter exponent for term %d: ", i + 1);
        scanf("%d", &exp);

        struct Node* newNode = createNode(coeff, exp);

        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

float evaluatePolynomial(struct Node* poly, float x) {
    float result = 0.0;

    while (poly != NULL) {
        result += poly->coeff * pow(x, poly->exp);
        poly = poly->next;
    }

    return result;
}

void displayPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%.2fx^%d", poly->coeff, poly->exp);

        if (poly->next != NULL) {
            printf(" + ");
        }

        poly = poly->next;
    }

    printf("\n");
}

int main() {
    struct Node* polynomial = createPolynomial();

    printf("\nPolynomial entered: ");
    displayPolynomial(polynomial);

    float x;
    printf("\nEnter the value of variable x: ");
    scanf("%f", &x);

    float result = evaluatePolynomial(polynomial, x);

    printf("\nThe value of the polynomial for x = %.2f is: %.2f\n", x, result);

    return 0;
}

