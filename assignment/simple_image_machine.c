/***************************************************************************************************
 * simple_image_machine.c
 * ----------------------
 *
 * OCTOBER 10, 2017
 * VERSION 0.5
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

#define VERSION 0.5
#define USAGE "USAGE: simple_image_machine -o <outputfile>.ppm template1 <x1> <y1> template2 <x2> <y2> ...\n"

/* *************************************************************************
 * MAIN
 * *************************************************************************/
int main(int argc, char** argv) {

  /* FIRST, option processing: -o outputfile | -h */
  char* outputfile = outputFilename(argc, argv);
  fprintf(stderr, "-o %s\n", outputfile);

  /* SECOND, create and initialize with all white an array that holds r,g,b color values */
  PIXEL** imagebuffer = malloc(sizeof(void*) * HEIGHT);
  for (int row = 0; row < HEIGHT; row++) {
    imagebuffer[row] = calloc(WIDTH, PIXEL_S);
  }
  fillBuffer(imagebuffer, WHITE);
  fprintf(stderr, "image buffer (%d x %d) created and initialized\n", WIDTH, HEIGHT);

  /* THIRD, loop over template files given on command line, load them, and overlay them */
  int f = 3;
  while (f < argc) {
    TEMPLATE* template = &(TEMPLATE){};
    loadTemplate(template, argv, f);
    templateInfo(template);
    f += 3;

    overlay(imagebuffer, template);
    fprintf(stderr, "Template stamped onto image buffer at (%d, %d)\n",
            template->start_x, template->start_y);
    free(template->buff);
  }
  writePPM(outputfile, imagebuffer);

  free(imagebuffer);
  fprintf(stderr, "Done\n");
  return 0;
}
/***************************************************************************
 * END MAIN
 ***************************************************************************/

/***************************************************************************
 * outputFilename                                                          *
 * --------------                                                          *
 * Uses getopt to process options -o outputfile | -h                       *
 *                                                                         *
 * parameters: int (argc)                                                  *
 *             char* (argv)                                                *
 * returns:    char* (output file name)                                    *
 ***************************************************************************/
char* outputFilename(int argc, char* argv[]) {
  int ch;
  while ((ch = getopt(argc, argv, "ho:")) != -1) {
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
  return optarg;
}

/***************************************************************************
 * templateInfo                                                            *
 * ------------                                                            *
 * Prints template information for debugging                               *
 *                                                                         *
 * parameter; TEMPLATE*                                                    *
 * returns:   void                                                         *
 ***************************************************************************/
void templateInfo(TEMPLATE* t) {
  fprintf(stderr, "template name: %s size: (%d x %d) stamp point: (%d, %d) buff %p\n",
          t->name, t->width, t->height, t->start_x, t->start_y, t->buff);
}

/***************************************************************************
 * fillBuffer                                                              *
 * ----------                                                              *
 * Initializes a buffer with a fill value                                  *
 *                                                                         *
 * parameters: PIXEL** buffer                                              *
 *             PIXEL fill                                                  *
 * returns:    void                                                        *
 ***************************************************************************/
void fillBuffer(PIXEL** buff, PIXEL fill) {
  for (int row = 0; row < HEIGHT; row++) {
    for (int col = 0; col < WIDTH; col++) {
      buff[row][col] = fill;
    }
  }
}

/***************************************************************************
 * loadTemplate                                                            *
 * ------------                                                            *
 * Loads a template as given on the command line                           *
 *                                                                         *
 * parameters: TEMPLATE* template                                          *
 *             char** argv (contains template name                         *
 *             int f (current position inside argv)                        *
 * returns:    void                                                        *
 ***************************************************************************/
void loadTemplate(TEMPLATE* template, char** argv, int f) {

  char* name = argv[f++];
  int start_x = atoi(argv[f++]);
  int start_y = atoi(argv[f++]);

  if ((fp = fopen(name, READ)) != NULL) {
    int width = 0;
    int height = 0;
    
    if ((fscanf(fp, "%d %d\n", &width, &height)) != 2) {
      fprintf(stderr, "ERROR reading width height in template file\n");
      exit(EXIT_FAILURE);
    }
    int templateSize = width * height;

    template->name = name;
    template->start_x = start_x;
    template->start_y = start_y;
    template->width = width;
    template->height = height;
    template->buff = calloc(templateSize, PIXEL_S);

    PIXEL_T pixelsRead;
    if ((pixelsRead = fread(template->buff, PIXEL_S, templateSize, fp)) != templateSize) {
      fprintf(stderr, "ERROR reading template file %s (%d)\n", name, templateSize);
      exit(EXIT_FAILURE);
    }
    fclose(fp);

  } else {
    fprintf(stderr, "can't open file %s\n", name);
    exit(1);
  }
}

/***************************************************************************
 * overlay                                                                 *
 * -------                                                                 *
 * Overlays a template onto the image buffer                               *
 *                                                                         *
 * parameters: PIXEL** imagebuffer                                         *
 *             TEMPLATE* template                                          *
 * returns:    void                                                        *
 ***************************************************************************/
void overlay(PIXEL** imagebuffer, TEMPLATE* template) {
  int width = template->width;
  int height = template->height;
  int start_x = template->start_x;
  int start_y = template->start_y;
  int end_x = fmin(WIDTH, start_x + width);
  int end_y = fmin(HEIGHT, start_y + height);
  int p = 0;

  for (int row = start_y; row < end_y; row++) {
    for (int col = start_x; col < end_x; col++) {
      PIXEL* pixel = template->buff + p;
      if (!(pixel->red == 0 && pixel->green == 0 && pixel->blue == 0)) {
        imagebuffer[row][col] = *pixel;
      }
      p++;
    }
  }
}

/***************************************************************************
 * writePPM                                                                *
 * --------                                                                *
 * Writes out the image buffer as a PPM (type P6) image file               *
 *                                                                         *
 * parameters: char* outputfile                                            *
 *             PIXEL** imagebuffer                                         *
 * returns:    void                                                        *
 ***************************************************************************/
void writePPM(char* outputfile, PIXEL** imagebuffer) {
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
      exit(EXIT_FAILURE);
    }
    PIXEL_T wrote;
    for (int row = 0; row < HEIGHT; row++) {
      for (int col = 0; col < WIDTH; col++) {
        if ((fwrite(&imagebuffer[row][col], PIXEL_S, 1, fp)) == 1) {
          wrote++;
        } else {
          fprintf(stderr, "ERROR writing (%d, %d) to %s\n", row, col, outputfile);
          exit(EXIT_FAILURE);
        }
      }
    }

    if (wrote != BUFSIZE) {
      fprintf(stderr, "ERROR writing image buffer; wrote [%d] bytes out of [%d] possible\n", wrote, BUFSIZE);
      exit(EXIT_FAILURE);
    }
    fprintf(stderr, "Wrote %d pixels to %s\n", wrote, outputfile);
    fclose(fp);
  }
  else {
    fprintf(stderr, "error opening a file for writing to\n");
    exit(EXIT_FAILURE);
  }
}

