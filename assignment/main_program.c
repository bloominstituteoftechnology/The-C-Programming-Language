#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "template1.h"
#include "template5x5.h"

int main(int argc, char** argv) {
  int aflag = 0;
  int bflag = 0;
  char *cvalue = NULL;
  int index;
  int c;

  char* outputFilename;

  opterr = 0;

  while ((c = getopt (argc, argv, "abco:")) != -1)
  {
    switch (c)
    {
      case 'a':
        aflag = 1;
        break;
      case 'b':
        bflag = 1;
        break;
      case 'c':
        cvalue = optarg;
        break;
      case 'o':
        outputFilename = optarg;
        break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        abort ();
    }
  }

  printf ("aflag = %d, bflag = %d, cvalue = %s\n",
          aflag, bflag, cvalue);

  for (index = optind; index < argc; index++)
    printf ("Non-option argument %s\n", argv[index]);
  // Read arguments from the command line!

  // Create an array to store our output image in in r,g, and b
//  int output[1024][768][3];
//  for(int i = 0 ; i < 1024 ; ++i) {
//    for(int j = 0 ; j < 768 ; ++j ) {
//      output[i][j][0] = 0;
//      output[i][j][1] = 0;
//      output[i][j][2] = 255;
//    }
//  }
//  for (int index = optind; index < argc; index++)
//    printf ("Incoming template arguments: %s\n", argv[index]); 

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
  FILE* f = fopen(outputFilename, "w");
  fprintf(f, "P3\n 1024 768\n");
  for(int i = 0 ; i < 1024 ; ++i) {
    for(int j = 0 ; j < 768 ; ++j ) {
      //fprintf(f, "%d %d %d ", output[i][j][0], output[i][j][1], output[i][j][2]);
    }
  }
  fclose(f);
}

