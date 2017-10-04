
# C

Invented by Dennis Richie at Bell Labs between 1969 and 1973 in order to write a new Unix. 

C is used for: programming operating systems, maximum efficiency programming (with minor exceptions in ASM), and general purpose development on systems with limited resources or operating systems.

You will still find C used at many shops for which it is not the best tool for the job, but a large existing codebase predicates continuing development into it.Finally, C is used for efficiency gains in any development environment (Python, Javascript, Matlab, R, and any other) when the more dynamic langauge runs into resource or performance limitations. C modules can be written and executed from any other programming language (but not from within a browser).

# Order of languages

C was once called a "higher level programming language", meaning that it has been abstracted far enough away from hardware to enable rapid development. Today, C is the "lowest level programming language" used in common development, though there are still a great number of ASM developers who are writing operating system drivers, graphics card libraries, and custom hardware. Languages other than C are considered to be higher level, meaning they provide more abstraction and increased developer productivity as a result of easy to use libraries, in exchange for pure processing efficiency.

# C build process

C is a compiled language. This means that the syntax and tokens that you write in your .c file are converted from the "higher level language" of C directly into machine language, and are loaded into and executed deterministically by the CPU. C is more than compiled, however; C programs are built in a series of steps:

- preprocessing

[Preprocessing](https://en.wikipedia.org/wiki/C_preprocessor)

#include, #if, #define, and more.

`gcc -E foo.c`
[JesperE](https://stackoverflow.com/a/3917029/498629)

(or perhaps `unifdef`?)

- compilation

Convert fully preprocessed C language into ASM via lexing and parsing steps.

[Lexical Analysis](https://en.wikipedia.org/wiki/Lexical_analysis)

`clang -Xclang -dump-tokens code.c`
[OlivierLi](https://stackoverflow.com/a/40209551/498629)

[Parsing](https://en.wikipedia.org/wiki/Parsing)

`clang -std=c99 -pedantic micro.C -S -o test.asm`

- assembly

Convert ASM to binary ML.

`clang -c test.asm`

- linking

`gcc -o object_files source_file.c`

# C language elements



# The-C-Programming-Language
