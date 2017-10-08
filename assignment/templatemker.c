/* **************************************************************************************************
 * templatemker.c
 * --------------
 *
 * OCTOBER 7, 2017
 * VERSION 0.2_2
 *
 ***************************************************************************************************/

#include <math.h>

#include "./simple_image_machine.h"

typedef struct {
  int x;
  int y;
  int z;
  int x_intersect;
  int y_intersect;
  int x_percent;
  int y_percent;
  int z_percent;
  int line;
  int diag_gradient;
} PIXEL_INFO;

PIXEL_INFO pixel_info(int, int);

int main(int argc, char** argv) {
  for (int h = 0; h < HEIGHT; h++) {
    for (int w = 0; w < WIDTH; w++) {
      PIXEL_INFO info = pixel_info(w, h);
    }
  }
}

PIXEL_INFO pixel_info(int x, int y) {
  int y_intersect = y - x; /* positive when y > x */
  int x_intersect = x - y; /* positive when x > y */
  int x_percent = ((float)x / WIDTH) * 100;
  int y_percent = ((float)y / HEIGHT) * 100;
  int z = (int)(sqrt(((float)x * x) + ((float)y * y)));
  int z_percent = (int)(sqrt(((float)WIDTH * WIDTH) + (float)(HEIGHT * HEIGHT))) * 100;
  int line = y_intersect >= 0 ? y : HEIGHT + x;
  int diag_gradient = (((float)line / (WIDTH + HEIGHT)) * 100 );

  return (PIXEL_INFO){
      x,
      y,
      z,
      x_intersect,
      y_intersect,
      x_percent,
      y_percent,
      z_percent,
      line,
      diag_gradient,
    };
}
