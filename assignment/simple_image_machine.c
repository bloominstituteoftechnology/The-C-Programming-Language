/***************************************************************************************************
 * simple_image_machine.c
 * ----------------------
 *
 * OCTOBER 5, 2017
 * VERSION 0.3_a
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

#include "./simple_image_machine.h"

#define VERSION 0.3_a

#define USAGE "USAGE: simple_image_machine -o <outputfile>.ppm template1 <width> <height> template2 <width> <height> ...\n"

PIXEL imagebuffer[HEIGHT][WIDTH];
char* outputfile;

/* *************************************************************************
 * MAIN
 * *************************************************************************/
int main(int argc, char** argv) {

  int ch;
  while ((ch = getopt(argc, argv, "o:")) != -1) { /* -o outputfile.ppm */
    if (ch == 'o')
      break;
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
    TEMPLATE template;
    template.name = argv[f++];
    template.start_x = atoi(argv[f++]);
    template.start_y = atoi(argv[f++]);
    if (isnan(template.start_x) || isnan(template.start_y)) {
      fprintf(stderr, "template starting point is incorrect: start-x: %d start-y: %d\n",
              template.start_x, template.start_y);
      fprintf(stderr, USAGE);
      exit(1);
    }
    
    int templateBuffSize = loadTemplate(template.name, template); /* load a template file */
    printf("Read %d pixels from %s\n", templateBuffSize, template.name);

    overlay(template); /* overlay the template data on the buffer file */

  }
  writePPM(outputfile); /* write the imagebuffer to an output file */

  return 0;
}
/***************************************************************************
 * END MAIN
 ***************************************************************************/

void templateInfo(TEMPLATE t) {
  fprintf(stderr, "template name: %s size: (%d x %d) stamp point: (%d, %d)\n",
          t.name, t.width, t.height, t.start_x, t.start_y);
}

void fillBuffer(PIXEL buff[HEIGHT][WIDTH], PIXEL fill) {
  for (int i = 0; i < HEIGHT; i++) {
    for (int j = 0; j < WIDTH; j++) {
      buff[i][j] = fill;
    }
  }
}

int loadTemplate(char* filename, TEMPLATE template) {
  if ((fp = fopen(filename, READ)) != NULL) {

    int width = 0;
    int height = 0;
    char newl = ' ';
    
    if ((fscanf(fp, "%d %d%c", &width, &height, &newl)) != 3) {
      fprintf(stderr, "ERROR reading width height in template file\n");
      exit(EXIT_FAILURE);
    }
    template.width = width;
    template.height = height;
    int template_size = width * height;
    templateInfo(template);

    int templateBuffSize = PIXEL_S * width * height;
    template.buff = malloc(templateBuffSize);

    int read = fread(template.buff, PIXEL_S, templateBuffSize, fp);
    fclose(fp);
    
  } else {
    fprintf(stderr, "can't open file %s\n", filename);
    exit(1);
  }
  return (int)read;
}

void overlay(TEMPLATE template) {
  PIXEL templateBuff[template.height][template.width];
  for (int row = 0; row < template.height; row++) {
    for (int column = 0; column < template.width; column++) {
      PIXEL p = template.buff[row][column];
      if (p.red != 0 || p.green != 0 || p.blue != 0)
        imagebuffer[row][column] = p;
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

void displayBuffer(TEMPLATE template) {
  for (int row = 0; row < template.height; row++) {
    printf("[%d] ", row);
    for (int column = 0; column < template.width; column++) {
      PIXEL pixel = template.buff[row * PIXEL_S * template.width][column * PIXEL_S];
      printf("[%d](r:%d g:%d b:%d) ", column, pixel.red, pixel.green, pixel.blue);
    }
    getchar();
    putchar('\n');
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

