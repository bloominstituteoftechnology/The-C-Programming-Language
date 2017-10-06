#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(void) {
  const int x = 1024, y = 768;
  int i, j;
  FILE *imageFile = fopen("P3.ppm", "w"); /* P3 NOT in binary mode */
  /* I do not understand the use of (void) here */
  (void) fprintf(imageFile, "P3\n%d %d\n255\n", x, y);
  for (j = 0; j < y; ++j) {
    for (i = 0; i < x; ++i) {
      // int red = j % 256;
      // int green = i % 256;
      // int blue = (i * j) % 256;
      int red = fabs(floor((j * 255 / 1024 - 35)));
      int green = fabs(floor((i * 255 / 1024 - 112)));
      int blue = fabs(floor(((i) * 255 / 1024 - 92)));
      fprintf(imageFile, "%d %d %d  ", red, green, blue);
    }
  }
  /* I do not understand the use of (void) here */
  (void) fclose(imageFile);
  return EXIT_SUCCESS;
}
