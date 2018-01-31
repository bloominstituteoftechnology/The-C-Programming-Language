#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char HANG_STATES[7][10 * 9] = 
{
	"             +         +----     +----     +----     +----     +----     +----     +----  ",
	"             |         |         |   O     |   O     |   O     |   O     |   O     |   O  ",
	"             |         |         |         |   +     | --+     | --+--   | --+--   | --+--",
	"             |         |         |         |   |     |   |     |   |     |   |     |   |  ",
	"             |         |         |         |         |         |         |  /      |  / \\ ",
	"             |         |         |         |         |         |         |         |      ",
	"/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   "
};

int main(int argc, char *argv[]) {
  /* Your code here */
	char *ans = malloc(sizeof(char) * 40);
	ans[0] = 'h'; 
	ans[1] = 'a'; 
	ans[2] = 'n'; 
	ans[3] = 'g';
//	ans[4] = 'm'; 
//	ans[5] = 'a'; 
//	ans[6] = 'n';
	char guess[1];
	char *usedLetters = malloc(sizeof(char) * 26);
	char *corLet = malloc(sizeof(char) * 7);
	corLet[0] = '_'; 
	corLet[1] = '_'; 
	corLet[2] = '_'; 
	corLet[3] = '_'; 
//	corLet[4] = '_'; 
//	corLet[5] = '_'; 
//	corLet[6] = '_';
	int counter = 0;
	int arrCounter = 0;
	int hangmanY = 0;
	int isGameDone = 0;

	while(isGameDone != 1) {
		// printf("%c\n", answer[0]);
		printf("letters Used: ");
		for (int i = 0; i < arrCounter; i++) {
			printf("%c, ", usedLetters[i]);	
		}
		printf("\n");
		printf("Correct Letters so Far: ");
		for(int i = 0; i < sizeof(ans); i++) {
			printf("%c ", corLet[i]);
		};
		printf("\n");
  	printf("enter a letter: ");	
		scanf("%s", guess);	

		// printf("%s\n", guess);
		// printf("%d",sizeof(answer));
		for (int i = 0; i < sizeof(ans); i++) {
			// printf("%c\n",answer[i]);
			if(ans[i] == guess[0]) {
				corLet[i] = guess[0];
 				counter +=1;
			} 
			if ((i == sizeof(ans) - 1) && counter == 1) {
				printf("There is %d %c.\n\n", counter, guess[0]);	
				for(int i = 0; i < sizeof(ans); i++) {
					if (ans[i] != corLet[i]) {
						break;
					} 
					if (i == sizeof(ans) -1) {
						printf("Correct Letters so Far: ");
						for(int i = 0; i < sizeof(ans); i++) {
							printf("%c ", corLet[i]);
						};
						printf("\n");
						printf("You Win!! \n");

						isGameDone = 1;
					}
				}
			}
			if ((i == sizeof(ans) - 1) && counter > 1) {
				printf("There are %d %c's.\n\n", counter, guess[0]);
				for(int i = 0; i < sizeof(ans); i++) {
					if (ans[i] != corLet[i]) {
						break;
					}
					if (i == sizeof(ans) -1) {
						printf("Correct Letters so Far: ");
						for(int i = 0; i < sizeof(ans); i++) {
							printf("%c ", corLet[i]);
						};
						printf("\n");
						printf("You Win!! \n");
						isGameDone = 1;
					}
				}
			}
			if ((i == sizeof(ans) - 1) && counter == 0) {
				printf("There is no %c.\n\n", guess[0]);
				for (int i = 0; i < 7; i++) {
					for (int j = hangmanY; j < hangmanY + 10 ; j++){
						printf("%c",HANG_STATES[i][j]);
					}
					printf("\n");
				}
				if(hangmanY == 80){
					printf("Sorry, You lose.");
					isGameDone = 1;
					printf("\n");
				}
				hangmanY += 10;
			}
		}
		usedLetters[arrCounter] = guess[0];
		arrCounter += 1;
		counter = 0;
	}
	free(ans), free(usedLetters), free(corLet);
  return 0;
}