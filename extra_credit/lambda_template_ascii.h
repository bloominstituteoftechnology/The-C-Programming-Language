static char* LAMBDA_ASCII = "\
000000000000\
000011100000\
000111110000\
000000110000\
000000110000\
000001011000\
000011011000\
000110011100\
000110001100\
001110001100\
001110001110\
000000000000";


/**
 * struct template1 contains a two dimensional array of image data
 */ 
struct template2{
  // this must be free()ed after it has been malloced
  int** stamp;
  int size;
  int* color;
};

/**
 * getTemplate1() returns the first template for this program
 */
struct template2 getTemplate2();

