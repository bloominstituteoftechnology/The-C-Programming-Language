#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "lambda_template_ascii.h"

extern char* LAMBDA_ASCII;

struct template2 getTemplate2() {
  struct template2 returnTemplate;
  // code that initializes the template2 structure
  int size = 12;
  
  // This is the code for mallocing a 2d array
  int m = size;
  int n = size;
  int** twoDArray;
  twoDArray = malloc(m * sizeof(void*));
  for(int i = 0 ; i < m ; ++i ) {
    twoDArray[i] = malloc(n * sizeof(int));
  }

  //printf("%s", LAMBDA_ASCII);

  // next lets copy the image[size][size] data into our 2D array
  for (int i = 0; i < m; i++) {
    for(int j= 0; j < n; j++) {
      twoDArray[i][j] = LAMBDA_ASCII[i*m+j]-48;
    }
  }

  returnTemplate.stamp = twoDArray;
  returnTemplate.size = size;
  
  // code that reads template2.dat
  // code that puts data from template2.dat into template2 structure
  /* -- test print function
  for (int i = 0; i < m; i++) {
    for(int j= 0; j < n; j++) {
      printf("%d", returnTemplate.stamp[i][j]);
    }
    printf("\n");
  }
  */

  return returnTemplate;
}

