#include <stdio.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0
#define UP 72
#define DOWN 80
#define ENTER 13
int main()
{
	char choice;
	int selected = 1 ;
	while (TRUE)
	{
		gotoxy(10, 8);
		printf("Select your choice:");
		gotoxy(10, 9);
		if (selected == 1)
			printf("[X] Register");
		else
			printf("[ ] Register");
		gotoxy(10, 10);
		if (selected == 2)
			printf("[X] Remove");
		else
			printf("[ ] Remove");
		gotoxy(10, 11);
		if (selected == 3)
			printf("[X] List");
		else
			printf("[ ] List");
		gotoxy(10, 12);
		if (selected == 4)
			printf("[X] Exit");
		else
			printf("[ ] Exit");
		fflush(stdin);
		choice = getche();
		switch (choice)
		{
		case UP:
			if (selected > 1)
				selected--;
			break;
		case DOWN:
			if (selected < 4)
				selected++;
			break;
		case ENTER:
			switch (selected)
			{
			case 1:
				printf("Call register function.");
				break;
			case 2:
				printf("Call Remove function.");
				break;
			case 3:
				printf("Call List function");
				break;
			case 4:
				return 0;
			}
			getchar();
		}
	}
}