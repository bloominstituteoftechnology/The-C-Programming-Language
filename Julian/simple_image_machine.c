/*  yellowSquare.c  */
#include <stdio.h>
#include <stdlib.h>

struct template {
    int** stamp;
    int size;
    char* color;
};

void applyTemplate(int** picture, struct template template1, int picWidth, int picHeight, int offsetX, int offsetY) {
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    for(i; i < picWidth; ++i) {
        if (i == k + offsetX) {
        for(j; j < picHeight; ++j) {
            if (j == l + offsetY) {
                picture[i][j] = template1.stamp[k][l];
                l++;
            };
        };
        k++;
    };
};

int main(int argc, char** argv) 
{
    int i;
    int j;
    int m;
    int n;
    m = 1024;
    n = 768;
    int** pictureArray;
    pictureArray = malloc(m * sizeof(void*));
    for(i=0; i < m; ++i) {
        pictureArray[i] = malloc(n * sizeof(int));
    };
    for(i = 0; i < m; ++i) {
        for(j = 0; j < n; j++) {
        pictureArray[i][j] = 0;
        };
    };


    // this is the header of the ppm file
    printf("P6\n 1024 768 255\n"); // width = 400, height = 400
    // image data:  loops over all the pixels and sets them all to bright yellow
    for (i = 0; i < 1024; i++) {
        for(j= 0; j < 768; j++) {
            printf("%c%c%c", 0, 255, 0); 
        };
    // r = 255, g = 255, b= 0
    };
    for(i = 0 ; i < m ; ++i ) {
        free(pictureArray[i]);
      }
      free(pictureArray);
    return 0;
};