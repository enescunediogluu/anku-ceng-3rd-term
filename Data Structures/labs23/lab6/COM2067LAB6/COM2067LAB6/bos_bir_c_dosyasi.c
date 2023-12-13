#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root;


int main(){
    //root->data = NULL;
    printf("%p", &root);
    return 0;
}