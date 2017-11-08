#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "template1.h"

struct template1 getTemplate1() {
  struct template1 returnTemplate;
  // code that initializes the template1 structure
  //
  int size = 40;
  int r = 57;
  int g = 200;
  int b = 200;
  int image[40][40]; // you don't need this line because you are mallocing this
                     // below
  for (int i = 0; i < size; i++) {
    for(int j= 0; j < size; j++) {
      if (i < 10) {
          image[i][j] = 1;
      } else if(j > 19 && j < 25) {
          image[i][j] = 1;
      } else {
          image[i][j] = 0;
      };
    };
  };

  // This is the code for mallocing a 2d array
  int m = 40;
  int n = 40;
  int** twoDArray;
  twoDArray = malloc(m * sizeof(void*));
  for(int i = 0 ; i < m ; ++i ) {
    twoDArray[i] = malloc(n * sizeof(int));
  }

  // next lets copy the image[40][40] data into our 2D array
  for (int i = 0; i < m; i++) {
    for(int j= 0; j < n; j++) {
      twoDArray[i][j] = image[i][j];
    }
  }

  returnTemplate.stamp = twoDArray;
  returnTemplate.size = size;
  returnTemplate.r = r;
  returnTemplate.g = g;
  returnTemplate.b = b;
  // code that reads template1.dat
  // code that puts data from template1.dat into template1 structure
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

struct template1 getSquareTemplate() {
  struct template1 returnTemplate;
  int size = 200;
  int r = 120;
  int g = 230;
  int b = 120;
  int image[200][200];
  for (int i = 0; i < 200; i++) {
    for(int j= 0; j < 200; j++) {
      image[i][j] = 1;
    };
  };

  int m = 200;
  int n = 200;
  int** twoDArray;
  twoDArray = malloc(m * sizeof(void*));
  for(int i = 0 ; i < m ; ++i ) {
    twoDArray[i] = malloc(n * sizeof(int));
  }

  for (int i = 0; i < m; i++) {
    for(int j= 0; j < n; j++) {
      twoDArray[i][j] = image[i][j];
    }
  }

  returnTemplate.stamp = twoDArray;
  returnTemplate.size = size;
  returnTemplate.r = r;
  returnTemplate.g = g;
  returnTemplate.b = b;
  return returnTemplate;
}

struct template1 getLTemplate() {
  struct template1 returnTemplate;
  int size = 200;
  int r = 250;
  int g = 100;
  int b = 100;
  int image[200][200];
  for (int i = 0; i < 200; i++) {
    for (int j = 0; j < 200; j++) {
      if ((i > 165 && j < 160)|| j < 35) {
        image[i][j] = 1;
      } else {
        image[i][j] = 0;
      }
    }
  }

  int m = 200;
  int n = 200;
  int** twoDArray;
  twoDArray = malloc(m * sizeof(void*));
  for(int i = 0 ; i < m ; ++i ) {
    twoDArray[i] = malloc(n * sizeof(int));
  }

  for (int i = 0; i < m; i++) {
    for(int j= 0; j < n; j++) {
      twoDArray[i][j] = image[i][j];
    }
  }

  returnTemplate.stamp = twoDArray;
  returnTemplate.size = size;
  returnTemplate.r = r;
  returnTemplate.g = g;
  returnTemplate.b = b;
  return returnTemplate;
}

struct template1 getCircleTemplate() {
  struct template1 returnTemplate;
  int size = 200;
  int r = 200;
  int g = 200;
  int b = 250;
  int image[200][200];
  int radius = 100;
  for (int i = -radius; i < radius; i++) {
    for (int j = -radius; j < radius; j++) {
      if ( i * i + j * j <= radius * radius) {
        image[i + radius][j + radius] = 1;
      } else {
        image[i + radius][j + radius] = 0;
      }
    }
  }

  int m = 200;
  int n = 200;
  int** twoDArray;
  twoDArray = malloc(m * sizeof(void*));
  for(int i = 0 ; i < m ; ++i ) {
    twoDArray[i] = malloc(n * sizeof(int));
  }

  for (int i = 0; i < m; i++) {
    for(int j= 0; j < n; j++) {
      twoDArray[i][j] = image[i][j];
    }
  }

  returnTemplate.stamp = twoDArray;
  returnTemplate.size = size;
  returnTemplate.r = r;
  returnTemplate.g = g;
  returnTemplate.b = b;
  return returnTemplate;
}