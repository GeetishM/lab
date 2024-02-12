// Write a c program to implement quick sort.

#include <stdio.h>
#include <conio.h>

#define max 100

int a[max], n, i, l, h;

void quick_sort(int a[], int l, int h);

void output(int a[], int n);

void main()
{
    void input(void);

    input();

    getch();
}

void input(void)
{
    printf("How many elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements: \n");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    l = 0;
    h = n - 1;

    quick_sort(a, l, h);

    printf("Sorted Array:\n");
    output(a, n);
}

void quick_sort(int a[], int low, int high)
{
    int temp, key;
    int l = low;
    int h = high;

    key = a[(low + high) / 2];

    do
    {
        while (key > a[l])
            l++;

        while (key < a[h])
            h--;

        if (l <= h)
        {
            temp = a[l];
            a[l++] = a[h];
            a[h--] = temp;
        }

    } while (l <= h);

    if (low < h)
        quick_sort(a, low, h);

    if (l < high)
        quick_sort(a, l, high);
}

void output(int a[], int n)
{
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}
