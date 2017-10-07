#define TEMPLATE_1
/**
 * struct template1 contains a two dimensional array of image data
 */ 
struct template1{
  // this must be free()ed after it has been malloced
  int** stamp;
  int size;
  char* color;
};

/**
 * getTemplate1() returns the first template for this program
 */
struct template1 getTemplate1();


