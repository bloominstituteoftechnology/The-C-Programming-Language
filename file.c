#include <stdlib.h>
#include <stdio.h>

// void write (char fname[], char data[], int size) {
//   FILE *pImage = fopen(fname, 'wb');
//   fputs("p6\n");;
//   fwrite(data,1,size,pImage);
//   fclose(pImage);
// }

int main() {
  int width = 255;
  int height = 255;

  FILE *image = fopen("picture.ppm", "wb");
  fprintf(image, "P3\n");
  fprintf(image, "%d %d\n", width, height);
  fprintf(image, "255\n");


  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int r = i % rand() % (255 + 1 - 0) + 0;
      int g = j % rand() % (255 + 1 - 0) + 0;;
      int b = j * i % rand() % (255 + 1 - 0) + 0;
      fprintf(image, "%d %d %d\n", r, g, b);
    }
  }
  // system("convert picture.ppm picture.png");
  // remove("picture.ppm");
  return 0;
}
