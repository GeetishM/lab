// Write a c program to find an element using linear search.

#include<stdio.h>
#include<conio.h>
void main(){
    int a[]={1,3,4,5,8,9,10,11,12,17};
    int i ,key ,flag=0;
    printf("Enter the element to be searched : ");
    scanf("%d",&key);
    for (i=0;i<10;++i){
        if(key == a[i]) {
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("%d found at index %d of the array ",key,i);
    else
        printf("%d Not found in the array ",key);
}     
