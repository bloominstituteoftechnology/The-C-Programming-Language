#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
  const int width = 1024, height = 768;
  // const int width = 40, height = 30;

  /*******************************************
   * 3 x 8-bit color channels
   * maximum greyscale value per color channel
   * 2^8 = 256 ==> 0 - 255
   * 0 = black, 255 = white
   * NOTE: (max + 1) per the fencepost problem
   ******************************************/
  const int max = 255;

  /* WRITE PPM HEADER INFORMATION */
  FILE *imageFile = fopen("P3.ppm", "w"); /* ascii mode - NOT binary*/
  fprintf(imageFile, "P3\n%d %d\n%d\n", width, height, max);

  int col, row;

  /* NESTED FOR LOOP COLOR MAGICKS */
  for (row = 0; row < height; ++row) {
    for (col = 0; col < width; ++col) {
      /* 40 x 30 small example greyscale - switch lines 6 and seven *****/
      // int red = (col * (max + 1)) / width;
      // int green = (col * (max + 1)) / width;
      // int blue = (col * (max + 1)) / width;
      /* 4x3 image blocks ***********************************************/
      // int red = col % (max + 1);
      // int green = row % (max + 1);
      // int blue = (col * row) % (max + 1);
      /* greyscale gradient 1 - COLUMN **********************************
       * Left to Right from BLACK to WHITE ******************************/
      // int red = (col * (max + 1)) / width;
      // int green = (col * (max + 1)) / width;
      // int blue = (col * (max + 1)) / width;
      /* greyscale gradient 2 - ROW *************************************
       * Top to Bottom from BLACK to WHITE ******************************/
      // int red = (row * (max + 1)) / width;
      // int green = (row * (max + 1)) / width;
      // int blue = (row * (max + 1)) / width;
      /* AWESOME COLOR FIELDS *******************************************/
      int red = fabs(floor((row * (max + 1) / width - 35)));
      int green = fabs(floor((col * (max + 1) / width - 112)));
      int blue = fabs(floor((col * (max + 1) / width - 92)));

      /*****************************************************
       * WRITE PPM DATA
       * adds a newline at the end of each ROW
       * TWO spaces in between COLumns
       * (per PPM formatting options for easier readability)
       *****************************************************/
      if (col == width - 1) {
        fprintf(imageFile, "%d %d %d\n", red, green, blue);
      } else {
        fprintf(imageFile, "%d %d %d  ", red, green, blue);
      }
    }
  }

  fclose(imageFile);

  return 0;
}
