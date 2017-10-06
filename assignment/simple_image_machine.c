/***************************************************************************************************
 * simple_image_machine.c
 * ----------------------
 *
 * OCTOBER 5, 2017
 * VERSION 0.1
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
 * simple_image_machine duck 40,100 circle 90,500 turkey 600,600 square 200,200 -o outputfile.ppm
 *
 ***************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define USAGE "USAGE: simple_image_machine -o <outputfile>.ppm template1 <width> <height> template2 <width> <height> ..."

/* command-line argument filenames */
FILE* fp;
#define READ "r"
#define WRITE "w"


/* "Portable Pixel Map" ppm format
 * ---> http://netpbm.sourceforge.net/doc/ppm.html
 *====================================================================
 * the ITU-R Recommendation BT.709 red, green, and blue in the pixel

 * A raster  of Height  rows, in  order from top  to bottom.  Each row
 * consists of Width  pixels, in order from left to  right. Each pixel
 * is a triplet  of red, green, and blue samples,  in that order. Each
 * sample is represented in pure binary by either 1 or 2 bytes. If the
 * Maxval  is  less  than 256,  it  is  1  byte.  Otherwise, it  is  2
 * bytes. The most significant byte is first.
 * A row of  an image is horizontal. A column  is vertical. The pixels
 * in the image are square and contiguous. */

/* PIXEL */
typedef unsigned short color;
typedef struct {
  color red;
  color green;
  color blue;
} PIXEL;

typedef struct {
  char* name;
  int   width;
  int   height;
} TEMPLATE;

/* 1024 x 768 PIXEL buffer */
#define WIDTH 1024
#define HEIGHT 768
#define BUFSIZE WIDTH * HEIGHT
#define PIXEL_S sizeof(PIXEL)

/* BUFFER */
PIXEL imagebuffer[HEIGHT][WIDTH];
PIXEL templatebuff[HEIGHT][WIDTH];

/* WHITE */
#define RED   235
#define GREEN 235
#define BLUE  235
#define WHITE (PIXEL){RED, GREEN, BLUE}
#define EMPTY (PIXEL){0, 0, 0}
#define MAXVAL 0xFFFF

/* FORWARD DECLARATIONS */
void fillBuffer(PIXEL[HEIGHT][WIDTH], PIXEL);
void displayBuffer(void);
void displayLine(int);
int loadTemplate(char*, PIXEL[HEIGHT][WIDTH]);
void overlay();
void writePPM(char*);

char* outputfile;

/* MAIN */
/* *************************************************************************/
int main(int argc, char** argv) {

  /* get the outputfile */
  int ch;
  while ((ch = getopt(argc, argv, "o:")) != -1) {
    if (ch == 'o')
      break;
  }
  if (ch != 'o') {
    fprintf(stderr, USAGE);
    exit(1);
  }
  outputfile = optarg;

  /* initialize the imagebuffer */
  fillBuffer(imagebuffer, WHITE);    /* 1. Create an array of r,g,b values that is 1024x768
                                      fill each pixel with WHITE */
  /* displayBuffer(); */

  /* get the template files out of argv one-by-one, load themw with data, overlay them */
  for (int f = 1; f < argc; f++) {
    TEMPLATE template;
    template.name = argv[f++];
    template.width = atoi(argv[f++]);
    template.height = atoi(argv[f++]);
    if (template.width == 0 || template.height == 0) { /* error if either number is zero */
      fprintf(stderr, USAGE);
      exit(1);
    }
    
    fillBuffer(templatebuff, EMPTY); /* erase the template buffer before using */
    int read = loadTemplate(template.name, templatebuff); /* load a template file */
    overlay(templatebuff); /* overlay the template data on the buffer file */

  } /* repeat for each template */

  /* output the imagebuffer to a .ppm file */
  fprintf(stderr, "Writing result to %s\n", outputfile);
  writePPM(outputfile); /* write the imagebuffer to an output file */

  return 0;
}
/***************************************************************************/
/* END MAIN */

/* fill a buffer with PIXELs */
void fillBuffer(PIXEL buff[HEIGHT][WIDTH], PIXEL fill) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      buff[i][j] = fill;
    }
  }
}

/* Load a template file */
int loadTemplate(char* filename, PIXEL buff[HEIGHT][WIDTH]) {
  if ((fp = fopen(filename, READ)) != NULL) {
    int read = fread(buff, PIXEL_S, BUFSIZE, fp);
    fclose(fp);

    if (read == BUFSIZE)
      return read;

    else {
      fprintf(stderr, "error reading the correct number of pixels from %s: read %d instead of %d\n", filename, read, BUFSIZE);
      exit(1);
    }

  } else {
    fprintf(stderr, "can't open file %s\n", filename);
    exit(1);
  }
}

/* Overlay a template buffer on the image buffer */
void overlay() {
  for (int row = 0; row < HEIGHT; row++) {
    for (int column = 0; column < WIDTH; column++) {
      PIXEL p = templatebuff[row][column];
      if (p.red != 0 || p.green != 0 || p.blue != 0)
        imagebuffer[row][column] = templatebuff[row][column];
    }
  }
}

/* Write out a PPM file according to the format described at:
 * http://netpbm.sourceforge.net/doc/ppm.html */
void writePPM(char* outputfile) {
  if ((fp = fopen(outputfile, WRITE)) != NULL) {
    /* Each PPM image consists of the following:
     *   1. the magic number "P6"; */
    /*   2. Whitespace (blanks, TABs, CRs, LFs). */
    /*   3. A width, formatted as ASCII characters in decimal. */
    /*   4. Whitespace. */
    /*   5. A height, again in ASCII decimal. */
    /*   6. Whitespace. */
    /*   7. The maximum color value (Maxval), again in ASCII decimal. Must be less than 65536 and more than zero. */
    if ((fprintf(fp, "P6\n#%s\n%d %d\n%d\n", outputfile, WIDTH, HEIGHT, MAXVAL)) == EOF) {
      fprintf(stderr, "error writing header information to output file %s\n", outputfile);
      exit(1);
    }
    int written;
    if ((written = fwrite(imagebuffer, PIXEL_S, BUFSIZE, fp)) != BUFSIZE) {
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

PIXEL makeColor(color red, color green, color blue) {
  return (PIXEL){red, green, blue};
}

void displayBuffer() {
  for (int row = 0; row < HEIGHT; row++) {
    displayLine(row);
    getchar();
  }
}

void displayLine(int row) {
  printf("[%d] ", row);
  for (int column = 0; column < WIDTH; column++) {
    PIXEL pixel = imagebuffer[row][column];
    printf("[%d](r:%d g:%d b:%d) ", column, pixel.red, pixel.green, pixel.blue);
  }
  return;
}

