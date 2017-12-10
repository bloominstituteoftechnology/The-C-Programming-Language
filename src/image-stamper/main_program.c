#include <stdio.h>

#include "template1.h"
#include "template5x5.h"

int main(int argc, char** argv) {
  // Read arguments from the command line!
  for(int i = 0 ; i < argc ; ++i ) {
    // what goes in here?
    // or just use _getopt and figure out how to use it
  }

  // Create an array to store our output image in in r,g, and b

  // Create templates based on the arguments that were passed in
  struct template1 myFirstTemplate = getTemplate1();

  for (int i = 0; i < myFirstTemplate.size; i++) {
    for(int j= 0; j < myFirstTemplate.size; j++) {
      printf("%d", myFirstTemplate.stamp[i][j]);
    }
    printf("\n");
  }

  // write the data from the template to the coordinates specified by args
  // into the output image array
  
  // write the arraty to the file name specified by the -o option
}

