# Image Stamper

Write a C program that stamps images.

## Suggested runtime process

* Create 3 or more template structs with an image contained within that are
  created in their own separate file.
* These templates can be manually programmed, or you can load them from a file.
  Consider writing a C program that reads the image to be stamped and writes out
  C code with the data in it. This is called a _code generator_.
* Create an array of r,g,b values that is 1024x768.
* Using the templates you created in the other files, copy the templates into
  your large array.
* Write the array to a file according to the .PPM file specification, then
  convert it to .png using GIMP or another tool such as ImageMagick, below.


## Invocation

This should generate a file called outputfile.ppm with a duck, circle, turkey,
and square stamped on it. (You can use whatever shapes you wish; these are
merely ideas.)

```
simple_image_machine -o outputfile.ppm duck 40 100 circle 90  500 turkey 600 600 square 200 200
```

## How to attack this problem?

Start breaking it down into pieces.

* Whole program
    * Parse Command Line
    * Stamp images on main image
    * Write out final PPM image

If any of those ideas are still unclear on how to implement, break _them_ down:

* Whole Program
    * Parse Command Line
        * Get arg count from argc
        * Get args from argv
            * Write a while loop to loop over all arguments
                * look for -o, if so, get next argument and save as output file name
                * otherwise it's the name of an image followed by two numbers
                    * convert number argument to int

Keep breaking it down until you get down to something that you can code up.

## ImageMagick

Install ImageMagick to help manipulate these images to get them ready to load into your program.

Mac with HomeBrew: `brew install imagemagick`

Arch Linux: `sudo pacman -S imagemagick`

### Getting a plain (ASCII) PNM file

Use `convert` like so to generate an RGB image:

`convert foo.jpg -compress none foo.ppm`

Then the file will be in the format specified by the [plain PPM format
specification](http://netpbm.sourceforge.net/doc/ppm.html). This is an ASCII
format that you might have an easier time reading in C.

If you want to read the data in binary format, use:

`convert foo.jpg foo.ppm`

and use `fread()` to read entire rows of the image into arrays at once. This is
easier to code than parsing the ASCII version, but it does involve learning
about reading binary data in C (not rocket science).

After you generate your final PPM image, you can convert it back to a format that's friendly to image viewers:

`convert myimage.ppm myimage.png`
