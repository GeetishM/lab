// Write a c program to find an element using binary search ?

#include<stdio.h>
#include<conio.h>
void main(){
    int a[]={1,3,4,5,8,9,10,11,12,17};
    int i,key , left ,right, mid, flag=0 ;
    printf("Enter the element to be searched : ");
    scanf("%d",&key);
    left = 0;
    right = 9;
    while(left<=right){
        mid=(left+right)/2;

        if(key==a[mid]){
            flag=1;
            break;
        }
        else{
            if(key<a[mid]){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
    }
    if(flag==1)
    printf("\nElement found at position %d ",mid);
    else
    printf("\nElement not found");

}
