#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node* new_node(int data);
/*
void insert_after_position(struct node *head,int pos) {
    if (head == NULL) {
	printf("head is pointing NULL \n"); {
	return ;
    }
    struct node *current = head;
}
*/
void insert_before_position(struct node **head,int pos) {
    if (head == NULL) {
	printf("head is pointing NULL \n");
	return ;
    }
    struct node *current = *head;
    struct node *prev = *head;
    struct node *temp =  NULL;
    int data; 
    if (pos == 1) {
	printf("Enter data \n");
	scanf("%d",&data);
	temp = new_node(data);
	temp->next =  *head;
	*head = temp;
    }

    while (pos-- && current) {
	if (pos == 1) {
	    printf("Enter data to insert:");
	    scanf("%d",&data);
	    temp = new_node(data);
	    temp->next = current;
	    prev->next = temp;
	    return;
	}
	prev = current;
	current = current->next;
    }
    return;
	
}

void insert_at_poistion(struct node **head,int pos) {
    if (*head == NULL) {
	printf("head is pointing NULL \n");
	return ;
    }
    struct node *current = *head;
    struct node *temp =  NULL;
    int act = pos;
    int data;
    /* handle if the position is 1 */
    if (pos == 1) {
	printf("reached position:%d enter data to be inserted:\n",act+1-pos);
	scanf("%d",&data);
	temp = new_node(data);
	temp->next = *head;
	*head = temp;
	return;	
    }

    while (pos-- && current) {
	if (pos == 1) {
	    printf("reached position:%d enter data to be inserted:\n",act+1-pos);
	    scanf("%d",&data);
	    temp = new_node(data);
	    temp->next = current->next;
	    current->next = temp;
	    printf("\ndata inserved current temp->data = %d\n",temp->data);
	    return;
	}
	current = current->next;
    }

    return;

}


struct node* new_node(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp != NULL) {
	temp->data = data;
	temp->next = NULL;
	return temp;
    } else {
	printf("MEMORY ALLOCATION FAILED!!!!!!!!!\n");
    }
    return;
}

struct node* create(struct node *head,int data) {
    struct node *new = NULL;
    if (head ==  NULL) {
	new = new_node(data);
	if  (new == NULL) {
	    printf("\nnode creation failed data = %d\n",data);
	    return;
	}
	head = new;
	return;
    }
    new = new_node(data);
    if  (new == NULL) {
	printf("\nnode creation failed data = %d\n",data);
	return;
    }
    new->next = head;
    head = new;
    return;    
}

void display(struct node *head) {
    if (head == NULL) {
	printf("list empty to disply \n");
	return;
    }
    printf("\n");
    struct node *current = head;
    while (current != NULL) {
	printf("%d  ",current->data);
	current = current->next;
    }
    printf("\n");
}

int main() {
    int i;
    struct node *head = NULL;
    int arr[10] = {23,45,55,6,34,9,23,57,64};
    for (i = 0 ; i < 10 ; i++) {
        head = create(head,arr[i]);
    }
    display(head);

    int pos;
    int val;
    while (1) {
    printf(" 1. insert_at_poistion \n2.inset_before_position \n3.insert_after_position\n");
    printf("chose any one of the above option : ");
    scanf("%d",&val);
    printf("\n");
    switch (val) {
    case 1:
	printf("enter the position :");
	scanf("%d",&pos);
	printf("\n");
	insert_at_poistion(&head,pos);
	break;
    case 2:
	printf("enter the position :");
	scanf("%d",&pos);
	printf("\n");
	insert_before_position(&head,pos);
	break;
    default :
	printf("enter the position :");
	//scanf("%d",&pos);
	//printf("\n");
	//insert_after_position(&head,pos);
	break;
    }

    printf("dispaly node after insertion\n");
    display(head);
    }
}
