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
int symbol, score, hit;
int AskRetry, error;
int ship_position[80][2];
int chose_position[15][2];
int bomb_ship[5][2];

int WelcomeMsg (void){
	printf("Welcome to boom-the-battleship. This game will test your skill of guessing and logic thinking.\n");
	printf("In this game you will have to destroy the ship that is scattered all across the map.\n");
	printf("But here is the catch. The ship is invisible!\n");
	printf("Good news is, you only have to destroy 5 ships then the enemy will flee.\n");
	printf("There is three difficulties for you to choose.Without further talking, let's start! Good luck!\n\n" );
}

int Initialize(void){
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
		while (checked == 0){
			ship_x[counter] = 1 + rand()%56;
			ship_y[counter] = 1 + rand()%20;
			checked = 1;
			for(check = 0; check < counter; check++){
				if(ship_y[counter] == ship_y[check]){
					if(ship_x[counter] <= ship_x[check] + 5 && ship_x[counter] >= ship_x[check] - 5){
						checked = 0;
					}
				}
			}
		}
	}
	for(i = 0; i < ship_num; i++){
		ship_position[i][0] = ship_y[i];
		ship_position[i][1] = ship_x[i];
	}
}

int CheckMap(void){
	do{
		error = 0;
		printf("\nEnter location to boom (row, col): ");
		scanf("%d, %d", &row, &col);
		if (row > 20 || col > 60){
			printf("Error! Row or column doesn't exist. Pleas input again.\n");
			error = 1;
		}
	}while (error == 1);
	chose_position[k][0] = row;
	chose_position[k][1] = col;
	hit = 2;
	for(m = 0; m < ship_num; m++){
		if(chose_position[k][0] == ship_position[m][0]){
			if(chose_position[k][1] >= ship_position[m][1] && chose_position[k][1] <= ship_position[m][1] + 4){
				bomb_ship[j][0] = ship_position[m][0];
				bomb_ship[j][1] = ship_position[m][1];
				j++;
				hit = 1;
			}
		}
	}
	k++;
}

int CheckHit(void){
	if(hit == 1)
		return 1;
	else if (hit == 2)
		return 2;
}
int PrintShip(void){
	for (i = 0; i < ship_num; i++){
		printf("\n%d.Coordinates: %d, %d", i, ship_position[i][0], ship_position[i][1]);
	}
	for(m = 0; m < k; m++){
		printf("\n\nChose: %d, %d", chose_position[m][0], chose_position[m][1]);
	}
	for(l = 0; l < j; l++){
		printf("\n\nBOMB: %d, %d", bomb_ship[l][0], bomb_ship[l][1]);
	}
	printf("\nScore: %d", j);
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
			for(n = 0; n < 5; n++){
			if(count_y == bomb_ship[n][0]){
				if(count_x == bomb_ship[n][1]){
					count_x = count_x + 4;
					symbol = 1;
					goto sym;
					}
				}
			}
			for(i = 0; i <= 15; i++){
				if(count_y == chose_position[i][0] && count_x == chose_position[i][1]){
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
		if(k < 10){
			printf("\nExcellent! You are really talented!");
		}
		else if(k >= 10 && k < 13){
			printf("\nGood job! With a little bit more practice you can be better!");
		}
		else if(k > 13 && k < 16){
			printf("\nStill not bad. But you almost failed. Practice more and you can be good at this too.");
		}
	}
	return AskRetry;
}
