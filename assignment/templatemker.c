/* **************************************************************************************************
 * templatemker.c
 * --------------
 *
 * OCTOBER 7, 2017
 * VERSION 0.2_6
 *
 ***************************************************************************************************/

#include <math.h>
#include <ctype.h>

#include "./simple_image_machine.h"

#define MAX_NAME_S 12

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
int all_one_color(PIXEL_INFO, PIXEL, int);

/***************************************************************************************************
 * MAIN                                                                                            *
 ***************************************************************************************************/
int main(int argc, char** argv) {

  /************************************************************************
   * template name; from -t <num>                                         *
   ************************************************************************/
  int ch = getopt(argc, argv, "t:");
  if (ch == -1 || ch == '?') {
    fprintf(stderr, "USAGE: templatemker -t <num>\n");
    exit(EXIT_FAILURE);
  }
  int template_num = atoi(optarg);
  if ( (strlen(optarg) == 1 && !isdigit(*optarg)) || template_num == 0 ) {
    fprintf(stderr, "USAGE: templatemker -t <num>\n");
    exit(EXIT_FAILURE);
  }
  char template_name[MAX_NAME_S];
  snprintf(template_name, MAX_NAME_S, "template_%02d", template_num);
  printf("template number %s\n", template_name);
  if ( (fp = fopen(template_name, WRITE)) == NULL ) {
    fprintf(stderr, "ERROR opening file %s for writing\n", template_name);
    exit(EXIT_FAILURE);
  } else {
    fprintf(stderr, "SUCCESS opening file %s for writing\n", template_name);
  }

  int count = 0;
  for (int h = 0; h < HEIGHT; h++) {
    for (int w = 0; w < WIDTH; w++) {
      PIXEL_INFO p_info = pixel_info(w, h);
      switch (template_num) {
      case 1:
        count = all_one_color(p_info, WHITE, count);
        break;
      case 2:
        count = all_one_color(p_info, BLACK, count);
        break;
      case 3:
        count = all_one_color(p_info, GRAY, count);
        break;
      default:
        ;
      }
    }
  }

  if (fclose(fp) != 0) {
    fprintf(stderr, "ERROR closing file %s\n", template_name);
    exit(EXIT_FAILURE);
  } else {
    fprintf(stderr, "SUCCESS closing file %s; wrote %d bytes\n", template_name, count);
  }
  exit(EXIT_SUCCESS);
}

/***************************************************************************************************
 * PIXEL_INFO                                                                                      *
 ***************************************************************************************************/
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

int all_one_color(PIXEL_INFO pi, PIXEL pixel_color, int count) {
  if ((fwrite(&pixel_color, PIXEL_S, 1, fp) != 1)) {
    fprintf(stderr, "ERROR writing PIXEL in `all_one_color'\n");
    exit(EXIT_FAILURE);
  }
  return count += PIXEL_S;
}
