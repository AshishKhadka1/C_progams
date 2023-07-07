#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define UP 'w'
#define DOWN 's'
#define ENTER '\r'

void clearScreen() {
    printf("\033[2J\033[H");
}

void displayMenu(int selected) {
    clearScreen();
    printf("Select your choice:\n\n");
    printf("%s Register\n", (selected == 1) ? "[X]" : "[ ]");
    printf("%s Remove\n", (selected == 2) ? "[X]" : "[ ]");
    printf("%s List\n", (selected == 3) ? "[X]" : "[ ]");
    printf("%s Exit\n", (selected == 4) ? "[X]" : "[ ]");
}

int main() {
    char choice;
    int selected = 1;

    while (TRUE) {
        displayMenu(selected);

        choice = getchar();

        switch (choice) {
            case UP:
                if (selected > 1)
                    selected--;
                break;
            case DOWN:
                if (selected < 4)
                    selected++;
                break;
            case ENTER:
                switch (selected) {
                    case 1:
                        printf("Call register function.\n");
                        break;
                    case 2:
                        printf("Call Remove function.\n");
                        break;
                    case 3:
                        printf("Call List function.\n");
                        break;
                    case 4:
                        return 0;
                }
                getchar(); // Consume the newline character
        }
    }

    return 0;
}
