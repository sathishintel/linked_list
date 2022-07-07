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
