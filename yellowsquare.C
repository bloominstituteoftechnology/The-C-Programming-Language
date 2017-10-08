/* yellowSquare.c */
#include <stdio.h>
int main(void)
{
 int i;
 // this is the header of the ppm file
 printf("P6\n 400 400 255\n"); // width = 400, height = 400

 // image data: loops over all the pixels and sets them all to bright yellow
 for (i = 0; i < 400 * 400; i++) {
 printf("%c%c%c", 255, 255, 0); // r = 255, g = 255, b = 0
 }
 return 0;
}