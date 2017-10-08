/* **************************************************************************************************
 * templatemker.c
 * --------------
 *
 * OCTOBER 7, 2017
 * VERSION 0.3
 *
 ***************************************************************************************************/

#include <math.h>
#include <ctype.h>

#include "./simple_image_machine.h"

#define VERSION 0.3
#define DESCRIPTION "Program to make a template for 'simple_image_machine'.\n\
Give a number (1, 2, 3, etc) for the template using the option -t <template-num>.\n\
The default size is 1024 x 768, but you can enter an explicit size after the number.\n"
#define USAGE "USAGE: templatemker -t template-num [width height]\n"

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
#define DEFAULT_WIDTH  WIDTH
#define DEFAULT_HEIGHT HEIGHT

int all_one_color(PIXEL_INFO, PIXEL, int);

/***************************************************************************************************
 * MAIN                                                                                            *
 ***************************************************************************************************/
int main(int argc, char** argv) {

  /************************************************************************
   * template name; from -t <num>                                         *
   ************************************************************************/
  /* make sure there is at least an option -t <num>
   * can also have an optional size [width height]
   * -h for help */
  if (argc == 0 || argc > 5) {
    fprintf(stderr, USAGE);
    exit(EXIT_FAILURE);
  }
  int ch = getopt(argc, argv, "ht:");
  if (ch == -1 || ch == '?') { // no options at all or incorrect options
    fprintf(stderr, USAGE);
    exit(EXIT_FAILURE);
  }
  if (ch == 'h') { // -h
    fprintf(stderr, "%s\n%s\n%s\n", argv[0], DESCRIPTION, USAGE);
    exit(EXIT_SUCCESS);
  }

  /* create the template name from the template num */
  int template_num = atoi(optarg);
  if ( (strlen(optarg) == 1 && !isdigit(*optarg)) || template_num == 0 ) {
    fprintf(stderr, USAGE);
    exit(EXIT_FAILURE);
  }
  char template_name[MAX_NAME_S];
  snprintf(template_name, MAX_NAME_S, "template_%02d", template_num);
  printf("template name: %s\n", template_name);

  /* make sure the program can open the file for writing */
  if ( (fp = fopen(template_name, WRITE)) == NULL ) {
    fprintf(stderr, "ERROR opening file %s for writing\n", template_name);
    exit(EXIT_FAILURE);
  } else {
    fprintf(stderr, "SUCCESS opening file %s for writing\n", template_name);
  }

  /* start with the default width and height as given by simple_image_maker;
   * check for optional width and height on the commnand-line */
  int width = DEFAULT_WIDTH;
  int height = DEFAULT_HEIGHT;
  if (argc == 5) {
    width = atoi(argv[3]);
    height = atoi(argv[4]);
    if (!(width > 0 && height > 0)) {
      fprintf(stderr, USAGE);
      exit(EXIT_FAILURE);
    }
    fprintf(stderr, "template size: %d x %d\n", width, height);
  }

  /***********************************************************************
   * Main Loop                                                           *
   ***********************************************************************/
  int byte_count = 0;
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      PIXEL_INFO p_info = pixel_info(w, h);
      switch (template_num) {
      case 1:
        byte_count = all_one_color(p_info, WHITE, byte_count);
        break;
      case 2:
        byte_count = all_one_color(p_info, BLACK, byte_count);
        break;
      case 3:
        byte_count = all_one_color(p_info, GRAY, byte_count);
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
    fprintf(stderr, "SUCCESS closing file %s; wrote %d bytes\n", template_name, byte_count);
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

/***************************************************************************************************
 * ALL_ONE_COLOR                                                                                   *
 ***************************************************************************************************/
int all_one_color(PIXEL_INFO pi, PIXEL pixel_color, int byte_count) {
  if ((fwrite(&pixel_color, PIXEL_S, 1, fp) != 1)) {
    fprintf(stderr, "ERROR writing PIXEL in `all_one_color'\n");
    exit(EXIT_FAILURE);
  }
  return byte_count += PIXEL_S;
}
