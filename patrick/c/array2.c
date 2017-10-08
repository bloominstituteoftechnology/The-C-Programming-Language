#include <stdio.h>
#include <stdlib.h> // to use atoi()

int main(int argc, char** argv) {
  /* image array to be called `a.out 10 20` makes a 10x20 grid */
  int width = atoi(argv[1]);
  int height = atoi(argv[2]);
  int total = width * height;
  printf("%d times %d = %d pixels\n", width, height, total);
  puts("Each pixel address: [height, width]");
  int col; // # of columns = width
  int row; // # of rows    = height
  for (row = 0; row <= height; ++row) {
    for (col = 0; col <= width; ++col) {
      if (col == width) {
        printf("[%2d,%d]\n", row, col); // %2d gives 2 char padding
      } else {
        printf("[%2d,%d] ", row, col);
      }
    }
  }
  // puts("image array");
  // int image [ width ][ height ];
  // for (row = 0; row <= height; ++row) {
  //   for (col = 0; col <= width; ++col) {
  //     image[row][col] = col;
  //   }
  // }
  // for (row = 0; row < height; ++row) {
  //   for (col = 0; col < width; ++col) {
  //     if (col == (width - 1)) {
  //       printf("[%2d,%d]\n", *image[row], image[row][col]);
  //     } else {
  //       printf("[%2d,%d] ", *image[row], image[row][col]);
  //     }
  //   }
  // }
  return 0;
}
