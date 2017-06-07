newnode=null;

while(head)
{
	temp=head->next;
	
	head->next=newnode;

	newnode=head;
	
	head=temp;

}

//second method
struct node* recursiveReverseLL(struct node* first){

   if(first == NULL) return NULL; // list does not exist.

   if(first->link == NULL) return first; // list with only one node.

   struct node* rest = recursiveReverseLL(first->link); // recursive call on rest.

   first->link->link = first; // make first; link to the last node in the reversed rest.

   first->link = NULL; // since first is the new last, make its link NULL.

   return rest; // rest now points to the head of the reversed list.
}

//method -3
LINK *reverse_linked_list_recursion(LINK *head)
{
        LINK *temp;
        if (!head) {
                printf("Empty list\n");
                return head;
        }
        else if (!head->next)
                return head;
        temp = reverse_linked_list_recursion(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
}

//method 4
truct node { 
struct node *np; 
int datum; 
}; 

struct node *swap_nodes( struct node *np) 
{ 

if ( ! np) 
return np; 
else if (np = np->np) 
return np; 

else 
np->np = swap_nodes( np); 
}
