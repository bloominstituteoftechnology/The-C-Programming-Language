/* **************************************************************************************************
 * templatemker.c
 * --------------
 *
 * OCTOBER 6, 2017
 * VERSION 0.1
 *
 ***************************************************************************************************/

#include "./simple_image_machine.h"

int main(int argc, char** argv) {

  PIXEL b[1] = {GREY};
  if ((fp = fopen("template", WRITE)) != NULL) {
    for (int h = 0; h < HEIGHT; h++) {
      for (int w = 0; w < WIDTH; w++) {
        if (h < 20 || h > 747 || w < 20 || w > 1003)
          b[0] = BLACK;
        else
          b[0] = WHITE;
        if (fwrite(b, PIXEL_S, 1, fp) != 1) {
          fprintf(stderr, "ERROR writing a pixel\n");
          exit(EXIT_FAILURE);
        }
      }
    }
  }
  fclose(fp);

  
}


