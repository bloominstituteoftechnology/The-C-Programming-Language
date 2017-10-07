/*  yellowSquare.c  */
#include <stdio.h>
#include "template1.c"

int main(int argc, char** argv, struct template1) 
{
int i;
int j;
int k = 0;
int l = 0;
int offsetX = 100;
int offsetY = 100;
// this is the header of the ppm file
printf("P6\n 1024 768 255\n"); // width = 400, height = 400
// image data:  loops over all the pixels and sets them all to bright yellow
for (i = 0; i < 1024; i++) {
    for(j= 0; j < 768; j++) {
        if (i == k + offsetX && j== k + offsetY) {

        }
        printf("%c%c%c", 255, 255, 0); 
    }
// r = 255, g = 255, b= 0
}
return 0;
}