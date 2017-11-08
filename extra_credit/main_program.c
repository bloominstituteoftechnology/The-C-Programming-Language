#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "template1.h"
#include "lambda_template_ascii.h"

#define IMAGE_WIDTH 1024
#define IMAGE_HEIGHT 768

int main(int argc, char** argv) {
  // Read arguments from the command line!
  int index;
  int c;
  char* outputFilename;
  opterr = 0;
  while ((c = getopt (argc, argv, "abco:")) != -1)
  {
    switch (c)
    {
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

  // Create an array to store our output image in greyscale
  int* columns[IMAGE_WIDTH];
  for(int i = 0 ; i < IMAGE_WIDTH ; ++i) {
    columns[i] = malloc(IMAGE_HEIGHT*sizeof(int));
  } 
  // Stores an initial value of 0 in each element in the array
  for(int i = 0 ; i < IMAGE_WIDTH ; ++i) {
    for(int j = 0 ; j < IMAGE_HEIGHT ; ++j) {
      columns[i][j] = 0;
    }
  }

  // Create templates based on the arguments that were passed in
  // This is using getopt. If you parse argc and argv by yourself, 
  // these values should start at argv[3]
  for (int index = optind; index < argc; index++) {
    char* name = argv[index];
    printf("Index + 1 ? %d %d\n", index+1, argc);
    if(index+2 >= argc) break;
    int xpos = atoi(argv[index+1]);
    int ypos = atoi(argv[index+2]);
    printf("Template arg: %s %d %d\n", name, xpos, ypos);
         
    // write the data from the template to the coordinates specified by args
    // into the output image array
    printf("%s %d %d\n", name, xpos, ypos); 

    if(strcmp(name, "duck") == 0) {
      struct template1 myFirstTemplate = getTemplate1();
      // error checking: is it legal to write the memory at xpos/ypos?
      if(myFirstTemplate.size + xpos > IMAGE_WIDTH) {
        puts("Template dimensions unusable, skipping.");
        continue;
      }

      for(int j = 0; j < myFirstTemplate.size; j++) {
        for (int i = 0; i < myFirstTemplate.size; i++) {
          columns[xpos+i][ypos+j] += myFirstTemplate.stamp[i][j] * 255;
        }
      }
    }
    else if(strcmp(name, "lambda") == 0) {
      struct template2 myFirstTemplate = getTemplate2();
      // error checking: is it legal to write the memory at xpos/ypos?
      if(myFirstTemplate.size + xpos > IMAGE_WIDTH) {
        puts("Template dimensions unusable, skipping.");
        continue;
      }

      for(int j = 0; j < myFirstTemplate.size; j++) {
        for (int i = 0; i < myFirstTemplate.size; i++) {
          columns[xpos+i][ypos+j] += myFirstTemplate.stamp[i][j] * 255;
        }
      }
    }

    index = index + 2;
  }
  
  /*
  struct template2 mySecondTemplate = getTemplate2();
  for (int i = 0; i < mySecondTemplate.size; i++) {
    for(int j = 0; j < mySecondTemplate.size; j++) {
      printf("%d", mySecondTemplate.stamp[i][j]);
    }
    printf("\n");
  }
  */
  
  // write the arraty to the file name specified by the -o option
  FILE* f = fopen(outputFilename, "w");
  fprintf(f, "P3\n%d %d\n255\n", IMAGE_WIDTH, IMAGE_HEIGHT);
  for(int i = 0 ; i < IMAGE_HEIGHT ; ++i) {
    for(int j = 0 ; j < IMAGE_WIDTH ; ++j ) {
      fprintf(f, "%d %d %d ", columns[i][j], columns[i][j], columns[i][j]);
      //fprintf(f, "%d %d %d ", output[j*IMAGE_WIDTH+i*3+0], output[j*IMAGE_WIDTH+i*3+1], output[j*IMAGE_WIDTH+i*3+2]);
    }
  }
  fclose(f);
  
  for(int i = 0 ; i < IMAGE_WIDTH ; ++i) {
    free(columns[i]);
  } 
}

