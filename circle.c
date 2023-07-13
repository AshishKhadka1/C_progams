// #include<stdio.h>
// #include<conio.h>
// #include<stdlib.h>
// #include<string.h>
// #define MAX 10

// struct student {
//   int roll;
//   char name[50];
//   int age;
// };
// struct node {
//   struct student std;
//   struct node *next;
// }

// struct node *header = NULL; // empty list
// struct node *getnode(struct student s){
//   struct node *ptrnew=(struct node*)malloc(sizeof(struct node));
//   if(ptrnew==NULL){
//     pritf("\nMemory allocation failed.");
//     getch();
//     exit(0);
//   }
//   ptrnew->std.roll=s.roll;
//   strcpy(ptrnew->std.name, s.name);
//   ptrnew->std.age=s.age;
//   ptrnew->next = NULL;
//   return ptrnew;

// }
// void addStudentAtFront(){
//   struct student s;
//   printf ("\nEnter the name of student: ");
//   gets(s.name);
//   printf("\nEnter rol number of student: ");
//   scanf("%d", &s.roll)
//     printf("\nEnter age: ");
//   scanf("%d",&s.age);
//   ptrnew=getnode(s);
//   if(header==NULL){
//     header = ptrnew;
//     header->next=header;
//   } else {
//     ptrnew->next=header->next;
//     header>next=ptrnew;
//   }
//   printf("Inserted at the forn of the list");
// }

// void display(){
//   struct node *ptrthis;
//   if(header==NUll){
//     printf("\n lIst is empty.");
//   }
//   else 
//   {
//     printf("\nList contains: \nRoll: \tName: \tAge \n ");
//     for(ptrthis=header->next;ptrthis!=header;ptrthis=ptrthis->next){
//       printf("%d\t%s\t%d", ptrthis->std.roll, ptrthis->std.name, ptrthis->std.age);
//       ptrthis=ptrthis->next;
//     } while (ptrthis!=header->next);// until we reach the first node again
//   }
// }
// void main(){
//   char ch;
//   while (1){
//     printf("Select your option: \n1 Insert at front \n2. Insert at last \n");
//     printf("3. Insert After\n4. Insert before \n5. Remove form front\n");
//     printf("6. Remove from last \n7. Remove any \n8. Display all \n 9. Exit");
//     ch=getche();
//     switch(ch){
//   case '1':insertAtFront();break;
// 	 case '2':insertAtLast();break;
// 	 case '3':insertAfter();break;
// 	 case '4':removeFromFront();break;
// 	 case '5':removeFromLast();break;
// 	 case '6':removeAny();break;
// 	 case '7':display();break;
// 	 case '8':
// 		printf("Good bye");getch();return;
//       }
//       getch();
//    }while(1);
// }

      
    
//     }

//   }
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50
struct Student { // deifning structture
    int rollNo;
    char name[MAX];
    int age;
    struct Student* next; // `next` to store the address of the next student node in the list
};


struct Student* head = NULL; // `head` for holding the address for the 1st student node in list

// Function declaration here
void insertAtFront(int rollNo, const char* name, int age);
void insertAtLast(int rollNo, const char* name, int age);
void insertAfter(int rollNo, const char* name, int age, int key); // key use here to identify the specific student node after or before which  a new student node will be inserted
void insertBefore(int rollNo, const char* name, int age, int key);
void removeFromFront();
void removeFromLast();
void removeAny(int rollNo);
void displayAll();
void exitProgram();

int main() {
    int choice, rollNo, age, key;
    char name[MAX];

    do {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Last\n");
        printf("3. Insert after a Node\n");
        printf("4. Insert before a Node\n");
        printf("5. Remove from Front\n");
        printf("6. Remove from Last\n");
        printf("7. Remove any\n");
        printf("8. Display All\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf_s("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter roll number: ");
                scanf_s("%d", &rollNo);
                printf("Enter name: ");
                scanf_s("%s", name);
                printf("Enter age: ");
                scanf_s("%d", &age);
                insertAtFront(rollNo, name, age);
                break;
            case 2:
                printf("Enter roll number: ");
                scanf_s("%d", &rollNo);
                printf("Enter name: ");
                scanf_s("%s", name);
                printf("Enter age: ");
                scanf_s("%d", &age);
                insertAtLast(rollNo, name, age);
                break;
            case 3:
                printf("Enter roll number: ");
                scanf_s("%d", &rollNo);
                printf("Enter name: ");
                scanf_s("%s", name);
                printf("Enter age: ");
                scanf_s("%d", &age);
                printf("Enter the roll number after which to insert: ");
                scanf_s("%d", &key);
                insertAfter(rollNo, name, age, key);
                break;
            case 4:
                printf("Enter roll number: ");
                scanf_s("%d", &rollNo);
                printf("Enter name: ");
                scanf_s("%s", name);
                printf("Enter age: ");
                scanf_s("%d", &age);
                printf("Enter the roll number before which to insert: ");
                scanf_s("%d", &key);
                insertBefore(rollNo, name, age, key);
                break;
            case 5:
                removeFromFront();
                break;
            case 6:
                removeFromLast();
                break;
            case 7:
                printf("Enter the roll number of the student to remove: ");
                scanf_s("%d", &rollNo);
                removeAny(rollNo);
                break;
            case 8:
                displayAll();
                break;
            case 9:
                exitProgram();
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    } while (choice != 9);

    return 0;
}

//  Function to insert a student node at the front of the circular linked list
void insertAtFront(int rollNo, const char* name, int age) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollNo = rollNo;
    strcpy_s(newStudent->name,sizeof(newStudent->name) ,name );
    newStudent->age = age;

    if (head == NULL) {
        head = newStudent;
        newStudent->next = head;
    } else {
        struct Student* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newStudent->next = head;
        temp->next = newStudent;
        head = newStudent;
    }

    printf("Student with roll number %d inserted at the front.\n", rollNo);
}

