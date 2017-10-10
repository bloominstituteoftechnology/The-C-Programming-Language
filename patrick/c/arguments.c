/*
 * testing how argc and argv work
 * invoke: ./a.out term1 term2...term(n-1)
 * results in: term1
 *             term2...
 *             term(n-1)
 *             (null)
*/

#include <stdio.h> // needed for printf

/* Specifies the type of variable the function returns.
 * with int, main() must return an integer */
int
//       placement of ** ?  and ** vs * ? Not sure...
main ( int argc, char ** argv ) {
  printf("There were this many arguments: %d\n", argc);
  printf("This is the binary you've executed: %s\n", argv[0]);
  for (int i = 1; i <= argc - 1; ++i) {
    printf ("You also passed in this argument: %s\n", argv[i]);
  }
  printf("You also have a this value as the last item your argument vector (array): %s\n", argv[argc]);
  /* a zero indicates all went well, re: other C return values? */
  return 0;
}
