#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "template1.h"
#include "template5x5.h"
FILE * fp;

int mem[1600][1600][3];

void pixel_write(int i, int j, int r, int g, int b) {
  static unsigned char color[3];
  color[0] = r;
  color[1] = g;
  color[2] = b;
  fwrite(color, 1, 3, fp);
}

void write_pic(struct template1 temp, int x, int y) {
  fp = fopen("output.ppm", "w");
  fprintf(fp, "P6\n %i %i 255\n", 1600, 768);
    for (int i = 0; i < 1600; i++) {
      for(int j=  0; j < 1600; j++) {
        if (i >= x && i < (x + temp.size) && j >= y && j < (y + temp.size) && temp.stamp[i - x][j - y])
        {
          pixel_write(i, j , temp.r, temp.g, temp.b);
          mem[i][j][0] = temp.r;
          mem[i][j][1] = temp.g;
          mem[i][j][2] = temp.b;
        } else {
          pixel_write(i, j, mem[i][j][0], mem[i][j][1], mem[i][j][2]);
        }
      }
    }
}

int main(int argc, char** argv) {
  for (int i = 0; i < 1600; i++) {
      for(int j=  0; j < 1600; j++) {
        mem[i][j][0] = 255;
        mem[i][j][1] = 255;
        mem[i][j][2] = 255;
      }
    }

  struct template1 myFirstTemplate = getTemplate1();
  struct template1 square = getSquareTemplate();
  struct template1 l = getLTemplate();
  struct template1 circle = getCircleTemplate();

  for (int i = 1; i < argc; i += 3) {
    if (strcmp(argv[i], "square") == 0) write_pic(square, atoi(argv[i+1]), atoi(argv[i+2]));
    if (strcmp(argv[i], "l") == 0) write_pic(l, atoi(argv[i+1]), atoi(argv[i+2]));
    if (strcmp(argv[i], "circle") == 0) write_pic(circle, atoi(argv[i+1]), atoi(argv[i+2]));
  }
  fclose(fp);
  for (int i = 0; i < 1600; i++) {
    for(int j=  0; j < 1600; j++) {
        mem[i][j][0] = 255;
        mem[i][j][1] = 255;
        mem[i][j][2] = 255;
    }
  }
  return 0;
}

// make program by clang main_program.c template1.c -o main_program
// 3 templates to choose from.. l, square, and circle each 200 X 200
// run program like ./main_program  l 100 500 square 200 300 circle 200 600
// this will make a file called output.ppm of the stamps and at their chosen location (the following numbers)