#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct intersectedNode {
    int data;
    int index1;
    int index2;
    struct intersectedNode* next;
};

struct Node* insertAtTheEnd(struct Node** head, int x) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = x;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
    } else {
        struct Node* temp2 = *head;
        while (temp2->next != NULL) {
            temp2 = temp2->next;
        }

        temp2->next = temp;
    }
}

void printValues(struct intersectedNode* head) {
    struct intersectedNode* temp2 = head;

    while (temp2 != NULL) {
        printf("%d %d %d\n", temp2->data, temp2->index1, temp2->index2);
        temp2 = temp2->next;
    }
}

void addInt(struct intersectedNode** head, int data, int index1, int index2) {
    struct intersectedNode* temp = (struct intersectedNode*)malloc(sizeof(struct intersectedNode));
    struct intersectedNode* current = *head;

    temp->data = data;
    temp->index1 = index1;
    temp->index2 = index2;
    temp->next = NULL;

    if (*head == NULL) {
        *head = temp;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = temp;
}

struct intersectedNode* intersected_nodes(struct Node* list1, struct Node* list2) {
    struct intersectedNode* commonList = NULL;
    struct Node* temp2 = list1;

    int count1 = 0;
    while (temp2 != NULL) {
        int count2 = 0;
        struct Node* temp = list2;
        while (temp != NULL) {
            if (temp2->data == temp->data) {
                addInt(&commonList, temp2->data, count1, count2);
            }
            temp = temp->next;
            count2++;
        }
        count1++;
        temp2 = temp2->next;
    }

    return commonList;
}

int main() {
    int input;
    int input2;

    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    while (1) {
        scanf("%d", &input);

        if (input == -1) {
            break;
        }
        insertAtTheEnd(&list1, input);
    }

    while (1) {
        scanf("%d", &input2);

        if (input2 == -1) {
            break;
        }
        insertAtTheEnd(&list2, input2);
    }

    struct intersectedNode* intersectedList = intersected_nodes(list1, list2);

    if (intersectedList != NULL) {
        printValues(intersectedList);
    } else {
        printf("-1\n");
    }
   
   return 0;
}