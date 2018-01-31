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
	char ans[] = {'/','h', 'a', 'n', 'g', 'm', 'a', 'n'};
	char guess[1];
	char *usedLetters = malloc(sizeof(char) * 26);
	char corLet[] = {'/','_', '_','_','_','_','_','_'}; 
	int counter = 0;
	int arrCounter = 0;
	int hangmanY = 0;
	int isGameDone = 0;

	while(isGameDone != 1) {
		// prints out letters player used
		printf("letters Used: ");
		for (int i = 1; i < arrCounter; i++) {
			printf("%c, ", usedLetters[i]);	
		}
		// prints out correct letters 
		printf("\n");
		printf("Correct Letters so Far: ");
		for(int i = 1; i < sizeof(ans)/sizeof(ans[0]); i++) {
			printf("%c ", corLet[i]);
		};
		printf("\n");
		//ask player for a letter
  	printf("enter a letter: ");	
		scanf("%s", guess);	
		
		for (int i = 1; i < sizeof(ans)/sizeof(ans[0]); i++) {
			// if guess char matches a char in array
			if(ans[i] == guess[0]) {
				// add it to the correct array;
				corLet[i] = guess[0];
				// counts how many spots char was correct for
 				counter +=1;
			} 
			// if char was correct for one spot and end of answer array is reached 
			if ((i == sizeof(ans)/sizeof(ans[0]) - 1) && counter == 1) {
				// tell player they got one correct
				printf("There is %d %c.\n\n", counter, guess[0]);
				// iterate through the correct array and check if all matches between correct and answer array
				for(int i = 1; i < sizeof(ans)/sizeof(ans[0]); i++) {
					// break if the correct array and answer array has differences in their elements and continue the game
					if (ans[i] != corLet[i]) {
						break;
					}
					// if no differences were found up the end of both arrays and player wins
					if (i == sizeof(ans)/sizeof(ans[0]) -1) {
						// display the result
						printf("Correct Letters so Far: ");
						for(int i = 1; i < sizeof(ans)/sizeof(ans[0]); i++) {
							printf("%c ", corLet[i]);
						};
						printf("\n");
						// win and exit the game by closing while loop by setting value to 1
						printf("You Win!! \n");
						isGameDone = 1;
					}
				}
			}
			// if end of array is reached no correct counter is greater than 1
			if ((i == sizeof(ans)/sizeof(ans[0]) - 1) && counter > 1) {
				// let player know they got x many right 
				printf("There are %d %c's.\n\n", counter, guess[0]);
				// iterate through the correct array and check if all matches between correct and answer array
				for(int i = 1; i < sizeof(ans)/sizeof(ans[0]); i++) {
					// break if the correct array and answer array has differences in their elements and continue the game
					if (ans[i] != corLet[i]) {
						break;
					}
					// if no differences were found up the end of both arrays and player wins
					if (i == sizeof(ans)/sizeof(ans[0]) -1) {
						// display the result
						printf("Correct Letters so Far: ");
						for(int i = 0; i < sizeof(ans)/sizeof(ans[0]); i++) {
							printf("%c ", corLet[i]);
						};
						printf("\n");
						// win and exit the game by closing while loop by setting value to 1
						printf("You Win!! \n");
						isGameDone = 1;
					}
				}
			}
			// if end of array is reached and no matches have been found
			if ((i == sizeof(ans)/sizeof(ans[0]) - 1) && counter == 0) {
				// let player know no matches have been found
				printf("There is no %c.\n\n", guess[0]);
				for (int i = 1; i < 7; i++) {
					// print out the hangman 
					for (int j = hangmanY; j < hangmanY + 10 ; j++){
						printf("%c",HANG_STATES[i][j]);
					}
					printf("\n");
				}
				// if hangman reaches to the end, player loses and close while loop by setting value to 1 to end game
				if(hangmanY == 80){
					printf("Sorry, You lose.");
					isGameDone = 1;
					printf("\n");
				}
				hangmanY += 10;
			}
		}
		// add the guess to the used letters array which will print out every loop
		usedLetters[arrCounter] = guess[0];
		// increment array counter every round to increase capacity of used letters array
		arrCounter += 1;
		// reset match counter after every looping
		counter = 0;
	}
	// free memory
	free(usedLetters);
  return 0;
}