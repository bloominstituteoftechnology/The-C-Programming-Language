#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
  const int width = 1024, height = 768;
  // const int width = 40, height = 30;

  /* maximum greyscale value
  3 x 8-bit color channels
  2^8 = 256 ==> 0 - 255
  0 = black, 255 = white */
  const int max = 255;

  FILE *imageFile = fopen("P6.ppm", "wb"); /* b - binary mode */
  fprintf(imageFile, "P6\n%d %d\n%d\n", width, height, max);

  int col, row;

  for (row = 0; row < height; ++row) {
    for (col = 0; col < width; ++col) {
      static unsigned char color[3];
      /* 40 x 30 small example */
      // color[0] = (col * max) / width; /* red */
      // color[1] = (col * max) / width; /* green */
      // color[2] = (col * max) / width; /* blue */
      /* 4x3 image blocks */
      // color[0] = col % max;          /* red */
      // color[1] = row % max;          /* green */
      // color[2] = (col * row) % max;  /* blue */
      /* greyscale gradient 1 - COLUMN
       * Left to Right from BLACK to WHITE */
      // color[0] = (col * max) / width; /* red */
      // color[1] = (col * max) / width; /* green */
      // color[2] = (col * max) / width; /* blue */
      /* greyscale gradient 2 - ROW
       * Top to Bottom from BLACK to WHITE */
      // color[0] = (row * max) / width; /* red */
      // color[1] = (row * max) / width; /* green */
      // color[2] = (row * max) / width; /* blue */
      /* awesome color fields */
      color[0] = fabs(floor((row * max / 1024 - 35)));  /* red */
      color[1] = fabs(floor((col * max / 1024 - 112))); /* green */
      color[2] = fabs(floor((col * max / 1024 - 92)));  /* blue */

      fwrite(color, 1, 3, imageFile);
    }
  }

  fclose(imageFile);

  return 0;
}