/***************************************************************************
 * makeColor                                                               *
 * ---------                                                               *
 * Given three colors, make and return a PIXEL                             *
 *                                                                         *
 * parameters; color (red), color (green), color (blue)                    *
 * returns:    PIXEL                                                       *
 ***************************************************************************/
PIXEL makeColor(color red, color green, color blue) {
  return (PIXEL){red, green, blue};
}

/***************************************************************************
 * showColors                                                              *
 * ----------                                                              *
 * Given a PIXEL, print out its components for debuggin                    *
 *                                                                         *
 * parameters; PIXEL* p                                                    *
 * returns:    void                                                        *
 ***************************************************************************/
void showColors(PIXEL* p) {
  fprintf(stderr, "%x:%x:%x ", p->red & 0xFF, p->green & 0xFF, p->blue & 0xFF);
}

/***************************************************************************
 * displayBuffer                                                           *
 * -------------                                                           *
 * Given a template, print out its components for debuggin                 *
 *                                                                         *
 * parameters: TEMPLATE* template                                          *
 * returns:    void                                                        *
 ***************************************************************************/
void displayBuffer(TEMPLATE* template) {
  templateInfo(template);
  for (int row = 0; row < template->height; row++) {
    fprintf(stderr, "row %2d ", row);
    for (int col = 0; col < template->width; col++) {
      fprintf(stderr, "[%d]", col);
      PIXEL* p = template->buff + (row * template->width + col);
      showColors(p);
    }
    fprintf(stderr, "\n");
  }
}

/***************************************************************************
 * displayImageBuffer                                                      *
 * ------------------                                                      *
 * Displays all of the pixels in the image buffer for debugging            *
 *                                                                         *
 * parameters: PIXEL** imagebuffer                                         *
 * returns:    void                                                        *
 ***************************************************************************/
void displayImageBuffer(PIXEL** imagebuffer) {
  for (int row = 0; row < HEIGHT; row++) {
    fprintf(stderr, "row [%2d]\n", row);
    for (int col = 0; col < WIDTH; col++) {
      PIXEL p = imagebuffer[row][col];
      fprintf(stderr, "[%2d]", col);
      showColors(&p);
    }
    fprintf(stderr, "\n");
  }
  fprintf(stderr, "DONE\n");
}
