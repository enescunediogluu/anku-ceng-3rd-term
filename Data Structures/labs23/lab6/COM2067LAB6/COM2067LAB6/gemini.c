#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int id;
  int grade;
  struct Node* left;
  struct Node* right;
  struct Node* parent; // Added parent field
} Node;


Node* createNode(int id, int grade) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->id = id;
  newNode->grade = grade;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node* insertNode(Node* root, int id, int grade) {
  if (root == NULL) {
    return createNode(id, grade);
  } else if (id < root->id) {
    root->left = insertNode(root->left, id, grade);
    root->left->parent = root; // Set parent for left child
  } else if (id > root->id) {
    root->right = insertNode(root->right, id, grade);
    root->right->parent = root; // Set parent for right child
  } else {
    printf("Error: Duplicate student ID %d.\n", id);
  }
  return root;
}


void printTree(Node* root) {
  if (root != NULL) {
    printf("%d %d", root->id, root->grade);
    if (root->parent != NULL) {
      printf(" (%d %s)", root->parent->id, (root == root->parent->left) ? "L" : "R");
    }
    printf("\n");
    printTree(root->left);
    printTree(root->right);
  }
}

void inOrderTraversal(Node* root) {
  if (root != NULL) {
    inOrderTraversal(root->left);
    printf("%d %d\n", root->id, root->grade);
    inOrderTraversal(root->right);
  }
}

int main() {
  Node* root = NULL;

  int id, grade;
  while (scanf("%d %d", &id, &grade) != EOF) {
    if (id == -1) {
      break;
    }
    root = insertNode(root, id, grade);
  }

  printf("\nTree:\n");
  printTree(root);

  printf("\nSorted List:\n");
  inOrderTraversal(root);

  return 0;
}
