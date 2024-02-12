// Write a c program to implement bubble sort.

#include <stdio.h>
#include <conio.h>

void main()
{
    int a[100], n, i, j, temp;

    printf("How many elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("Elements of array after sorting are: \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}
