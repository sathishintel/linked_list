#include<stdio.h>
#include<stdlib.h>

int __is_palindrome(struct node *left , struct node *right) {
 if (right ==  NULL)
     return 1;
  }
  int flag = __is_palindrom(left,right->next);
  if (flag == 0) 
    return 0;

  int flag2 = (right->data == left->data);
  left = left->next;
  return flag2;
}

int is_palindrome(strcy node *head) {
    int pal = __is_palindrome(head,head);
    if (pal != 1)
        printf("not a palindrome\n");
}



Second Method without recursion
//isPalindrome() will determine whether given list is palindrome or not.  
void isPalindrome(){  
    struct node *current = head;  
    bool flag = true;  
      
    //Store the mid position of the list  
    int mid = (size%2 == 0)? (size/2) : ((size+1)/2);  
      
    //Finds the middle node in given singly linked list  
    for(int i=1; i<mid; i++){  
        current = current->next;  
    }  
      
    //Reverse the list after middle node to end  
    struct node *revHead = reverseList(current->next);  
   
    //Compare nodes of first half and second half of list  
    while(head != NULL && revHead != NULL){  
        if(head->data != revHead->data){  
            flag = false;  
            break;  
        }  
        head = head->next;  
        revHead = revHead->next;  
    }  
   
    if(flag)  
        printf("Given singly linked list is a palindrome\n");  
    else  
        printf("Given singly linked list is not a palindrome\n");  
}  
