/*******************************************************************************
 * Produces a 400 x 400 image of yellow pixel values in binary RGB
 * with header info for reading in a P6 PPM image file
 * $ gcc yellow.c
 * compiled binary to be piped into a .ppm file manually
 * $ ./a.out > yellowSquare.ppm
 ******************************************************************************/
#include <stdio.h>

int main(void) {
  int i;

  // this is the header of the ppm file
  // width = 400, height = 400
  printf("P6\n 400 400 255\n");

  // image data: loops over all the pixels and sets them all to bright yellow
  // r = 255, g = 255, b = 0
  for (i = 0; i < 400 * 400; i++) {
    printf("%c%c%c", 255, 255, 0);
  }
  return 0;
}