// Function to insert a student node at the last of the circular linked list
void insertAtLast(int rollNo, const char* name, int age) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollNo = rollNo;
    strcpy_s(newStudent->name,sizeof(newStudent->name), name);
    newStudent->age = age;

    if (head == NULL) {
        head = newStudent;
        newStudent->next = head;
    } else {
        struct Student* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newStudent;
        newStudent->next = head;
    }

    printf("Student with roll number %d inserted at the last.\n", rollNo);
}

// Function to insert a student node after a specific node in the circular linked list
void insertAfter(int rollNo, const char* name, int age, int key) {
    if (head == NULL) {
        printf("Linked list is empty. Cannot perform insertion.\n");
        return;
    }

    struct Student* temp = head;
    do {
        if (temp->rollNo == key) {
            struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
            newStudent->rollNo = rollNo;
            strcpy_s(newStudent->name,sizeof(newStudent->name), name);
            newStudent->age = age;
            newStudent->next = temp->next;
            temp->next = newStudent;

            printf("Student with roll number %d inserted after %d.\n", rollNo, key);
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Roll number %d not found in the linked list.\n", key);
}

// Function to insert a student node before a specific node in the circular linked list
void insertBefore(int rollNo, const char* name, int age, int key) {
    if (head == NULL) {
        printf("Linked list is empty. Cannot perform insertion.\n");
        return;
    }

    struct Student* temp = head;
    struct Student* prev = NULL;
    do {
        if (temp->rollNo == key) {
            struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
            newStudent->rollNo = rollNo;
            strcpy_s(newStudent->name,sizeof(newStudent->name), name);
            newStudent->age = age;
            newStudent->next = temp;
            if (prev == NULL) {
                // Inserting before the head node
                struct Student* last = head;
                while (last->next != head) {
                    last = last->next;
                }
                last->next = newStudent;
                head = newStudent;
            } else {
                prev->next = newStudent;
            }

            printf("Student withroll number %d inserted before %d.\n", rollNo, key);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    printf("Roll number %d not found in the linked list.\n", key);
}

// Function to remove the student node from the front of the circular linked list
void removeFromFront() {
    if (head == NULL) {
        printf("Linked list is empty. Cannot perform deletion.\n");
        return;
    }

    struct Student* temp = head;
    struct Student* last = head;
    while (last->next != head) {
        last = last->next;
    }

    if (head == last) {
        // Only one student in the linked list
        head = NULL;
    } else {
        head = head->next;
        last->next = head;
    }

    free(temp);
    printf("Student removed from the front.\n");
}

// Function to remove the student node from the last of the circular linked list
void removeFromLast() {
    if (head == NULL) {
        printf("Linked list is empty. Cannot perform deletion.\n");
        return;
    }

    struct Student* temp = head;
    struct Student* prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        // Only one student in the linked list
        head = NULL;
    } else {
        prev->next = head;
    }

    free(temp);
    printf("Student removed from the last.\n");
}

// Function to remove a specific student node from the circular linked list
void removeAny(int rollNo) {
    if (head == NULL) {
        printf("Linked list is empty. Cannot perform deletion.\n");
        return;
    }

    struct Student* temp = head;
    struct Student* prev = NULL;
    do {
        if (temp->rollNo == rollNo) {
            if (temp == head) {
                // Removing the head node
                struct Student* last = head;
                while (last->next != head) {
                    last = last->next;
                }
                head = head->next;
                last->next = head;
            } else {
                prev->next = temp->next;
            }

            free(temp);
            printf("Student with roll number %d removed.\n", rollNo);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    printf("Student with roll number %d not found in the linked list.\n", rollNo);
}

// Function to display all the student nodes in the circular linked list
void displayAll() {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    struct Student* temp = head;
    printf("Circular Linked List of Students:\n");
    printf("Roll No\tName\t\tAge\n");
    do {
        printf("%d\t%s\t\t%d\n", temp->rollNo, temp->name, temp->age);
        temp = temp->next;
    } while (temp != head);
}

// Function to exit the program and free the allocated memory
void exitProgram() {
    struct Student* temp = head;
    struct Student* next;

    if (temp != NULL) {
        do {
            next = temp->next;
            free(temp);
            temp = next;
        } while (temp != head);
    }

    printf("Exiting the program.\n");
}