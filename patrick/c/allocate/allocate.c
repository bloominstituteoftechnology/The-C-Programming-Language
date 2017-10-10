
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Makefile
// make

int main(int argc, char** argv) {
  int i;
  int ii;
  // dynamically allocated array
  int m = 10;
  int n = 7;
  int diameter = 5;
  // twoDArray is a memory address of an array of memory addresses
  int** twoDArray;
  twoDArray = malloc(m * sizeof(void*));
  for(i = 0 ; i < m ; ++i ) {
    twoDArray[i] = malloc(n * sizeof(int));
  }
  // puts("Can I assign memory into my 2d array?");
  for(i = 0 ; i < m; ++i ) {
    for(ii = 0 ; ii < n; ii++ ) {
      if( sqrt(abs(i-m/2)*abs(ii-n/2)) < diameter && sqrt(abs(i-m/2)*abs(ii-n/2) > diameter-1 ) ) {
        twoDArray[i][ii] = 1;
      }
      else {
        twoDArray[i][ii] = 0;
      }
    }
  }
  for (i = 0; i < m; ++i) {
    for (ii = 0; ii < n; ++i) {
      printf("%d", twoDArray[i][ii]);
    }
  }
  for(i = 0 ; i < m ; ++i ) {
    free(twoDArray[i]);
  }
  free(twoDArray);
}
