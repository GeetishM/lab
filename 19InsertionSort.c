// Write a c program to implement insertion sort.

#include <stdio.h>
#include <conio.h>

void main()
{
    int a[100], n, k, j, temp;

    //clrscr();

    printf("How many elements\n");
    scanf("%d", &n);

    printf("Enter the elements of the array\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (k = 1; k < n; k++)
    {
        temp = a[k];
        j = k - 1;

        while (j >= 0 && temp < a[j])
        {
            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j + 1] = temp;
    }

    printf("Elements of array after sorting\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    //getch();
}
