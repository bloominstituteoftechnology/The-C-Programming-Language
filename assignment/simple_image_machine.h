/* **************************************************************************************************
 * simple_image_machine.h
 * ----------------------
 * 
 * OCTOBER 6, 2017
 * VERSION 0.2
 *
 ***************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int argc;
char** argv;

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

typedef unsigned short color;

/* PIXEL DEFINITION */
typedef struct {
  color red;
  color green;
  color blue;
} PIXEL;

/* TEMPLATE INFORMATION */
typedef struct {
  char* name;
  int   width;
  int   height;
} TEMPLATE;

/* IMAGE SIZE 1024 x 768 PIXELS */
#define WIDTH 1024
#define HEIGHT 768
#define BUFSIZE WIDTH * HEIGHT

/* PIXEL INFORMATION */
#define PIXEL_S sizeof(PIXEL)
#define RED   235
#define GREEN 235
#define BLUE  235
#define WHITE (PIXEL){RED, GREEN, BLUE}
#define BLACK (PIXEL){16, 16, 16}
#define GRAY (PIXEL){165, 165, 165}
#define EMPTY (PIXEL){0, 0, 0}

/* PPM DATA */
#define PPM_TYPE "P6"
#define MAXVAL 0xFFFF

/* USED WHEN OPENING FILES FOR READING AND WRITING */
FILE* fp;
#define READ  "r"
#define WRITE "w"

/* returns the name of the outputfile '-o outputfile' */
char* getoutputfile();

/* fills a buffer with a pixel */
void fillBuffer(PIXEL[HEIGHT][WIDTH], PIXEL);

/* loads a template file given from the command-line */
int loadTemplate(char*, PIXEL[HEIGHT][WIDTH]);

/* overlays a template buffer onto an image buffer */
void overlay();

/* writes out the image buffer into the outputfile */
void writePPM(char*);


void displayBuffer(void);
void displayLine(int);
