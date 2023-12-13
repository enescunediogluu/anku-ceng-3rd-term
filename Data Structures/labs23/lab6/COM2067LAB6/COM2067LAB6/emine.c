#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    int id;
    int grade;
    int parent_data;
    struct node *right;
};
struct node *root = NULL;

struct node* insert(struct node *root, int id, int grade, int parent_data){
    
    if (root == NULL)
    {
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->left = NULL;
        temp->right = NULL;
        temp->parent_data = parent_data;
        temp->id = id;
        temp->grade = grade;
        return temp;
    }
    else
    {
        if (grade > root->grade){
            root->right = insert(root->right, id, grade, root->grade);
        }
        
        else if (grade < root->grade){
            root->left = insert(root->left, id, grade, root->grade);
        }   
        return root;
    }
}

void take_inputs(){  
    struct node *root = NULL;      
    int id;
    int grade;
    printf("id girin:");
    scanf("%d", &id);

    while (id != -1)
    {
            
        printf("grade girin:");
        scanf("%d", &grade);

        root = insert(root, id, grade, 0);
            
        
        printf("id girin:");
        scanf("%d", &id);
    }
    
}

void display(struct node *root){
    if (root == NULL)
    {
        return;
    }
    else
    {
        display(root->left);
        printf("%d %d\n", root->id, root->grade);
        display(root->right);
    }
}

int tree_height(struct node *root) {
    // Get the height of the tree
    if (!root)
        return 0;
    else {
        // Find the height of both subtrees
        // and use the larger one
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}


void print_level(struct node *root, int level_no) {
    // Prints the nodes in the tree
    // having a level = level_no
    
    // We have a auxiliary root node
    // for printing the root of every
    // subtree
    if (root == NULL)
        return;
    if (level_no == 0) {
        // We are at the top of a subtree
        // So print the auxiliary root node
        if(root->parent_data == 0){
            printf("%d %d ",root->id, root->grade);
        }
        else if (root->parent_data > root->grade)
        {
            printf("%d %d (%d L) ",root->id, root->grade, root->parent_data);
        }
        else if (root->parent_data < root->grade)
        {
            printf("%d %d (%d R) ",root->id, root->grade, root->parent_data);
        }
        
        
    }
    else {
        // Make the auxiliary root node to
        // be the left and right nodes for
        // the subtrees and decrease level by 1, since
        // you are moving from top to bottom
        print_level(root->left, level_no - 1);
        //printf("(%d L)  ",root->grade);
        print_level(root->right, level_no - 1);
        //printf("(%d R)  ",root->grade);
    }

}

void print_tree_level_order(struct node *root) {
    if (root == NULL)
        return;
    int height = tree_height(root);
    for (int i=0; i<height; i++) {
        //printf("%d ", i);
        print_level(root, i);
        printf("\n");
    }
    /*
    printf("\n\n-----Complete Level Order Traversal:-----\n");
    for (int i=0; i<height; i++) {
        print_level(root, i);
    }
    */
    //printf("\n");
}


int main(){
    //struct node *root = NULL;
    //take_inputs();
    
    struct node *root = NULL;      
    int id;
    int grade;
    printf("id girin:");
    scanf("%d", &id);

    while (id != -1)
    {
            
        printf("grade girin:");
        scanf("%d", &grade);

        root = insert(root, id, grade, 0);
  
        printf("id girin:");
        scanf("%d", &id);
    }
    display(root);
    printf("\n");
    //printf("Level Order traversal of binary tree is \n");
    print_tree_level_order(root);
    return 0;
}

