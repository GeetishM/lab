// Write a c program to implement selection sort.

#include <stdio.h>
#include <conio.h>

void main()
{
    int a[100], n, i, j, temp, loc, min;

    //clrscr();

    printf("How many elements:\n");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n - 1; i++)
    {
        min = a[i];
        loc = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                loc = j;
            }
        }

        if (loc != i)
        {
            temp = a[i];
            a[i] = a[loc];
            a[loc] = temp;
        }
    }

    printf("The numbers after selection sorting are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }

    //getch();
}
