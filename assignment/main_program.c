
#include <stdio.h>
#include "template1.h"
#include "template2.h"

int main(int argc, char** argv) {
  // Read arguments from the command line!
  for(int i = 0 ; i < argc ; ++i ) {
    // what goes in here?
    // or just use _getopt and figure out how to use it
  }

  // Create an array to store our output image in in r,g, and b

  // Create templates based on the arguments that were passed in
  struct template1 myFirstTemplate = getTemplate1();

  // write the data from the template to the coordinates specified by args
  // into the output image array
  
  // write the arraty to the file name specified by the -o option
}

