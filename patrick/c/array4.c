#include <stdio.h>

int main () {
  /* 768 rows and 1024 columns*/
  int image[768][1024];
  int row, col;
  /* output each array element's value */
  for ( row = 0; row < 768; row++ ) {
    for ( col = 0; col < 1024; col++ ) {
      image[row][col] = 12345; // How do I get this to be RGB color values?????
      printf("image[%d][%d] = %d\n", row,col, image[row][col] );
    }
  }
  return 0;
}
