#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
    } else {
        struct Node *last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
    }
    *head = newNode;
}
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; 
        *head = newNode;
    } else {
        struct Node *last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
    }
}
void deleteFirstNode(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    struct Node *last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    *head = (*head)->next;
    last->next = *head;
    free(temp);
}
void deleteLastNode(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head;
    struct Node *prev = NULL;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL) {
        prev->next = *head;
    } else {
        *head = NULL;
    }
    free(temp);
}

// Function to delete a node with value 'n' from a circular linked list
void deleteNodeWithValue(struct Node **head, int n) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = *head, *prev = NULL;
    while (temp->data != n) {
        if (temp->next == *head) {
            printf("Node with value %d not found\n", n);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp == *head) {
        deleteFirstNode(head);
        return;
    }
    prev->next = temp->next;
    free(temp);
}
void deleteCircularList(struct Node **head) {
    if (*head == NULL) {
        printf("List is already empty\n");
        return;
    }
    struct Node *current = *head, *next;
    while (current->next != *head) {
        next = current->next;
        free(current);
        current = next;
    }
    free(*head);
    *head = NULL;
}
void displayList(struct Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    printf("List after insertion at the beginning: ");
    displayList(head);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 5);
    printf("List after insertion at the end: ");
    displayList(head);
    deleteFirstNode(&head);
    printf("List after deletion of the first node: ");
    displayList(head);
    deleteLastNode(&head);
    printf("List after deletion of the last node: ");
    displayList(head);
    deleteNodeWithValue(&head, 3);
    printf("List after deletion of node with value '3': ");
    displayList(head);

    deleteCircularList(&head);
    printf("List after deletion of entire list: ");
    displayList(head);

    return 0;
}