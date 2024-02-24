#include <stdio.h>
#include <stdlib.h>

// BST Node
typedef struct Node {
    int key;
    struct Node *left, *right;
} Node;

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node** pre, Node** suc, int key) {
    // Base case
    if (root == NULL) return;

    // If key is present at root
    if (root->key == key) {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL) {
            Node* tmp = root->left;
            while (tmp->right != NULL)
                tmp = tmp->right;
            *pre = tmp;
        }

        // the minimum value in right subtree is successor
        if (root->right != NULL) {
            Node* tmp = root->right;
            while (tmp->left != NULL)
                tmp = tmp->left;
            *suc = tmp;
        }
        return;
    }

    // If key is smaller than root's key, go to left subtree
    if (root->key > key) {
        *suc = root;
        findPreSuc(root->left, pre, suc, key);
    } else // go to right subtree
    {
        *pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

// A utility function to create a new BST node
Node* newNode(int item) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to insert a new node with given key in BST
Node* insert(Node* node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}

int main() {
    int key, n;

    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n];

    printf("Enter the keys:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &keys[i]);

    Node* root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, keys[i]);

    printf("Enter the key to find its successor and predecessor: ");
    scanf("%d", &key);

    Node* pre = NULL, *suc = NULL;

    findPreSuc(root, &pre, &suc, key);
    if (pre != NULL)
        printf("Predecessor is %d\n", pre->key);
    else
        printf("No Predecessor");

    if (suc != NULL)
        printf("Successor is %d", suc->key);
    else
        printf("No Successor");

    return 0;
}