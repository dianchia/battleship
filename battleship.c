#include <stdio.h>
# include <battleship.h>
#include <stdlib.h>

int diff, i;
char retry[1];
int AskRetry;

int main(void){
	do{
		Initialize();		
		WelcomeMsg();
		printf("Please choose a difficulty: (1-beginner, 2-intermediate, 3-advance)");
		scanf("%d", &diff);
		SetShip(diff);
		int bomb_count = 15;
		while(bomb_count > 0){
			PrintMaps();
			PrintShip();
			printf("\n\nYou still have %d bomb left.", bomb_count);
			CheckMap();
			bomb_count--;
			system("cls");
			AskRetry = CheckScore();
			if(AskRetry == 1){
				break;
			}
		}
		if(AskRetry == 1){
			printf("Do you wish to retry? (Y or N)");
			scanf("%1s", retry);
		}
		else{
			printf("\nSorry, you have ran out of bomb. Try again? (Y or N) ");
			scanf("%1s", retry);
		}

	}while(retry[0] == 'Y' || retry[0] == 'y');
	printf("\nThank You for playing this game! Hope to see you again soon.");
	return 0;
}
