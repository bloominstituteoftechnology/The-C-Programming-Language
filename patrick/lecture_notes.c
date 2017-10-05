// ppm file: Protable Pixel Map
// http://netpbm.sourceforge.net/doc/ppm.html
// http://netpbm.sourceforge.net/doc/libnetpbm.html
/*******************************************************************************
* From the LucidChart
*/

// dynamically allocated array
int m = 30;
int n = 30;
// twoDArray is a memory address of an array of memory addresses
int** twoDArray;
twoDArray = malloc(m * sizeof(void*)); // twoDArray contains garbage until this line is finished
for(i = 0 ; i < m ; ++i ) {
  twoDArray[i] = malloc(n * sizeof(int));
}
