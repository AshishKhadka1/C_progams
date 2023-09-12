#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node **head, int data) {
  Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

// Function to remove a node with the given data from the list
void removeNode(Node **head, int data) {
  Node *current = *head;
  Node *prev = NULL;

  // If the node to be removed is the head node
  if (current != NULL && current->data == data) {
    *head = current->next;
    free(current);
    return;
  }

  // Search for the node to be removed
  while (current != NULL && current->data != data) {
    prev = current;
    current = current->next;
  }

  // If the node is not found
  if (current == NULL) {
    printf("Node with data %d not found.\n", data);
    return;
  }

  // Remove the node from the list
  prev->next = current->next;
  free(current);
}

// Function to display the linked list
void displayList(Node *head) {
  Node *current = head;
  if (current == NULL) {
    printf("List is empty.\n");
    return;
  }

  printf("Linked List: ");
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  Node *head = NULL; // Initialize an empty list

  int choice, data;

  while (1) {
    printf("\nLinked List Operations\n");
    printf("1. Add Node\n");
    printf("2. Remove Node\n");
    printf("3. Display List\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the data to add: ");
      scanf("%d", &data);
      insertAtBeginning(&head, data);
      printf("Node added successfully.\n");
      break;

    case 2:
      printf("Enter the data to remove: ");
      scanf("%d", &data);
      removeNode(&head, data);
      break;

    case 3:
      displayList(head);
      break;

    case 4:
      printf("Exiting...\n");
      exit(0);

    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}