#include <stdio.h>

int count_x;
int count_y = 1;
int x = 1;
int y = 1;
int ship_num, counter = 1;
int ship_x;
int top = 1;


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
		if (count_y < 10)
			printf(" ");
		printf("%d", y);
		printf(" ");
		while (count_x <= 60){
			printf("#");
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
	
	while (counter <= ship_num){
		srand(time(NULL));
		ship_x = 1 + rand();

	}
}
