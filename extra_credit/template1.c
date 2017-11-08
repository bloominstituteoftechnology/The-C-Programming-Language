#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "template1.h"

struct template1 getTemplate1() {
  struct template1 returnTemplate;
  // code that initializes the template1 structure
  //
  int size = 40;
  int color[3];
  color[0] = 57;
  color[1] = 63;
  color[2] = 200; 
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
  returnTemplate.color = color;
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
  int color[3];
  color[0] = 255;
  color[1] = 255;
  color[2] = 255; 
  int image[200][200];
  for (int i = 0; i < 200; i++) {
    for(int j= 0; j < 200; j++) {
      image[i][j] = 1;
    };
  };

  // This is the code for mallocing a 2d array
  int m = 200;
  int n = 200;
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
  returnTemplate.color = color;
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

struct template1 getLTemplate() {
  struct template1 returnTemplate;
  int size = 200;
  int color[3];
  color[0] = 255;
  color[1] = 255;
  color[2] = 255; 
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

        

  // This is the code for mallocing a 2d array
  int m = 200;
  int n = 200;
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
  returnTemplate.color = color;
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