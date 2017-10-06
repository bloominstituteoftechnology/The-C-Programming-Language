#include <stdlib.h>
#include <stdio.h>

int main(void) {
  const int width = 1024, height = 768;
  int col, row;
  FILE *imageFile = fopen("P6.ppm", "wb"); /* b - binary mode */
  /* I do not understand the use of (void) here */
  (void) fprintf(imageFile, "P6\n%d %d\n255\n", width, height);
  for (row = 0; row < height; ++row) {
    for (col = 0; col < width; ++col) {
      static unsigned char color[3];
      color[0] = col % 256;  /* red */
      color[1] = row % 256;  /* green */
      color[2] = (col * row) % 256;  /* blue */
      (void) fwrite(color, 1, 3, imageFile);
    }
  }
  /* I do not understand the use of (void) here */
  (void) fclose(imageFile);
  return EXIT_SUCCESS;
}
