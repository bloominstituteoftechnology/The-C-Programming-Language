#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "template1.h"
#include "template5x5.h"
FILE * fp;

int mem[1600][1600];

void pixel_write(int i, int j, int r, int g, int b) {
    static unsigned char color[3];
    color[0] = r;
    color[1] = g;
    color[2] = b;
    fwrite(color, 1, 3, fp);
}

void write_pic(struct template1 temp, int x, int y) {
  fp = fopen("output.ppm", "wb");
  fprintf(fp, "P6\n %i %i 255\n", 1600, 768);
      for (int i = 0; i < 1600; i++) {
      for(int j=  0; j < 1600; j++) {
        if (i >= x && i < (x + temp.size) && j >= y && j < (y + temp.size) && temp.stamp[i - x][j - y])
        {
          pixel_write(i, j , 0, 0, 0);
          mem[i][j] = 0;
        } else {
          pixel_write(i, j, mem[i][j], mem[i][j], mem[i][j]);
        }
      }
    }
}

int main(int argc, char** argv) {
  // Read arguments from the command line!
  for (int i = 0; i < 1600; i++) {
      for(int j=  0; j < 1600; j++) {
          mem[i][j] = 255;
        }
      }

  // Create an array to store our output image in in r,g, and b

  // Create templates based on the arguments that were passed in

  struct template1 myFirstTemplate = getTemplate1();
  struct template1 square = getSquareTemplate();
  struct template1 l = getLTemplate();
  for (int i = 1; i < argc; i += 3) {
    if (strcmp(argv[i], "square") == 0) write_pic(square, atoi(argv[i+1]), atoi(argv[i+2]));
    if (strcmp(argv[i], "l") == 0) write_pic(l, atoi(argv[i+1]), atoi(argv[i+2]));
  }
     fclose(fp);

     for (int i = 0; i < 1600; i++) {
      for(int j=  0; j < 1600; j++) {
          mem[i][j] = 255;
        }
      }



  // write the data from the template to the coordinates specified by args
  // into the output image array
  
  // write the array to the file name specified by the -o option


  return 0;
}

