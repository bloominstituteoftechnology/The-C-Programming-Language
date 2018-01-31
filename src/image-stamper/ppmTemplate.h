/**
 * struct template contains a two dimensional array of PPM image data
 */ 
struct ppmTemplate{
  // this must be free()ed after it has been malloced
  char * fileName; 
  int width;
  int height;
};