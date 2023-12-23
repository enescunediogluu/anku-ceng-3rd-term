#include <stdio.h>
#include <stdlib.h>

struct node {
    int point;
    struct node* left;
    struct node* right;
    int height;
    int balance;
    int parentData;
    int depth;
};


int calcHeight(struct node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}


int findMaxValue(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}


struct node* getNewNodeAddress(int newValue, int parent, int level) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->point = newValue;
    node->parentData = parent;
    node->depth = level;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return node;
}


struct node* rightMostRotation(struct node* y) {
    struct node* x = y->left;
    struct node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = findMaxValue(calcHeight(y->left), calcHeight(y->right)) + 1;
    x->height = findMaxValue(calcHeight(x->left), calcHeight(x->right)) + 1;

    x->parentData = y->parentData;
    y->parentData = x->point;

    int temp = x->depth;
    x->depth = y->depth;
    y->depth = temp;
    x->left->depth = temp;
    
    return x;
}

struct node* leftMostRotation(struct node* x) {
    struct node* y = x->right;
    struct node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = findMaxValue(calcHeight(x->left), calcHeight(x->right)) + 1;
    y->height = findMaxValue(calcHeight(y->left), calcHeight(y->right)) + 1;

    y->parentData = x->parentData;
    x->parentData = y->point;

    int temp = y->depth;
    y->depth = x->depth;
    x->depth = temp;

    return y;
}

int calcBalance(struct node* node) {
    if (node == NULL)
        return 0;
    return calcHeight(node->left) - calcHeight(node->right);
}

struct node* insert(struct node* node, int data, int parent, int level) {
    if (node == NULL)
        return getNewNodeAddress(data, parent, level);

    if (data < node->point){
        node->left = insert(node->left, data, node->point, node->depth + 1);
    }else if (data > node->point){
        node->right = insert(node->right, data, node->point, node->depth + 1);
    }

    node->height = 1 + findMaxValue(calcHeight(node->left), calcHeight(node->right));

    int balance = calcBalance(node);

    

    if (balance > 1 && data < node->left->point)
        return rightMostRotation(node);

    if (balance < -1 && data > node->right->point)
        return leftMostRotation(node);

    if (balance > 1 && data > node->left->point) {
        node->left = leftMostRotation(node->left);
        return rightMostRotation(node);
    }

    if (balance < -1 && data < node->right->point) {
        node->right = rightMostRotation(node->right);
        return leftMostRotation(node);
    }
    return node;
}

void inOrderTraverse(struct node* root) {
    if (root != NULL) {
        inOrderTraverse(root->left);
        printf("%d\n", root->point);
        inOrderTraverse(root->right);
    }
}

void printLevelByLevel(struct node* root, int level) {
    if (root == NULL)
        return;

    struct node** list = (struct node**)malloc(sizeof(struct node*) * 20);
    int front = 0, rear = 0;

    list[rear++] = root;

    while (front < rear) {
       
        struct node* current = list[front++];
        if(current->depth == level && current->depth == 0){
            printf("%d (%d B) ", current->point,calcBalance(current));
        }else if(current->depth == level && current->point < current->parentData){
            printf("%d (%d L) (%d B) ", current->point, current->parentData, calcBalance(current));
        }else if(current->depth == level && current->point> current->parentData){
            printf("%d (%d R) (%d B) ",   current->point ,current->parentData, calcBalance(current));
        }

        if (current->left != NULL)
            list[rear++] = current->left;

        if (current->right != NULL)
            list[rear++] = current->right;
    }

    free(list);
}

void levelOrderTraversal(struct node* root){
    int  height = calcHeight(root);
    for(int i = 0; i<=height; i++){
        printf("\n");
        printLevelByLevel(root,i);
    }
}

int main() {
    struct node* root = NULL;
    int num;
    scanf("%d", &num);

    while(num != -1){
        root = insert(root, num, 0,0);
        scanf("%d", &num);
    }

    inOrderTraverse(root);
    levelOrderTraversal(root);

    return 0;
}
