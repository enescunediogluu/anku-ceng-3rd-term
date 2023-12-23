#include <stdio.h>
#include <stdlib.h>

#define ORDER 3

// Node structure
typedef struct Node {
    int isLeaf;
    int numKeys;
    int keys[ORDER - 1];
    struct Node* children[ORDER];
} Node;

// Function prototypes
Node* createNode();
void insertBTree(Node** root, int key);
void splitNode(Node* parentNode, int index);
void insertNonFull(Node* node, int key);
void display(Node* root, int level);
void level_order_traversal(Node* root);

int main() {
    Node* root = NULL;

    // Insert keys into the B-tree
    int keys[] = {10, 20, 5, 6, 12, 30, 7, 17};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < numKeys; i++) {
        insertBTree(&root, keys[i]);
        printf("Inserted key %d: ", keys[i]);
        display(root, 0);
        printf("\n");
    }

    return 0;
}


// Function to create a new node
Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->isLeaf = 1;
    newNode->numKeys = 0;
    for (int i = 0; i < ORDER; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to insert a key into the B-tree
void insertBTree(Node** root, int key) {
    if (*root == NULL) {
        *root = createNode();
        (*root)->keys[0] = key;
        (*root)->numKeys = 1;
    } else {
        if ((*root)->numKeys == ORDER - 1) {
            Node* newRoot = createNode();
            newRoot->isLeaf = 0;
            newRoot->children[0] = *root;
            *root = newRoot;
            splitNode(newRoot, 0);
        }
        insertNonFull(*root, key);
    }
}

// Function to insert a key into a non-full node
void insertNonFull(Node* node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;

        if (node->children[i]->numKeys == ORDER - 1) {
            splitNode(node, i);
            if (key > node->keys[i]) {
                i++;
            }
        }

        insertNonFull(node->children[i], key);
    }
}

// Function to split a full node
void splitNode(Node* parentNode, int index) {
    Node* childNode = parentNode->children[index];
    Node* newNode = createNode();
    newNode->isLeaf = childNode->isLeaf;
    newNode->numKeys = ORDER / 2 - 1;

    for (int i = 0; i < ORDER / 2 - 1; i++) {
        newNode->keys[i] = childNode->keys[i + ORDER / 2];
    }

    if (!childNode->isLeaf) {
        for (int i = 0; i < ORDER / 2; i++) {
            newNode->children[i] = childNode->children[i + ORDER / 2];
            childNode->children[i + ORDER / 2] = NULL;
        }
    }

    childNode->numKeys = ORDER / 2 - 1;

    for (int i = parentNode->numKeys; i > index; i--) {
        parentNode->children[i + 1] = parentNode->children[i];
    }

    parentNode->children[index + 1] = newNode;

    for (int i = parentNode->numKeys - 1; i >= index; i--) {
        parentNode->keys[i + 1] = parentNode->keys[i];
    }

    parentNode->keys[index] = childNode->keys[ORDER / 2 - 1];
    parentNode->numKeys++;
}

// Function to display the B-tree
void display(Node* root, int level) {
    if (root != NULL) {
        printf("Level %d: ", level);
        for (int i = 0; i < root->numKeys; i++) {
            printf("%d ", root->keys[i]);
        }
        printf("\n");

        level++;
        if (!root->isLeaf) {
            for (int i = 0; i <= root->numKeys; i++) {
                display(root->children[i], level);
            }
        }
    }
}
