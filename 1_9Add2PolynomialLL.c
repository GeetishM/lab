/* Write a C program to add 2 polynomials using linked list. */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct rec
{
    float coeff;
    int exp;
    struct rec *next;
};

struct rec *rear;

int select();
struct rec *create(struct rec *list);
void *add(struct rec *first, struct rec *second);
struct rec *insert(double coeff, int exp, struct rec *rear);
void *display(struct rec *list);

int main()
{
    struct rec *first = NULL, *second = NULL;
    int choice;
    do
    {
        choice = select();
        switch (choice)
        {
        case 1:
            first = create(first);
            continue;
        case 2:
            second = create(second);
            continue;
        case 3:
            add(first, second);
            display(rear->next); // Display the result
            continue;
        case 4:
            puts("END");
            exit(0);
        }
    } while (choice != 4);

    return 0;
}

int select()
{
    int selection;
    do
    {
        printf("\n\tMENU:\n");
        printf("\t1. Create Polynomial.\n");
        printf("\t2. Create second Polynomial.\n");
        printf("\t3. Add Polynomial.\n");
        printf("\t4. END.\n");
        printf("Enter your choice: ");
        scanf("%d", &selection);
    } while ((selection < 1) || (selection > 4));
    return (selection);
}

struct rec *create(struct rec *x)
{
    float coeff;
    int exp;
    int endexp = INT_MAX;
    struct rec *element;

    puts("Enter coeff and exp: exp in descending order, to quit enter 0 for exp");
    x = (struct rec *)malloc(sizeof(struct rec));
    x->next = NULL;
    rear = x; // Use global rear

    for (;;)
    {
        puts("Enter coefficient");
        element = (struct rec *)malloc(sizeof(struct rec));
        scanf("%f", &coeff);
        element->coeff = coeff;
        if (element->coeff == 0.0)
            break;

        puts("Enter exponent");
        scanf("%d", &exp);
        element->exp = exp;

        if ((element->exp <= 0) || (element->exp >= endexp))
        {
            puts("Invalid exponent");
            break;
        }

        element->next = NULL;
        rear->next = element;
        rear = element; // Move rear to the newly added element
    }

    return x->next; // Return the first element (not the dummy head)
}

void *add(struct rec *first, struct rec *second)
{
    float total;
    struct rec *result;
    result = (struct rec *)malloc(sizeof(struct rec));
    rear = result; // Use global rear
    while ((first != NULL) && (second != NULL))
    {
        if (first->exp == second->exp)
        {
            total = first->coeff + second->coeff;
            if (total != 0.0)
                rear = insert(total, first->exp, rear);
            first = first->next;
            second = second->next;
        }
        else
        {
            if (first->exp > second->exp)
            {
                rear = insert(first->coeff, first->exp, rear);
                first = first->next;
            }
            else
            {
                rear = insert(second->coeff, second->exp, rear);
                second = second->next;
            }
        }
    }

    // Copy remaining elements from the first polynomial
    for (; first != NULL; first = first->next)
    {
        rear = insert(first->coeff, first->exp, rear);
    }

    // Copy remaining elements from the second polynomial
    for (; second != NULL; second = second->next)
    {
        rear = insert(second->coeff, second->exp, rear);
    }

    rear->next = NULL; // Set the next of the last element to NULL
    display(result->next); // Display the result
}

void *display(struct rec *head)
{
    while (head != NULL)
    {
        printf("%2f", head->coeff);
        printf("%2d", head->exp);
        head = head->next;
    }
    printf("\n");
}

struct rec *insert(double coeff, int exp, struct rec *rear)
{
    rear->next = (struct rec *)malloc(sizeof(struct rec));
    rear = rear->next;
    rear->coeff = coeff;
    rear->exp = exp;
    rear->next = NULL;
    return rear;
}
