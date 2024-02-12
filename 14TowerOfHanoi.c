//Write a c program for implement the problem of Tower of Hanoi.

#include<stdio.h>
#include<conio.h>
void tower(int n, char s ,char a, char d);
void main(){
    char s='A', a='B', d='C';
    int n;
    printf("Enter no. of disk ");
    scanf("%d",&n);
    printf("The solution of Tower of Hanoi problem for %d disks is : \n ",n);
    tower(n,s,a,d);
}
void tower(int n,char s ,char a, char d){
    if(n!=0){
        tower(n-1,s,d,a);
        printf("Move disk %d form %c to %c \n",n,s,d);
        tower(n-1,a,s,d);
   }
}

