#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
int data;
struct node *link;
} NODE;
NODE *head,*current;

int create(int );
void  print(NODE*);
NODE* recursiveReverseLL(struct node* first);

int main()
{
//      NODE *head;
        int i,j;
        NODE *p;
        for(i=10;i<20;i++)
        {
                create(i);
        }

        print(head);
        printf("reverse lkinked loist\n");
        p = recursiveReverseLL(head);
        printf("print the data\n");
        print(p);
        printf("\n");
        print(head);
        p = recursiveReverseLL(p);
        print(p);
        return 0;
}

//struct node* recursiveReverseLL(struct node* first){
NODE* recursiveReverseLL(struct node* first){
        if (!first)
                return NULL;
        if (!first->link)
                return first;
        NODE *rest = recursiveReverseLL(first->link);
        first->link->link = first;
        first->link = NULL;
        return rest;
}
int create(int data)
{
        //NODE *current;
        printf("head=%p\n",head);
        NODE *temp;
        if(head == NULL)
        {
                temp = (NODE*) malloc(sizeof(NODE));
                if(temp==NULL)
                {
                        printf("no memory allocated\n");
                }
                //printf("memory allocated \n");
                temp->data=data;
                temp->link=NULL;
                head=temp;
                current=head;
                //printf("data%d\n",current->data);
//              printf("head=%p\n",head);
        }
        else
        {
                temp = (NODE*) malloc(sizeof(NODE));
                if(temp==NULL)
                {
                        printf("no memory allocated\n");
                }
                //printf("memory allocated \n");        
                printf("current=%p\n",current);
                temp->data=data;
                temp->link=NULL;
                current->link=temp;
                current=temp;
        }
        return 0;

}


void print(NODE *head)
{
        NODE *first=head;
        printf("print:head=%p,first=%p\n",head,first);
        while(first->link!=NULL)
        {
                printf("%d->",first->data);
                first=first->link;
        }
                printf("%d->",first->data);
                printf("NULL\n");
}
                   
