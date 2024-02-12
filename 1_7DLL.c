/* Write a c program to build a doubly LinkedList
1. Display the list
2. Insert at beginning
3. Insert at end
4. Delete from beginning
5. Delete from end
 */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
  struct node *prev;
  }typedef node;
node *start;

void add_first (int);
void add_last(int);
void del_first ();
void del_last();
void display();

int main()
{
  int i,choice,ele;
  char ch1;
  /* clrscr(); */

  do
  {
     printf("1.Add First\n");
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
        add_first(ele);
        break;
      case 2:printf("Enter the element : ");
        scanf("%d",&ele);
        add_last(ele);
        break;
      case 3:del_first();
       break;
       case 4:del_last();
       break;
       case 5:display();
        break;
       default:printf("Invaild option");
       }
       printf("\nDo you wish to continue(y/n) : ");
       fflush(stdin);
       scanf("%c",&ch1);

    }  while(ch1=='Y' || ch1=='y');
 getch();
}


void add_first(int item)
{
   node *newnode;
   newnode=(node*)malloc(sizeof(node));
   newnode->data=item;
   newnode->next=NULL;
   newnode->prev=NULL;
//   temp=start;
   if(start==NULL)
   {
     start=newnode;
    }
   else
   {
     newnode->next=start;
     start->prev=newnode;
     start=newnode;
}
}

void add_last(int item)
{
   node *newnode,*temp;
   newnode=(node*)malloc(sizeof(node));
   newnode->data=item;
   newnode->next=NULL;
   newnode->prev=NULL;
   temp=start;
   if(start==NULL)
   {
     start=newnode;
     }
   else
   {
     while(temp->next!=NULL)
     {
  temp=temp->next;
  }

   temp->next=newnode;
   newnode->prev=temp;
   newnode->next=NULL;
}
}

void del_first()
{
  node *temp;
  temp=start;

  if(temp==NULL)
  {
   printf("\n List is empty");
   }
  if(start->next==NULL)
   {
     start=NULL;
     free(temp);
     }
  else
    {
    printf("Deleted item is %d ",temp->data);
    start=temp->next;
    free(temp);
    }
}

void del_last()
{
  node *temp,*prev;
  temp=start;
  prev=start;
  if(temp==NULL)
  {
   printf("\n List is empty");
   }
   if(start->next==NULL)
   {
     start=NULL;
     free(temp);
     }
    while(temp->next!=NULL)
    {
     prev=temp;
     temp=temp->next;
     }

    free(temp);
    prev->next=NULL;
 }

 void display()
 {
   node *temp;
   temp=start;
   if(temp==NULL)
   {
     printf("\nDoubly list is empty");
     return;
     }
   else
    {
     do
     {
      printf("%5d",temp->data);
      temp=temp->next;
      }while(temp!=NULL);
   }
 }



