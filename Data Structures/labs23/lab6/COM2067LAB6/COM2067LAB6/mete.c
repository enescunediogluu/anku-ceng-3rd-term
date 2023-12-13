#include <stdio.h>
#include <stdlib.h>

struct node {
    int numara;
    int not;
    int par;
    int parLevel;
    struct node *left;
    struct node *right;
};

void inorderTraversal(struct node *head) {
    if (head != NULL) {
        inorderTraversal(head->left);
        printf("%d %d\n", head->numara, head->not);
        inorderTraversal(head->right);
    }
}

int calcHeight(struct node* root){
    if (root == NULL) {
        return -1; 
    }

    int leftHeight = calcHeight(root->left);
    int rightHeight = calcHeight(root->right);

    if(leftHeight > rightHeight){
        return leftHeight + 1;
    }else{
        return rightHeight + 1;
    }
}

void secondOutput(struct node* root) {
    int height = calcHeight(root);

    for(int level = 0; level<=height; level++){
        if (root == NULL)
        return;

    struct node** queue = (struct node**)malloc(sizeof(struct Node*) * 20);
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
       
        struct node* cur = queue[front++];
        if(cur->parLevel == level && cur->parLevel == 0){
            printf("%d %d", cur->numara,cur->not);
        }else if(cur->parLevel == level && cur->not < cur->par){
            printf("%d %d (%d L) ", cur->numara,cur->not, cur->par);
        }else if(cur->parLevel == level && cur->not > cur->par){
            printf("%d %d (%d R) ", cur->numara,cur->not, cur->par);
        }

        if (cur->left != NULL)
            queue[rear++] = cur->left;

        if (cur->right != NULL)
            queue[rear++] = cur->right;
    }

    free(queue);
    printf("\n");
    }
}

struct node *in(struct node *head, int gr, int nu, int par, int parLevel) {
    if (head == NULL) {
        struct node *yeniNode = (struct node *)malloc(sizeof(struct node));
        yeniNode->not = gr;
        yeniNode->numara = nu;
        yeniNode->par = par;
        yeniNode->parLevel = parLevel;
        yeniNode->left = NULL;
        yeniNode->right = NULL;
        return yeniNode;  
    }
    if (gr < head->not) {
        head->left = in(head->left, gr, nu, head->not, head->parLevel + 1);
    } else if (gr > head->not) {
        head->right = in(head->right, gr, nu, head->not, head->parLevel + 1);
    }
    return head;
}

int main() {
    struct node *head = NULL;
    int nu = 0;
    int gr = 0;
    scanf("%d", &nu);
    scanf("%d", &gr);

    while (nu != -1) {
        head = in(head, gr, nu, 0, 0);  
        scanf("%d", &nu);
        if(nu != -1){
            scanf("%d", &gr);
        }
    }
    inorderTraversal(head);
    printf("\n");
    secondOutput(head);
    
    

  return 0;
}