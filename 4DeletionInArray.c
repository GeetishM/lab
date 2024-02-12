// Write a c program to delete an element from an array at given location.

#include<stdio.h>
#include<conio.h>
void main() 
   {
    int a[10],i,pos,ele,n;
    printf("Enter size of array : ");
    scanf("%d",&n);
    printf("Enter number of elements in your list: ");
    for(i=0;i<n;i++)
   {
        scanf("%d",&a[i]);
    }
    printf("array is ");
    for (i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf(" \nEnter position from where element is to be delete ");
    scanf("%d", &pos);
    if(pos>n)
   {
        printf("deletion not possible \n");
    }
    else
   {
        for(i=pos-1;i<n-1;i++){
            a[i] = a[i+1];
     }
    }
    printf("array after deletion ");
    for (i = 0; i < n - 1; ++i)
    {
        printf("%d ", a[i]);
    }
    
}  
