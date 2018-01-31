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
void print_ui() {

}

int main(int argc, char *argv[]) {
  /* Your code here */
  // check if no input was passed to our program
  int clear = 0;
  char *word = NULL;
  char *guessed = NULL;
  if (argc == 1) {
    printf("Usage: %s [-c] word\n", argv[0]);
    return 1;
  }
  // check if user typed in a flag 
  if (argv[1][0] == '-') {
    // check if user typed in the '-c' flag
    if (argv[1][1] == 'c') {
      // clear the screen;
      clear = 1;
    }
    word = argv[2];
  } else {
    word = argv[1];
  }
  // allocate to hold guessed letters
  // use calloc instead of malloc since calloc initializes memory 
  // with all 0s
  guessed = calloc(strlen(word) + 1, sizeof(char));

  // print some graphics (optional);
  printf("Hangman");

  // start our game loop
  while(1) {
    // print our UI
    print_ui();

    // read user input 
    //guess = read_input();

    // handle if user wants to exit the game 
    if (strlen(guess) > 1){
    //  if strcmp(guess, "exit") == 0) {
        // correct guess 
        printf("You guessed the whole word! You win\n")
        free(guess);
        break;
  //    } else {
        printf("Nope!\n");
        // increase the strike count
      }
    }
  }

  return 0;
}