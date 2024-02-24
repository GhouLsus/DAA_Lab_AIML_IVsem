#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left, *right;
};

struct node* newNode(int data)
{
  struct node* node = (struct node*) malloc(sizeof(struct node));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

struct node *lca(struct node *root, int n1, int n2)
{
  if (root == NULL)
    return NULL;

  if (root->data > n1 && root->data > n2)
    return lca(root->left, n1, n2);

  if (root->data < n1 && root->data < n2)
    return lca(root->right, n1, n2);

  return root;
}
struct node* insert(struct node* root, int value)
{
  if (root == NULL) {
    root = newNode(value);
    return root;
  }

  if (value < root->data)
    root->left = insert(root->left, value);
  else if (value > root->data)
    root->right = insert(root->right, value);

  return root;
}

int main()
{
  struct node *root = NULL;
  int n, value, n1, n2;
 
  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  printf("Enter the values of the nodes:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &value);
    root = insert(root, value);
  }

  printf("Enter the values of node 1 and node 2: ");
  scanf("%d %d", &n1, &n2);

  struct node *t = lca(root, n1, n2);
  printf("CCA of %d and %d is %d \n", n1, n2, t->data);

  return 0;
}
