/***************************************************************************************************
 * simple_image_machine.c
 * ----------------------
 *
 * OCTOBER 10, 2017
 * VERSION 0.3_d
 *
 * DIRECTIONS:
 * ===========
 * Write a C program that: stamps images:
 * 
 * -- 1. Create 3 or more template structs that are created in their own separate file;
 *       these templates can be manually programmed, or you can load them from a file;
 * -- 2. Create an array of r,g,b values that is 1024x768;
 * -- 3. Using the templates you created in the other files, copy the templates into your
 *       large array;
 * -- 4. Write the array to a file according to the .PPM file specification;
 * -- 5. then convert it to .png using GIMP or another tool.
 *
 * USAGE: 
 * ======
 * 
 * simple_image_machine -o outputfile.ppm duck 40,100 circle 90,500 turkey 600,600 square 200,200
 *
 ***************************************************************************************************/

#include "./simple_image_machine.h"

#define VERSION 0.3_d

#define USAGE "USAGE: simple_image_machine -o <outputfile>.ppm template1 <x1> <y1> template2 <x2> <y2> ...\n"

PIXEL imagebuffer[HEIGHT][WIDTH];
char* outputfile;

/* *************************************************************************
 * MAIN
 * *************************************************************************/
int main(int argc, char** argv) {

  /* FIRST, option processing */
  int ch;
  while ((ch = getopt(argc, argv, "ho:")) != -1) { /* -o outputfile.ppm
                                                      -h help */
    if (ch == 'o')
      break;
    if (ch == 'h') {
      fprintf(stderr, USAGE);
      fprintf(stderr, "The simple_image_machine stamps template images onto a main image and produces a PPM (type P6) image file.\n  \
The templates are placed in the image at the points given after the template names.\n  The templates can be larger than or \
extend outside the boundaries of the image, but they will be truncated.\n  The template sizes are given in ascii at the \
beginning of the template file as two numbers and a newline: `xxx yyy \\n'.\n");

      exit(EXIT_SUCCESS);
    }
  }
  if (ch != 'o') {
    fprintf(stderr, "getting option name\n");
    fprintf(stderr, USAGE);
    exit(1);
  }
  outputfile = optarg;

  fillBuffer(imagebuffer, WHITE);    /* 1. Create an array of r,g,b values that is 1024x768
                                        fill each pixel with WHITE *\/ */
  /* displayBuffer(); */

  /* Loop over template files */
  for (int f = 3; f < argc; f++) { /* template x y (point at which to overlay template file in image buffer */
    TEMPLATE* template;
    template->name = argv[f++];
    template->start_x = atoi(argv[f++]);
    template->start_y = atoi(argv[f++]);
    if (isnan(template->start_x) || isnan(template->start_y)) {
      fprintf(stderr, "template starting point is incorrect: start-x: %d start-y: %d\n",
              template->start_x, template->start_y);
      fprintf(stderr, USAGE);
      exit(1);
    }
    
    PIXEL_T templateBuffSize = loadTemplate(template->name, template); /* load a template file */

    /* overlay(template); /\* overlay the template data on the buffer file *\/ */

    free(template->buff);
  }
  /* writePPM(outputfile); /\* write the imagebuffer to an output file *\/ */

  return 0;
}
/***************************************************************************
 * END MAIN
 ***************************************************************************/

void templateInfo(TEMPLATE* t) {
  fprintf(stderr, "template name: %s size: (%d x %d) stamp point: (%d, %d)\n",
          t->name, t->width, t->height, t->start_x, t->start_y);
}

void fillBuffer(PIXEL buff[HEIGHT][WIDTH], PIXEL fill) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      buff[i][j] = fill;
    }
  }
}

