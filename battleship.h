#include <stdio.h>

int count_x;
int count_y = 1;
int x = 1;
int y = 1;
int ship_num, counter = 0;
int top = 1;
int i = 0, j = 0;
int ship_x[80], ship_y[80];
int row[60], col[60];
int bomb_x[60], bomb_y[60];
int check, width, checked;
int init_x, init_y;

int WelcomeMsg (void){
	printf("Welcome to boom-the-battleship. This game will test your skill of guessing and logic thinking.\n There is three difficulties for you to choose.Without further talking, let's start!" );
}

int PrintMap (void){
	printf("            %d", top);
	while(top <= 5){
		top++;
		printf("         %d", top);
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
	while (count_y <= 20){
		count_x = 1;
		printf("\n");
		if (count_y < 10){
			printf(" ");
		}
		printf("%d", y);
		printf(" ");
		while(count_x <= 60){
			if (count_x == col[i] && count_y == row[i]){
				printf(" ");
			}
			else if (count_x == bomb_x[i] && count_y == bomb_y[i]){
				printf("o");
			}
			else
				printf("#");
			i++;
			count_x++;
		}	
		count_y ++;
		y++;
	}
}


int SetShip(int diff){
	if(diff == 1)
		ship_num = 80;
	else if( diff == 2)
		ship_num = 50;
	else if(diff == 3)
		ship_num = 20;
	srand(time(NULL));
	for(counter = 0; counter < ship_num; counter++){
		checked = 0;
		while (!checked){
			ship_x[counter] = 1 + rand()%60;
			ship_y[counter] = 1 + rand()%20;
			checked = 1;
			for(width = 0; width < 6; width++){
				for(check = 0; check < counter; check++){
					if(ship_y[counter] == ship_y[check] && ship_x[counter] == (ship_x[check] + width)){
							checked = 0;
					}
				}
			}
		}
	}
}

int CheckMap(void){
	printf("Enter location to boom (row, rol): ");
	scanf("%d, %d", &row, &col);
}

int PrintShip(void){
	for (i = 0; i < ship_num; i++){
	printf("\n%d.Coordinates: %d, %d", i, ship_y[i], ship_x[i]);
	}
}

int PrintMaps(void){
	printf("            %d", top);
	while(top <= 5){
		top++;
		printf("         %d", top);
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
	while (count_y <= 20){
		count_x = 1;
		printf("\n");
		if (count_y < 10){
			printf(" ");
		}
		printf("%d", y);
		printf(" ");
		i = 0;
		j = 0;
		while(count_x <= 60){
			if (count_y == row[i]){
				while(j <= 60){
					if (count_x == col[j]){
						printf(" ");
					}
					j++;
				}
			}
			else if (count_y == ship_y[i]){
				while(j <= 60){
					if(count_x == ship_x[j]){
						printf("o");
					}
					j++;
				}
			}
			else
				printf("#");
			i++;
			count_x++;
		}	
		count_y ++;
		y++;
	}
}
