/*
 * testing how argc and argv work
 * invoke: ./a.out term1 term2...term(n-1)
 * results in: term1 term2...term(n-1) null
*/

// needed for printf
#include <stdio.h>

/* Specifies the type of variable the function returns.
 * main() must return an integer */
int

/*       placement of ** ?  ** vs * ? */
main ( int argc, char ** argv ) {
  /* will print null for the last value */
  // for (int i = 0; i <= argc; ++i) {
  /* will not print null for the last value */
  for (int i = 0; i < argc; ++i) {
    printf ("%s\n", argv[i]);
  }
  /* a zero indicates all went well, re: other C return values? */
  return 0;
}