PIXEL_T loadTemplate(char* filename, TEMPLATE* template) {
  PIXEL_T pixelsRead;
  
  if ((fp = fopen(filename, READ)) != NULL) {

    int width = 0;
    int height = 0;
    char newl = ' ';
    
    if ((fscanf(fp, "%d %d%c", &width, &height, &newl)) != 3) {
      fprintf(stderr, "ERROR reading width height in template file\n");
      exit(EXIT_FAILURE);
    }
    template->width = width;
    template->height = height;
    int template_size = width * height;

    int templateBuffSize = PIXEL_S * width * height;
    if ((template->buff = malloc(templateBuffSize)) == NULL) {
      fprintf(stderr, "ERROR mallocing memory for template buffer\n");
      exit(EXIT_FAILURE);
    }

    pixelsRead = fread(template->buff, PIXEL_S, templateBuffSize, fp);
    fclose(fp);

    /* printf("read %d pixels from %s\n", pixelsRead, template->name);c- */
    /* displayBuffer(template); */
    
  } else {
    fprintf(stderr, "can't open file %s\n", filename);
    exit(1);
  }
  return pixelsRead;
}

void overlay(TEMPLATE* template) {
  int width = template->width;
  int height = template->height;
  int start_x = template->start_x;
  int start_y = template->start_y;
  int p = 0;
  for (int row = start_y; row < start_y + height; row++) {
    for (int col = start_x; col < start_x + width; col++) {
      PIXEL* pixel = template->buff + p;
      if (!(pixel->red == 0 && pixel->green == 0 && pixel->blue == 0)) { 
          imagebuffer[row][col] = *pixel;
        }
      p += PIXEL_S;
    }
  }
}

void writePPM(char* outputfile) {
  if ((fp = fopen(outputfile, WRITE)) != NULL) {
    /* http://netpbm.sourceforge.net/doc/ppm.html */
    /* Each PPM image consists of the following:
     *   1. the magic number "P6"; */
    /*   2. Whitespace (blanks, TABs, CRs, LFs). */
    /*   3. A width, formatted as ASCII characters in decimal. */
    /*   4. Whitespace. */
    /*   5. A height, again in ASCII decimal. */
    /*   6. Whitespace. */
    /*   7. The maximum color value (Maxval), again in ASCII decimal. Must be less than 65536 and more than zero. */
    if ((fprintf(fp, "%s\n#%s\n%d %d\n%d\n", PPM_TYPE, outputfile, WIDTH, HEIGHT, MAXVAL)) == EOF) {
      fprintf(stderr, "error writing header information to output file %s\n", outputfile);
      exit(1);
    }
    int written;
    if ((written = fwrite(imagebuffer, PIXEL_S, BUFSIZE, fp)) != BUFSIZE) { /* I THINK THIS IS SOURCE OF ERROR
                                                                               BUFSIZE SHOULD BE 3X AS BIG
                                                                               TO ACCOUNT FOR PIXEL_S BEING 
                                                                               3 BYTES */
      fprintf(stderr, "ERROR writing image buffer; wrote [%d] bytes out of [%d] possible\n", written, BUFSIZE);
      exit(1);
    }
    fclose(fp);
  }
  else {
    fprintf(stderr, "error opening a file for writing to\n");
    exit(1);
  }
}

/**************************************************************************
 * makeColor
 **************************************************************************/
PIXEL makeColor(color red, color green, color blue) {
  return (PIXEL){red, green, blue};
}

/***************************************************************************
 * showColors
 ***************************************************************************/
void showColors(PIXEL* p) {
  printf("%x:%x:%x ", p->red & 0xFF, p->green & 0xFF, p->blue & 0xFF);
}

/**************************************************************************
 * displayBuffer
 **************************************************************************/
void displayBuffer(TEMPLATE* template) {
  templateInfo(template);
    for (int row = 0; row < template->height; row++) {
      printf("row %2d ", row);
      for (int col = 0; col < template->width; col++) {
        printf("[%d]", col);
        PIXEL* p = template->buff + (row * PIXEL_S * template->width) + (col * PIXEL_S);
        showColors(p);
      }
      putchar('\n');
    }
}
