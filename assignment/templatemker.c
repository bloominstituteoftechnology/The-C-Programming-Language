/* **************************************************************************************************
 * templatemker.c
 * --------------
 *
 * OCTOBER 10, 2017
 * VERSION 0.4_a
 *
 ***************************************************************************************************/

#include "./simple_image_machine.h"

#define VERSION 0.4_a
#define DESCRIPTION "Program to make a template for 'simple_image_machine'.\n\
Give a number (1, 2, 3, etc) for the template using the option -t <template-num>.\n\
The default size is 1024 x 768, but you can enter an explicit size after the number.\n"
#define USAGE "USAGE: templatemker -t template-num [width height]\n"

#define MAX_NAME_S 12

typedef struct {
  int width;
  int height;
  int x;
  int y;
  int z;
  int x_intersect;
  int y_intersect;
  float x_percent;
  float y_percent;
  float z_percent;
  int line;
  float line_percent;
  float diag_gradient;
  int mid_x;
  int mid_y;
  int lr; // left-right
  int ud; // up-down
  int quadrant; // 0,1,2,3
} PIXEL_INFO;

PIXEL_INFO pixel_info(int, int, int , int);
#define DEFAULT_WIDTH  WIDTH
#define DEFAULT_HEIGHT HEIGHT

void printPixel(PIXEL);
void showPixel(PIXEL);
void showPixelInfo(PIXEL_INFO);
int  all_one_color(PIXEL_INFO, PIXEL, int);
int  diag_gradient(PIXEL_INFO, int);
int  horiz_gradient(PIXEL_INFO, int);
int quadrants(PIXEL_INFO, int);

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

    /* place `width' `height' dimensions at the start of the template file */
    if (fprintf(fp, "%d %d\n", width, height) < 0) {
      fprintf(stderr, "ERROR printing dimensions into template file\n");
      exit(EXIT_FAILURE);
    }
  }

  /***********************************************************************
   * Main Loop                                                           *
   ***********************************************************************/
  int byte_count = 0;
  for (int h = 0; h < height; h++) {
    for (int w = 0; w < width; w++) {
      PIXEL_INFO p_info = pixel_info(w, h, width, height);
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
      case 4:
        byte_count = all_one_color(p_info, BLUE, byte_count);
        break;
      case 5:
        byte_count = diag_gradient(p_info, byte_count);
        break;
      case 6:
        byte_count = horiz_gradient(p_info, byte_count);
        break;
      case 7:
        byte_count = quadrants(p_info, byte_count);
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
 * -----------                                                                                     *
 * (x, y) point                                                                                    *
 * width x height: template size                                                                   *
 ***************************************************************************************************/
PIXEL_INFO pixel_info(int x, int y, int width, int height) {
  int y_intersect = y - x; /* positive when y > x */
  int x_intersect = x - y; /* positive when x > y */
  float x_percent = (float)x / width;
  float y_percent = (float)y / height;
  int z = (int)(sqrt(((float)x * x) + ((float)y * y)));
  float z_percent = sqrt(((float)width * width) + (float)(height * height)) * 100;
  int line = 10 + y_intersect;
  float line_percent = (float)line / (height * 2);
  float diag_gradient = (float)line / (width + height);
  int mid_x = round(width / 2);
  int mid_y = round(height / 2);
  int lr = round(x / mid_x);
  int ud = round(y / mid_y);
  int quadrant = lr == 0 ? ud == 0 ? 0 : 3 : ud == 0 ? 1 : 4;

  return (PIXEL_INFO){
      width,
      height,
      x,
      y,
      z,
      x_intersect,
      y_intersect,
      x_percent,
      y_percent,
      z_percent,
      line,
      line_percent,
      diag_gradient,
      mid_x,
      mid_y,
      lr,
      ud,
      quadrant,
    };
}

/***************************************************************************************************
 * PRINTPIXEL                                                                                      *
 ***************************************************************************************************/
void printPixel(PIXEL p) {
  if ((fwrite(&p, PIXEL_S, 1, fp) != 1)) {
    fprintf(stderr, "ERROR writing PIXEL in\n");
    exit(EXIT_FAILURE);
  }
}

/***************************************************************************************************
 * SHOWPIXEL                                                                                       *
 ***************************************************************************************************/
void showPixel(PIXEL p) {
  printf("red: %02hhx  green: %02hhx  blue: %02hhx\n", p.red, p.green, p.blue);
}

/***************************************************************************************************
 * SHOWPIXELINFO                                                                                   *
 ***************************************************************************************************/
void showPixelInfo(PIXEL_INFO pi) {
  printf("(%d, %d, %d) %d x %d @ line %d\n", pi.x, pi.y, pi.z, pi.width, pi.height, pi.line);
  printf("x-i: %d y-i: %d\n", pi.x_intersect, pi.y_intersect);
  printf("x-percent: %2.2f%%  y-percent: %2.2f%%  line-percent: %2.2f%%\n",
         pi.x_percent * 100, pi.y_percent * 100, pi.line_percent * 100);
  printf("mid-x: %d  mid-y: %d  lr: %d  up: %d  quadrant: %d\n",
         pi.mid_x, pi.mid_y, pi.lr, pi.ud, pi.quadrant);
}

/***************************************************************************************************
 * ALL_ONE_COLOR: -t 1 (WHITE) 2 (BLACK) 3 (GRAY)                                                  *
 ***************************************************************************************************/
int all_one_color(PIXEL_INFO pi, PIXEL pixel_color, int byte_count) {
  printPixel(pixel_color);
  byte_count += PIXEL_S;
  /* printf("[%d](%d, %d) ", byte_count, pi.x, pi.y); */
  /* showPixel(pixel_color); */
  return byte_count;
}

/***************************************************************************************************
 * DIAG_GRADIENT: -t 5                                                                             *
 ***************************************************************************************************/
int diag_gradient(PIXEL_INFO pi, int byte_count) {
  /* showPixelInfo(pi); */
  color p_red = RED_MIN + (color)PIXEL_COLOR_RANGE * 2 * pi.line_percent;
  color p_green = GREEN_MIN;
  color p_blue = BLUE_MIN;
  PIXEL p = (PIXEL){p_red, p_green, p_blue};
  printPixel(p);
  byte_count += PIXEL_S;
  /* showPixel(p); */
  /* printf("\n"); */
  return byte_count;
}

/***************************************************************************************************
 * HORIZ_GRADIENT: -t 6                                                                            *
 ***************************************************************************************************/
int horiz_gradient(PIXEL_INFO pi, int byte_count) {
  color p_red = RED_MIN;// + (color)(PIXEL_COLOR_RANGE * pi.y_percent);
  color p_green = GREEN_MIN;// + (color)(PIXEL_COLOR_RANGE * pi.x_percent);
  color p_blue = BLUE_MIN + (color)(PIXEL_COLOR_RANGE * pi.z_percent);
  PIXEL p = (PIXEL){p_red, p_green, p_blue};
  printPixel(p);
  byte_count += PIXEL_S;
  /* showPixelInfo(pi); */
  /* showPixel(p); */
  /* printf("\n"); */
  return byte_count;
}

/***************************************************************************************************
 * QUADRANTS                                                                                       *
 ***************************************************************************************************/
int quadrants(PIXEL_INFO pi, int byte_count) {
  PIXEL p;
  switch (pi.quadrant) {
  case 1:
    p = RED;
    break;
  case2:
    p = GREEN;
    break;
  case 3:
    p = BLUE;
    break;
  case 4:
    p = BLACK;
    break;
  }
  printPixel(p);
  return byte_count += PIXEL_S;
}
