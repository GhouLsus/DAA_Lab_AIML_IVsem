#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node *l;
  struct node *r;
} node;
int opcount = 0;
node* create(int x) {
  node* new = (node*)malloc(sizeof(node));
  new->val = x;
  new->l = new->r = NULL;
  return new;
}

int count(node* root) {
  if (root == NULL)
    return 0;
  int l = count(root->l);
  int r = count(root->r);
  opcount++;
  return 1 + l + r;
}

void insert(node** root, int val) {
  node* new = create(val);
  if (*root == NULL) {
    *root = new;
  } else {
    node* curr = *root;
    node* parent;
    while (1) {
      if (val < curr->val) {
        parent = curr;
        curr = curr->l;
        if (curr == NULL) {
          parent->l = new;
          break;
        }
      } else {
        parent = curr;
        curr = curr->r;
        if (curr == NULL) {
          parent->r = new;
          break;
        }
      }
    }
  }
}

void printInOrder(node* root) {
  if (root == NULL)
    return;

  printInOrder(root->l);
  printf("%d ", root->val);
  printInOrder(root->r);
}

int main() {
  int n, val;
  node* root = NULL;

  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  printf("Enter the values of nodes:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &val);
    insert(&root, val);
  }

  printf("In-order traversal: ");
  printInOrder(root);
  printf("\n");

  printf("Total number of nodes is %d\n", count(root));
  printf("Number of operations: %d\n", opcount);
  return 0;
}