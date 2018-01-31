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
  // check if no input was passed to our program
  int clear = 0;
  
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
  }
}