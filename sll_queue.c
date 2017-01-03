/* queue implementation using single linked list*/
/* author: Sathish J */
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
int data;
struct node *link;
} NODE;
NODE *head,*current;

int create(int );
void  print();
void middlenode_find();
void middlenode_insert();

int main()
{
  printf("################MENU#####################\n");
  while(1)
  {
    printf("please choose an option\n");
    printf("1.linked list creation\t 2.display the linked list\t 3.find a middle node\t 4.insert node at middle\t 5.exit\n);
    int choice;
    scanf("%d",choice");
    switch(1)
    {
      case 1 :
              int i,j;
              for(i=10;i<20;i++)
              {
                create(i);
              }
              break;
      case 2 :
              print();
              break;
      case 3 :
              middlenode_find();
              break;

      case 4 :
               middlenode_insert();
                break;
        case 5 : 
              exit(1);
      default :
               printf("please choose the valid option\n");
               break;
       
      return 0;
}


int create(int data)    /* to create a linked list in queue manner*/
{
        NODE *temp;
        temp = (NODE*) malloc(sizeof(NODE));
        if(temp==NULL)
        {
          printf("no memory allocated\n");
        }
        else {
          printf("memory allocated \n");
        }
        temp->data=data;
        temp->link=NULL;
         if(head == NULL)
        {
                head=current=temp;
        }
        else
        {
                current->link=temp;
                current=temp;

        }
        return 0;
}


void print()   /* to traverse and to print a linked list */
{
        if(head==NULL)
        {
                printf("\nqueue is empty\n");
        }
        else
        {
        NODE *first = head;
                while(first->link!=NULL)
                {
                printf("%d-->",first->data);
                first=first->link;
                }
                printf("%d-->NULL\n",first->data);
        }
}
          
void middlenode_find() \* find a middle node in single linked list*\
{
        NODE *first,*second;
        first=second=head;
        if(first==NULL)
        {
                printf("head node is pointing to NULL\n");
                exit(1);
        }
        while (first!=NULL&&first->link!=NULL)
        {
                first=first->link->link;
                second=second->link;
        }
        printf("found the middle node at :%d\n",second->data);
}
          
void middlenode_insert() \* find a middle node of the linked list and insert a node there of middle position *\
{
        NODE *first,*second;
        first=second=head;
        if(first==NULL)
        {
                printf("head node is pointing to NULL\n");
                exit(1);
        }
        while (first!=NULL&&first->link!=NULL)
        {
                first=first->link->link;
                second=second->link;
        }

        NODE *temp;
        temp = (NODE*) malloc(sizeof(NODE));
        if(temp==NULL)
        {
                 printf("no memory allocated\n");
                exit(1);
        }
        int data;
        printf("enter the data to be inserted:\n");
        scanf("%d",&data);
        temp->data=data;
        temp->link=second->link;
        second->link=temp;
}
