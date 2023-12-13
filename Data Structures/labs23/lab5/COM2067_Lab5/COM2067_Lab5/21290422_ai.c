#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CALLERS 100

// Define priority levels
enum Priority {
    MOTHER = 1,
    UNCLE = 2,
    WORKPLACE = 3,
    FRIEND = 4,
    BANK = 5,
    ADVERTISEMENT = 6
};

// Struct to represent a caller
struct CallerInfo {
    char name[50];
    enum Priority priority;
};

// Priority queue node
struct Node {
    struct CallerInfo data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(struct CallerInfo caller) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = caller;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a caller into the priority queue
void insert(struct Node** head, struct CallerInfo caller) {
    struct Node* newNode = createNode(caller);

    if (*head == NULL || caller.priority < (*head)->data.priority ||
        (caller.priority == (*head)->data.priority && strcmp(caller.name, (*head)->data.name) < 0)) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && (caller.priority > current->next->data.priority ||
                (caller.priority == current->next->data.priority && strcmp(caller.name, current->next->data.name) > 0))) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to display the call log
void displayCallLog(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%s\n", current->data.name);
        current = current->next;
    }
}

int main() {
    struct Node* callLog = NULL;

    // Sample calls (you can modify this part to include user input)
    struct CallerInfo callers[] = {
        {"Arkadasim1", FRIEND},
        {"Annem", MOTHER},
        {"Banka", BANK},
        {"Arkadasim2", FRIEND},
        {"Arkadasim3", ADVERTISEMENT},
        {"Amcam", UNCLE},
        {"Kardesim", MOTHER},
        // Add more calls as needed
    };

    int numCallers = sizeof(callers) / sizeof(callers[0]);

    // Insert calls into the priority queue
    for (int i = 0; i < numCallers; i++) {
        insert(&callLog, callers[i]);
    }

    // Display the call log
    displayCallLog(callLog);

    // Clean up memory (free allocated nodes)
    struct Node* current = callLog;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
