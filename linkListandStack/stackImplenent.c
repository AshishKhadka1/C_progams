#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the stack

// Define the stack structure
struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Initialize an empty stack
void initStack(struct Stack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Check if the stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push %d\n", value);
        return;
    }
    stack->data[++stack->top] = value;
}

// Pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

int main() {
    struct Stack myStack;
    initStack(&myStack);

    // Push some elements onto the stack
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);

    // Pop elements from the stack and print them
    printf("Popped elements: %d, %d, %d\n", pop(&myStack), pop(&myStack), pop(&myStack));

    // Attempting to pop from an empty stack
    pop(&myStack); // This will print an error message and exit the program

    return 0;
}
