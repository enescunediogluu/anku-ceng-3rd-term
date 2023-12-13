#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  int ID;
  int examGrade;  
  struct Node* left;
  struct Node* right;
  struct Node* parent;
};

struct Node* createNode(int ID, int examGrade) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->ID = ID;
  newNode->examGrade = examGrade;
  newNode->left = newNode->right = newNode->parent = NULL;
  return newNode;
}

struct Node* insertNode(struct Node* root, int ID, int examGrade) {
  if (root == NULL) {
    return createNode(ID, examGrade);
  }

  if (examGrade < root->examGrade) {
    root->left = insertNode(root->left, ID, examGrade);
    root->left->parent = root;
  } else {
    root->right = insertNode(root->right, ID, examGrade);
    root->right->parent = root;
  }

  return root;
}

void printInOrder(struct Node* root){
    if(root != NULL){
        printInOrder(root->left);
        printf("%d %d\n", root->ID, root->examGrade);
        printInOrder(root->right);
    }
}

void printLevelByLevel(struct Node* root) {
  struct Node* queue[100];
  int front = 0, rear = -1;

  if (root == NULL) {
    printf("Tree is empty.\n");
    return;
  }
  queue[++rear] = root;
  int parentExamGrade = -1;
  char parentInfo[10];

  while (front <= rear) {
    int levelSize = rear - front + 1;

    for (int i = 0; i < levelSize; i++) {
      struct Node* temp = queue[front++];
      int currentExamGrade = temp->examGrade;

      if(temp->parent == NULL){
        printf("%d %d ", temp->ID, temp->examGrade);
      }else if(temp->parent->examGrade < temp->examGrade){
        printf("%d %d (%d R) ", temp->ID, temp->examGrade, temp->parent->examGrade);
      }else if(temp->parent->examGrade > temp->examGrade){
        printf("%d %d (%d L) ", temp->ID, temp->examGrade, temp->parent->examGrade);
      }
      parentExamGrade = currentExamGrade;

      if (temp->left) {
        queue[++rear] = temp->left;
      }
      if (temp->right) {
        queue[++rear] = temp->right;
      }
    }

    parentExamGrade = -1;
    printf("\n");
  }
}

int main() {
  struct Node* root = NULL;
  int ID, examGrade;

  while (1) {
    scanf("%d", &ID);
    if (ID == -1) {
      break;
    }
    scanf("%d", &examGrade);
    root = insertNode(root, ID, examGrade);
  }
  printInOrder(root);
  printf("\n");
  printLevelByLevel(root);

  return 0;
}

