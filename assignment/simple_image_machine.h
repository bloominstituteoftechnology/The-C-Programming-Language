/* **************************************************************************************************
 * simple_image_machine.h
 * ----------------------
 * 
 * OCTOBER 7, 2017
 * VERSION 0.3_g
 *
 ***************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <ctype.h>

int argc;
char** argv;

/***************************************************************************************************
 * TYPEDEFS                                                                                        *
 ***************************************************************************************************/

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

typedef char color;

/* PIXEL DEFINITION */
typedef struct {
  color red;
  color green;
  color blue;
} PIXEL;

/* TEMPLATE INFORMATION */
typedef struct {
  char* name;
  PIXEL* buff;
  int   start_x;
  int   start_y;
  int   width;
  int   height;
} TEMPLATE;

/***************************************************************************************************
 * DEFINES                                                                                         *
 ***************************************************************************************************/

/* IMAGE SIZE 1024 x 768 PIXELS */
/* SOURCE OF ERROR? BUFSIZE SHOULD BE 3X AS BIG BECAUSE OF PIXEL_S? */
#define WIDTH 1024
#define HEIGHT 768
#define BUFSIZE WIDTH * HEIGHT

/* PIXEL INFORMATION */
#define PIXEL_S sizeof(PIXEL)
typedef unsigned int PIXEL_T;

/* PIXEL COLOR VALUES */
#define RED_MAX   0xEB /* dec 235 */
#define GREEN_MAX 0xEB
#define BLUE_MAX  0xEB
#define WHITE (PIXEL){RED_MAX, GREEN_MAX, BLUE_MAX}

#define RED_MIN   0x0F /* dec 235 */
#define GREEN_MIN 0x0F
#define BLUE_MIN  0x0F
#define BLACK (PIXEL){RED_MIN, GREEN_MIN, BLUE_MIN}

#define RED_MID 0x6d /* dec 109 (235-16)/2 */
#define GREEN_MID 0x6d
#define BLUE_MID 0x6d
#define GRAY (PIXEL){RED_MID, GREEN_MID, BLUE_MID}

#define RED (PIXEL){RED_MAX, GREEN_MIN, BLUE_MIN}
#define GREEN (PIXEL){RED_MIN, GREEN_MAX, BLUE_MIN}
#define BLUE (PIXEL){RED_MIN, GREEN_MIN, BLUE_MAX}

#define PIXEL_COLOR_RANGE (RED_MAX - RED_MIN)

#define EMPTY (PIXEL){0, 0, 0}

/* PPM DATA */
#define PPM_TYPE "P6"
#define MAXVAL 0xFF

/* USED WHEN OPENING FILES FOR READING AND WRITING */
FILE* fp;
#define READ  "r"
#define WRITE "w"

/***************************************************************************************************
 * FUNCTION PROTOTYPES                                                                             *
 ***************************************************************************************************/

/*****************************
 * templateInfo
 * prints template information
 *****************************/
void templateInfo(TEMPLATE*);

/***********
 * makeColor
 * given three colors red, green, blue, returns a new PIXEL
 ************/
PIXEL makeColor(color, color, color);

/***********
 * showColor
 ***********/
void showColors(PIXEL*);

/***************
 * getoutputfile
 * returns the name of the outputfile '-o outputfile'
 ***************/
char* getoutputfile();

/************
 * fillBuffer
 * fills a buffer with a pixel
 ************/
void fillBuffer(PIXEL[HEIGHT][WIDTH], PIXEL);

/**************
 * loadTemplate
 * loads a template file named on the command-line into a PIXEL template buffer of unknown size
 **************/
PIXEL_T loadTemplate(char*, TEMPLATE*);

/*********
 * overlay
 * overlays a template buffer onto an image buffer
 *********/
void overlay(TEMPLATE*);

/**********
 * writePPM
 * writes the image buffer to the outputfile
 **********/
void writePPM(char*);

/***************
 * displayBuffer
 ***************/
void displayBuffer(TEMPLATE*);
