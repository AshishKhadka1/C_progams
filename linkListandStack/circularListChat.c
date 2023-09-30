#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode; // Point to itself for the first node
        *head = newNode;
    } else {
        struct Node* last = (*head)->next;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to display the circular linked list
void display(struct Node* head) {
    struct Node* current = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf(" (Back to the beginning)\n");
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printf("Circular Linked List: ");
    display(head);

    return 0;
}
