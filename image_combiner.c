#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
  const int width = 40, height = 30;

  /* WRITE PPM HEADER INFORMATION */
  FILE *imageFile = fopen("P3_40x30.ppm", "w"); /* ascii mode - NOT binary*/
  int col, row;

  /* NESTED FOR LOOP COLOR MAGICKS */
  for (row = 0; row < height; ++row) {
    for (col = 0; col < width; ++col) {

      if (col == width - 1) {
        fprintf(imageFile, "%d %d %d\n", red, green, blue);
      } else {
        fprintf(imageFile, "%d %d %d  ", red, green, blue);
      }
    }
  }

  // for rows 40 thru 50 by colums 100 through 110 write rgb values 0, 0, 0 read in another PPM files

  fclose(imageFile);

  return 0;
}
