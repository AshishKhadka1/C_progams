#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

// func to create new node
TreeNode* createNode(int data){
  TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
  newNode->data = data;
  newNode->left = NULL;
  newNode->left = NULL;
  return newNode;
}

// func to inset node in bt
TreeNode *insert(TreeNode *root , int data){
  if(root == NULL){
    return createNode(data);
  }
  if(data < root->data){
    root->left = insert(root->left, data);
  } else if(data > root->data){
    root->right = insert (root->right, data);
  }
  return root;
}

void inOrderTraversal ( TreeNode *root){
  // if the root == NULL it means we are at the end of the tree
  if(root == NULL){
    return;
  } 
  // checks again and again in left side before moving to right
  inOrderTraversal(root->left);
  printf("\t%d", root->data);
  inOrderTraversal(root->right);
}

void freeTreeNode(TreeNode *root){
  if(root == NULL){
    return;
  }
  freeTreeNode(root->left);
  freeTreeNode(root->right);
  free(root);
}
int main() {
  struct TreeNode* root = NULL;
  int data, choice;

  do { 
    printf("Select options:\n");
    printf("1. Insert\n");
    printf("Enter the choice: ");
    scanf("%d", &choice);
    printf("Enter the data to be inserted: \n");
    scanf("%d", &data);

    root = insert(root, data);

  } while (choice == 1);

  // Perform inorder traversal to print the elements of the binary tree
  printf("Inorder Traversal: ");
  inOrderTraversal(root);
  printf("\n");

  // Free the memory occupied by the binary tree
  freeTreeNode(root);

  return 0;
}