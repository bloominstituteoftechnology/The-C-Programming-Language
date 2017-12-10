#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <setjmp.h>
#include <signal.h>
#include <time.h>
#include <limits.h>
#include <float.h>

int outsideVariable = 5;

/**
 * primitives (int char float double)
 * loops, break, continue, while
 * branches if else else if
 * arrays
 * structs (to become classes)
 * extended types UINT_32 myInt = 5;
 * pointers, references, dereferencers, and pass-by-value
 * int x = 5
 * int* x = 5; 
 * struct myStruct* y;
 * *y = 5;
 * int x = 5;
 * int y = &x;
 * int functions(int arg) { arg = ?? }
 * functions(10); <- 10 remains in this scope, and arg above is a copy of 10
 * int functiont(int* arg) {}
 *
 * memory management malloc/free
 * int* X = malloc(1024);
 * X = malloc(1024); // the memory above is unrecoverably leaked ^
 * free(X);
 * free(X); // causes a crash
 *
 * const
 * const int five = 5;
 * const struct myStruct;
 * const int* six = 6;
 * const int* const six = 6;
 * int* const six = 6;
 *
 * reading stdin and files
 * 
 * meta programming (#ifdef)
 * 
 * declaration
 * definition
 * initialization
 * forward declaration
 * struct forward declaration https://stackoverflow.com/questions/18658438/what-is-forward-declaration-and-the-difference-between-typedef-struct-x-and
 *
 * faults - SIGSEGV, SIG, et
 *
 * header files
 * #include <math.h>
 *
 * file scope
 * extern
 * includes
 * libraries
 * objects
 * compilation
 * compilation arguments
 * files within directories, linked and built
 * linking
 * printf formatting
 * comparisons && || !
 * bit shifting >> <<
 * binary operators &, |, ~
 * function pointers
 */

// In order to run a program, you must:
//
// * Write this C file
//
// * Make it syntactically correct
//
// * Compile the program with gcc my_first_C_program.C -o my_output
//
// * ./my_output

#include <stdio.h>

int main(int argc, char** argv) {
  printf("Hello world!");
  // forward declaration
  // It used to be required that any variable you wished to use inside of
  // a function had to be declared at the top of the function, then used later.
  // This has been relaxed post C99, but many developers and old C code still
  // follow it.
  int foo;
  // later
  foo = 5;
  // or, even more commonly:
  int i;
  for (i = 0 ; i < 5 ; ++i) {}
  // now it is allowed to do:
  int Foo = 5;

  // struct forward declaration
  // https://stackoverflow.com/questions/18658438/what-is-forward-declaration-and-the-difference-between-typedef-struct-x-and
  // automatically hoisted?
  struct element {
      int value;
      // Use of the forward declaration
      struct element *next;
  }; // Complete definition
  // Tagged struct, has to be defined as a struct to use
  struct flement {
      int value;
      // No need for a forward declaration here
      struct flement *next;
  } flement; // tag
  
  element bar;
  bar.value = 5;
  bar.next = &bar;

  struct flement baz;
  baz.value = 6;
  baz.next = &baz;

  typedef struct flement glement;
  glement bale;
  bale.value = 7;
  bale.next = &bale;

  /* faults - SIGSEGV, SIG, et
   * header files
   * file scope
   */

  // extern
  //
  // C uses a technique called "file scope". The only objects and functions
  // that a C program is aware of are the ones that are located in the current
  // file. The extern keyword moves a variable from file scope into global scope
  // so it can be read by other files.

  extern int outsideVariable;
  int y = outsideVariable;

  // includes 
  // External files are referred to by their header.
  //
  // Files that are included must be compiled into the final program by the
  // compiler - specifying the inclusion does not affect compiler behavior.
  //
  // Adding the file to the compiler involves another step - either passing
  // the source file into the `gcc` command, or passing in the compiled `.o`
  // object file into the `gcc` command, or specifying the location of an
  // object file with the `-L` argument to gcc.
  //
  // "" searches your current directory and directories passed in with -I
  // <> searches in system directories

 /* libraries
 * objects
 * compilation
 * compilation arguments
 * files within directories, linked and built
 * linking
 * printf formatting
 * comparisons && || !
 * bit shifting >> <<
 * binary operators &, |, ~
 * compiler optimizations

 clang -pedantic micro.C -S -o test.asm
 */
  char* myString = "Hello dude";
}


