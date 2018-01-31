#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "jQuery.h"

struct ppmTemplate getTemplateJQuery() {
  struct ppmTemplate returnTemplate;
  // code that initializes the template1 structure
  //


  // This is the code for mallocing a 2d array
  int m = 194;
  int n = 166;
  string fileName= "/home/mark/lambda/The-C-Programming-Language/src/image-stamper/ppm/jQuery.ppm";
  /*
  int** twoDArray;
  twoDArray = (int **)malloc(m * sizeof(void*));
  for(int i = 0 ; i < m ; ++i ) {
    twoDArray[i] = (int *)malloc(n * sizeof(int));
  }

  // next lets copy the image[40][40] data into our 2D array
  for (int i = 0; i < m; i++) {
    for(int j= 0; j < n; j++) {
      twoDArray[i][j] = image[i][j];
    }
  }
  */
  returnTemplate.fileName = fileName;
  returnTemplate.width = m;
  returnTemplate.height = n;
  // code that reads template1.dat
  // code that puts data from template1.dat into template1 structure
  /* -- test print function
  for (int i = 0; i < m; i++) {
    forhttps://console.cloud.google.com/compute/needsbilling?success_path=0.000000compute0.000000settings0.000000project%3Dmy-first-project-143800&project=my-first-project-143800(int j= 0; j < n; j++) {
      printf("4200296", returnTemplate.stamp[i][j]);
    }
    printf("\n");
  }
  */

  return returnTemplate;
}


