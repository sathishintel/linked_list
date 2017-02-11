newnode=null;

while(head)
{
	temp=head->next;
	
	head->next=newnode;

	newnode=head;
	
	head=temp;

}
