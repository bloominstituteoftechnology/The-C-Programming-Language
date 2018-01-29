#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "template1.h"
#include "template5x5.h"

struct inputSet {
  char * name;
  int width;
  int height;
};

int main(int argc, char** argv) {
  // Read arguments from the command line!

  char *outputPPM = NULL;
  int index;
  int c;

  opterr = 0;

  while ((c = getopt (argc, argv, "c:")) != -1)
    switch (c)
      {

      case 'o':
        outputPPM = optarg;
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
  if (((argc - optind) % 3) != 0)
  {
    fprintf(stderr, "input args must be in sets of 3 <char * name> <int width> <int height>");
    return 1;
  }
  if (argc - optind == 0)
  {
    fprintf(stderr, "must be at least 1 set of 3 args  <char * name> <int width> <int height>");
    return 1;
  }
  const int inputSetCount = (optind / 3);
  const struct inputSet ** inputSets = (struct inputSet **)malloc(inputSetCount * sizeof(void *)); 

  for(int i = optind, j = 0 ; i < argc ; i+=3, j++ ) {
    struct inputSet * iS = (struct inputSet *)malloc(sizeof(struct inputSet));
    iS->name = argv[i];
    iS->width = atoi(argv[i+1]);
    iS->height = atoi(argv[i+ 2]);
    inputSets[i] = iS;
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

