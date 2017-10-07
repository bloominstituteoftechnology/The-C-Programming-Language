
# C

Invented by Dennis Richie at Bell Labs between 1969 and 1973 in order to write a new Unix. 

C is used for: programming operating systems, maximum efficiency programming (with minor exceptions in ASM), and general purpose development on systems with limited resources or operating systems.

You will still find C used at many shops for which it is not the best tool for the job, but a large existing codebase predicates continuing development into it.Finally, C is used for efficiency gains in any development environment (Python, Javascript, Matlab, R, and any other) when the more dynamic langauge runs into resource or performance limitations. C modules can be written and executed from any other programming language (but not from within a browser).

# Order of languages

C was once called a "higher level programming language", meaning that it has been abstracted far enough away from hardware to enable rapid development. Today, C is the "lowest level programming language" used in common development, though there are still a great number of ASM developers who are writing operating system drivers, graphics card libraries, and custom hardware. Languages other than C are considered to be higher level, meaning they provide more abstraction and increased developer productivity as a result of easy to use libraries, in exchange for pure processing efficiency.

# C build process

C is a compiled language. This means that the syntax and tokens that you write in your .c file are converted from the "higher level language" of C directly into machine language, and are loaded into and executed deterministically by the CPU. C is more than compiled, however; C programs are built in a series of steps:

1. preprocessing

[Preprocessing](https://en.wikipedia.org/wiki/C_preprocessor)

#include, #if, #define, and more.

`gcc -E foo.c`

[JesperE](https://stackoverflow.com/a/3917029/498629)

(or perhaps `unifdef`?)

2. compilation

Convert fully preprocessed C language into ASM via lexing and parsing steps.

[Lexical Analysis](https://en.wikipedia.org/wiki/Lexical_analysis)

`clang -Xclang -dump-tokens code.c`
[OlivierLi](https://stackoverflow.com/a/40209551/498629)

[Parsing](https://en.wikipedia.org/wiki/Parsing)

`clang -std=c99 -pedantic micro.C -S -o test.asm`

3. assembly

Convert ASM to binary ML.

`clang -c test.asm`

4. linking

`gcc -o object_files source_file.c`

# ASSIGNMENT

Write a C program that: stamps images

- create 3 or more template structs that are created in their own separate file
- these templates can be manually programmed, or you can load them from a file
- create an array of r,g,b values that is 1024x768
- using the templates you created in the other files, copy the templates into your large array
- write the array to a file according to the .PPM file specification, then convert it to .png using GIMP or another tool./

Calling method:

    simple_image_machine -o outputfile.ppm duck 40 100 circle 90  500 turkey 600 600 square 200 200

Extra Credit: use a third party library to output a .png file from your array


# C language elements

     * primitives (int char float double)
     * loops, break, continue, while
     * branches if else else if
     * arrays
     * structs (to become classes)
     * ^^^ ^^^ ^^^ ^^^ ^^^ you did this
     * Operating Systems C Lesson Assignment 1
     * 
     * Operating Systems and C and Theory and Algorithms Lessons
     * \/\/\/\/
     *
     * extended types UINT_32 myInt = 5;
     * pointers, references, dereferencers, and pass-by-value
     * int x = 5
     * int* x = 5; //
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
    // Write this C file
    // Make it syntactically correct
    // Compile the program with gcc my_first_C_program.C -o my_output
    // ./my_output

#include <stdio.h>

    int main(int argc, char** argv) {
      printf("Hello world!");
    /**
     * primitives (int char float double)
     * loops, break, continue
     * branches if else else if, while
     * arrays
     * structs (to become classes)
     * ^^^ ^^^ ^^^ ^^^ ^^^
     * Operating Systems C Lesson Assignment 1
     * 
     * Operating Systems and C and Theory and Algorithms Lessons
     * \/\/\/\/
     * operators, concatenated operators, and pre/post-order incrementation
     * extended types
     * pointers, references, dereferencers, and pass-by-value
     * memory management malloc/free
     * const
     * meta programming (#ifdef)
     * declaration
     * definition
     * initialization
     */
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
      for(i = 0 ; i < 5 ; ++i) {}
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
      // C uses a technique called "file scope". The only objects and functions
      // that a C program is aware of are the ones that are located in the current
      // file. The extern keyword moves a variable from file scope into global scope
      // so it can be read by other files.
      extern int outsideVariable;
      int y = outsideVariable;

      // includes 
      // External files are referred to by their header.
      // Files that are included must be compiled into the final program by the
      // compiler - specifying the inclusion does not affect compiler behavior.
      // Adding the file to the compiler involves another step - either passing
      // the source file into the `gcc` command, or passing in the compiled `.o`
      // object file into the `gcc` command, or specifying the location of an
      // object file with the `-L` argument to gcc.
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
     */
      
     /*
      int main(int argc, char** argv) {
        int x = 5;
        return x;
      }
     */
        
     /*
     clang -pedantic micro.C -S -o test.asm
     */
      char* myString = "Hello dude";
    }

