
/*Convert a tree to doubly linked list using Inorder traversal */

Node *convet_trrr_dbl(Node *root,Node **head_ref,Node **prev) {
  if (!root)
      return;
  
  //left subtree traversal
  convet_trrr_dbl(root->left,head_ref,prev);
  
  if (!*head_ref) {
      *head_ref = root;
  } else {
      root->left = *prev;
      *prev->right = root;
  }
  *prev = root;
  
  //right subtree travesal
  convet_trrr_dbl(root->right,head_ref,prev);
}
