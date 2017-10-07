#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void) {
  const int width = 1024, height = 768;
  int col, row;
  FILE *imageFile = fopen("P6", "wb"); /* b - binary mode */

  /* fprintf(imageFile, "P6\n%d %d\n65535\n", width, height); */
  for (row = 0; row < height; ++row) {
    for (col = 0; col < width; ++col) {
      static unsigned char color[3];
      // color[0] = col % 256;  /* red */
      // color[1] = row % 256;  /* green */
      // color[2] = (col * row) % 256;  /* blue */
      color[0] = fabs(floor((row * 255 / 1024 - 35))); /* red */
      color[1] = fabs(floor((col * 255 / 1024 - 112))); /* green */
      color[2] = fabs(floor(((col) * 255 / 1024 - 92))); /* blue */

      fwrite(color, 1, 3, imageFile);
    }
  }
  fclose(imageFile);
  return EXIT_SUCCESS;
}
