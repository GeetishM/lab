// Write a c program to insert any element to an array at given location.

#include<stdio.h>
#include<conio.h>
void main(){
    int a[10]={1,2,3,4,5};
    int n,k,loc,i,ub=4,max=10;
    printf("enter an element to insert : ");
    scanf("%d",&n);
    printf("enter location : ");
    scanf("%d",&loc);
    if(k==max){
        printf("underflow");
    }
    else{
        k=ub;
        while(k>=loc){
            a[k+1]=a[k];
            --k;
        }
        a[loc]=n;
    }
    printf("Your array is : ");
    for(i=0;i<=5;i++){
        printf("%3d",a[i]);
    }
} 

