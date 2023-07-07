#include <stdio.h>
#define MAX 10

typedef struct {
    int num[MAX]; // array is used as store-house for stack
    int tos; // top of the stack	
} stack;

int isEmpty(stack* s) {
    if (s->tos == -1) {
        return 1; // TRUE
    } else {
        return 0; // FALSE
    }
}

int isFull(stack s) {
    if (s.tos == MAX - 1) {
        return 1; // TRUE
    } else {
        return 0; // FALSE
    }
}

void push(stack* sp) {
    int n;
    if (isFull(*sp)) {
        printf("\nStack Is Full.");
        return;
    }
    printf("Enter a number: ");
    scanf("%d", &n);
    sp->tos++;
    sp->num[sp->tos] = n;
}

void pop(stack* sp) {
    int n;
    if (isEmpty(sp)) {
        printf("\nStack Is Empty.");
        return;
    }
    n = sp->num[sp->tos];
    sp->tos--;
    printf("%d was popped.", n);
}

void list(stack s) {
    if (isEmpty(&s)) {
        printf("\nStack is empty.");
    } else {
        printf("Stack Contents:\n");
        for (int i = 0; i <= s.tos; i++) {
            printf("%d\n", s.num[i]);
        }
    }
}

int main() {
    stack s;
    char choice;
    s.tos = -1; // initialize stack to be empty
    while (1) {
        printf("\nSelect an option");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. List");
        printf("\n4. Exit\n");
      
        choice = getchar();
        switch (choice) {
            case '1':
                push(&s);
                break;
            case '2':
                pop(&s);
                break;
            case '3':
                list(s);
                break;
            case '4':
                return 0;
        }
    }
}

