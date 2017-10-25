#include <stdio.h>
#include <battleship.h>

int diff;

int main (void){
	WelcomeMsg();
	printf("\nChoose your difficulty: (1-Beginner. 2-Intermediate, 3-Advance)");
	scanf("%d", &diff);
	SetShip(diff);
	
}