#include <stdio.h>
#include <stdlib.h>
int count_x;
int count_y;
int x = 1;
int y = 1;
int ship_num, counter = 0;
int top = 1;
int i, j, k, l, m, n;
int ship_x[80], ship_y[80];
int row, col;
int bomb_x[5], bomb_y[5];
int check, width, checked;
int chose_x[15], chose_y[15];
int symbol, score;
int AskRetry;

int WelcomeMsg (void){
	printf("Welcome to boom-the-battleship. This game will test your skill of guessing and logic thinking.\n There is three difficulties for you to choose.Without further talking, let's start!\n\n" );
}

int Initialize(void){
	memset(ship_x, 0, 80* sizeof(ship_x[0]));
	memset(ship_y, 0, 80* sizeof(ship_y[0]));
	memset(bomb_x, 0, 5* sizeof(bomb_x[0]));
	memset(bomb_y, 0, 5* sizeof(bomb_y[0]));
	memset(chose_x, 0, 15* sizeof(chose_x[0]));
	memset(chose_y, 0, 15* sizeof(chose_y[0]));
	score = 0;
	j = 0;
	k = 0;
	m = 0;
}

int SetShip(int diff){
	switch(diff){
		case 1 : ship_num = 80;
		break;
		case 2 : ship_num = 50;
		break;
		case 3 : ship_num = 20;
		break;
	}
	srand(time(NULL));
	for(counter = 0; counter < ship_num; counter++){
		checked = 0;
		while (!checked){
			ship_x[counter] = 1 + rand()%56;
			ship_y[counter] = 1 + rand()%20;
			checked = 1;
			for(check = 0; check < counter; check++){
				for(width = 0; width < 6; width++){
					if(ship_y[counter] == ship_y[check] && ship_x[counter] == ship_x[check] + width){
						checked = 1;
					}
				}
			}
		}
	}
}

int CheckMap(void){
	printf("\nEnter location to boom (row, col): ");
	scanf("%d, %d", &row, &col);
	chose_y[k] = row;
	chose_x[k] = col;
	k++;
	for(i = 0; i < ship_num; i++){
		if(row == ship_y[i] && col == ship_x[i]){
			bomb_x[j] = ship_x[i];
			bomb_y[j] = ship_y[i];
			j++;
		}
	}
}

int PrintShip(void){
	for (i = 0; i < ship_num; i++){
	printf("\n%d.Coordinates: %d, %d", i, ship_y[i], ship_x[i]);
	}
	for(m = 0; m < k; m++){
		printf("\n\nChose: %d, %d", chose_y[m], chose_x[m]);
	}
	for(l = 0; l < j; l++){
		printf("\n\nBOMB: %d, %d", bomb_y[l], bomb_x[l]);
	}
	printf("Score: %d", j);
}

int PrintMaps(void){
	y = 1;
	top = 1;
	AskRetry = 0;
	printf("%13d", top);
	while(top <= 5){
		top++;
		printf("%10d", top);
	}
	top = 1;
	printf("\n   ");
	while(top <= 6){
		x = 1;
		while(x <= 9){
			printf("%d", x);
			x++;
		}
		printf("0");
		top++;
	}
	for(count_y = 1; count_y <= 20; count_y++){
		printf("\n");
		printf("%2d", y);
		printf(" ");
		for (count_x = 1; count_x <= 60; count_x++){
			for(i = 0; i <= 15; i++){
				if(count_y == chose_y[i] && count_x == chose_x[i]){
					for(n = 0; n < 5; n++){
						if(count_y == bomb_y[n] && count_x == bomb_x[n]){
							count_x = count_x + 4;
							symbol = 1;
							goto sym;
						}
					}
					symbol = 2;
					goto sym;
				}
				else
					symbol = 0;
			}
			sym: 
			switch(symbol){
				case 0 : printf("#");
				break;
				case 1 : printf("ooooo");
				break;
				case 2: printf(" ");
				break;
			}
		}
		y++;
	}
}

int CheckScore(void){
	if (j == 5){
		printf("Congratulation! You have won! You did it in %d attempts!\n", k);
		AskRetry = 1;
	}
	return AskRetry;
}

