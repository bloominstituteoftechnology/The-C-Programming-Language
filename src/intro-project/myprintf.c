// Imports in C are handled like so. Here we're including a header file called
// `stdio` that provides headers for some functions that we'll need in this
// file. 
#include <stdio.h>

/* 
 * Notice the function inputs here being passed to this `main` function. The
 * first is an integer called `argc`, and the second is an array of characters
 * called `argv`. This is the standard set of inputs given to a `main` function
 * when we want the executable to be able to handle input.
 * 
 * For this program, call the `printf` function, which is being imported from
 * the `stdarg` library, and pass it two arguments, `argv[1]` and `argv`,
 * respectively. Then compile and execute the program. What happens?
 * 
 * What happens when you pass in some input to the executable by typing
 * something like `./myprintf Sergeant McPorkinface` ?
 * 
 * Try printing out argc as well to find out what it is. Or you could look it
 * up. That works too.
 */
int main(int argc, char** argv) {
    // Your code here 
}

