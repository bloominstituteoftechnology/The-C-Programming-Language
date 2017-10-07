#include "template1.h"


struct template1 getTemplate1() {
  struct template1 returnTemplate;
  // code that initializes the template1 structure
  //
  int size = 40;
  char color[3];
  color[0] = 57;
  color[1] = 63;
  color[2] = 200; 
  int image[40][40];
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
  returnTemplate.stamp = image;
  returnTemplate.size = size;
  returnTemplate.color = color;
  // code that reads template1.dat
  // code that puts data from template1.dat into template1 structure

  return returnTemplate;
}

