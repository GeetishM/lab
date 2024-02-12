/* Write a c program to build a circular LinkedList.
1. Display the list
2. Insert at beginning
3. Insert at end
4. Delete from beginning
5. Delete from end */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
  }typedef node;

struct cir_list
{
  struct node *start;
  }typedef cir_list;

void add_first (cir_list *,int);
void add_last(cir_list*,int);
void del_first (cir_list*);
void del_last(cir_list*);
void display(cir_list*);


int main()
{
  int i,choice,ele;
  char ch1;
  cir_list *cl;
  //clrscr();
  cl->start=NULL;
  do
  {
     printf("1.Add First \n");
     printf("2.Add Last\n");
     printf("3.Delete first\n");
     printf("4.Delete last\n");
     printf("5.Display\n");
     printf("\nEnter the choice : ");
     scanf("%d",&choice);
     switch(choice)
     {
      case 1:printf("Enter the element : ");
            scanf("%d",&ele);
            add_first(cl,ele);
            break;
      case 2:printf("Enter the element : ");
            scanf("%d",&ele);
            add_last(cl,ele);
            break;
      case 3:del_first(cl);
            break;
       case 4:del_last(cl);
            break;
       case 5:display(cl);
            break;
       default:printf("Invaild option");
       }
       printf("\nDo you wish to continue(y/n) : ");
       fflush(stdin);
       scanf("%c",&ch1);

    }  while(ch1=='Y' || ch1=='y');
 getch();
}

void add_first(cir_list * cl,int item)
{
   node *newnode,*temp;
   newnode=(node*)malloc(sizeof(node));
   newnode->data=item;
   newnode->next=NULL;
   temp=cl->start;
   if(cl->start==NULL)
   {
     cl->start=newnode;
     cl->start->next=cl->start;

     }
   else
   {
     while(temp->next!=cl->start)
     {
  temp=temp->next;
  }
temp->next=newnode;
newnode->next=cl->start;
cl->start=newnode;

}
}

void add_last(cir_list * cl,int item)
{
   node *newnode,*temp;
   newnode=(node*)malloc(sizeof(node));
   newnode->data=item;
   newnode->next=NULL;
   temp=cl->start;
   if(cl->start==NULL)
   {
     cl->start=newnode;
     cl->start->next=cl->start;

     }
   else
   {
     while(temp->next!=cl->start)
     {
  temp=temp->next;
  }

newnode->next=cl->start;
temp->next=newnode;
}
}

void del_first(cir_list *cl)
{
  node *temp,*temp1;
  temp=cl->start;
  temp1=cl->start;
  if(temp==NULL)
  {
   printf("\n List is empty");
   }
   if(cl->start->next==cl->start)
   {
     cl->start=NULL;
     free(temp);
     }
    while(temp->next!=cl->start)
    {
     temp=temp->next;
     }
    cl->start=cl->start->next;
    free(temp1);
    temp->next=cl->start;
 }

void del_last(cir_list *cl)
{
  node *temp,*prev;
  temp=cl->start;
  prev=cl->start;
  if(temp==NULL)
  {
   printf("\n List is empty");
   }
   if(cl->start->next==cl->start)
   {
     cl->start=NULL;
     free(temp);
     }
    while(temp->next!=cl->start)
    {
     prev=temp;
     temp=temp->next;
     }

    free(temp);
    prev->next=cl->start;
 }

 void display(cir_list *cl)
 {
   node *temp;
   temp=cl->start;
   if(temp==NULL)
   {
     printf(" \n circular list is empty ");
     return;
     }
   else
    {
     do
     {
      printf("%5d",temp->data);
      temp=temp->next;
      }while(temp!=cl->start);
   }
 }


