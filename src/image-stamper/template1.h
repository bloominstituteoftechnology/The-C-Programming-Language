#define TEMPLATE_1 = { {0,0,0,0,1,1,1,0,0,0}, {0,0,0,0,1,1,1,0,0,0}, {0,0,0,0,1,1,1,0,0,0}, {0,0,0,0,1,1,1,0,0,0}, {0,0,0,0,1,1,1,0,0,0}, {0,0,0,0,1,1,1,0,0,0}, {0,0,0,0,1,1,1,0,0,0}, {0,0,0,0,1,1,1,0,0,0}, {0,0,0,0,1,1,1,0,0,0}, {0,0,0,0,1,1,1,0,0,0} }

/**
 * struct template1 contains a two dimensional array of image data
 */ 
struct template1{
  // this must be free()ed after it has been malloced
  int** stamp;
  int size;
  int* color;
};

/**
 * getTemplate1() returns the first template for this program
 */
struct template1 getTemplate1();

