#include <stdio.h>
#include <math.h>
 
int main()
{
    int r, g, b, x, y, w=640, h=480;
 
    // Open output PPM file
    FILE* f = fopen("pattern.ppm", "w");
 
    // Print image header to file
    fprintf(f, "P3\n# batchloaf.wordpress.com\n%d %d\n255\n", w, h);
 
    // Generate pixel values and write to file
    for (y=0 ; y<h ; ++y)
    {
        for (x=0 ; x<w ; ++x)
        {
            r = fmod(0.001*(pow(x-w/2,3) + pow(y-w/2,3)),255.0);
            g = fmod(0.001*(pow(3*w/2-x,3) + pow(3*h/2-y,3)),255.0);
            b = 255;
            fprintf(f, "%03d %03d %03d ", r, g, b);
        }
        fprintf(f, "\n");
    }
 
    // Close file
    fclose(f);
 
    return 0;
}