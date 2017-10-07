/* **************************************************************************************************
 * templatemker.c
 * --------------
 *
 * OCTOBER 7, 2017
 * VERSION 0.2_1
 *
 ***************************************************************************************************/

#include <math.h>

#include "./simple_image_machine.h"

typedef struct {
  int x;
  int y;
  int dist;
  int x_intersect;
  int y_intersect;
  int x_percent;
  int y_percent;
} PIXEL_INFO;

PIXEL_INFO gradient3D(int, int);

int main(int argc, char** argv) {
  for (int h = 0; h < HEIGHT; h++) {
    for (int w = 0; w < WIDTH; w++) {
      gradient3D(w, h);
    }
  }
}

PIXEL_INFO gradient3D(int x, int y) {
  int y_intersect = y - x; /* positive when y > x */
  int x_intersect = x - y; /* positive when x > y */
  int x_percent = ((float)x / WIDTH) * 100;
  int y_percent = ((float)y / HEIGHT) * 100;
  int dist = (int)(sqrt(((float)x * x) + ((float)y * y)));

  printf("(%d, %d, %d) x%%: %d%% y%%: %d%%\n", x, y, dist, x_percent, y_percent);

  return (PIXEL_INFO){
    x, y, dist, x_intersect, y_intersect, x_percent, y_percent,
  };
}
