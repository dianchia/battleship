#include <stdio.h>
#include <battleship.h>
#include <stdlib.h>

int diff, i;
char retry[1];
int AskRetry;
int hit;

int main(void){
	WelcomeMsg();
	do{
		Initialize();		
		printf("Please choose a difficulty: (1-beginner, 2-intermediate, 3-advance)");
		scanf("%d", &diff);
		SetShip(diff);
		int bomb_count = 15;
		while(bomb_count > 0){
			PrintMaps();
			PrintShip();
			switch(hit){
				case 1 : printf("\nYou hit a ship! %d more left.\n", (5-j));
				break;
				case 2 : printf("\nToo bad, you missed. There is no ship at that coordinate.\n");
				break;
				default : printf("\n");
				break;
			}
			printf("\n\nYou still have %d bomb left.\n", bomb_count);
			CheckMap();
			hit = CheckHit();
			bomb_count--;
			system("cls");
			AskRetry = CheckScore();
			if(AskRetry == 1){
				break;
			}
		}
		if(AskRetry == 1){
			printf("\nDo you wish to retry? (Y or N)");
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
