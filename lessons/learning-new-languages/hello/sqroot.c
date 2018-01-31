 /**
 * Classic hello, world
 * 
 * Compile with
 * 
 *   gcc -Wall -Wextra -o hello sqroot.c
 * 
 * or 
 * 
 *   clang -Wall -Wextra -o hello sqroot.c
 * 
 * Then run with
 * 
 *   ./sqroot
 */
 
 /* sqrt example */
  #include <stdio.h>
  #include <math.h>

  int main ()
  {
    double param, result;
    param = 1024.0;
    result = sqrt (param);
    printf ("sqrt(%lf) = %lf\n", param, result );
    return 0;
 }