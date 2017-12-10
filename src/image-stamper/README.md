# Image Stamper

Write a C program that: stamps images

- create 3 or more template structs that are created in their own separate file
- these templates can be manually programmed, or you can load them from a file
- create an array of r,g,b values that is 1024x768
- using the templates you created in the other files, copy the templates into your large array
- write the array to a file according to the .PPM file specification, then convert it to .png using GIMP or another tool./

Calling method:

    simple_image_machine -o outputfile.ppm duck 40 100 circle 90  500 turkey 600 600 square 200 200
