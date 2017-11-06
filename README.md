
# The C Programming Language

Invented by Dennis Richie at Bell Labs between 1969 and 1973 in order to write a new Unix. 

C is used for: programming operating systems, maximum efficiency programming (with minor exceptions in ASM), and general purpose development on systems with limited resources or operating systems.

You will still find C used at many shops for which it is not the best tool for the job, but a large existing codebase predicates continuing development into it.Finally, C is used for efficiency gains in any development environment (Python, Javascript, Matlab, R, and any other) when the more dynamic langauge runs into resource or performance limitations. C modules can be written and executed from any other programming language (but not from within a browser).

# Objective

The main objective of this lab is, in fact, _not_ to teach you C. The goal here isn't to get you as comfortable with C as you are with JavaScript. The main points are the following:
  - To get you guys working in a different language, because once you know one language very well, you'll reach a point where the language itself starts to constrain how you think about problems. Becoming familiar with other languages pushes the boundaries of your understanding and skills as developers. 
  - A *HUGE* chunk of the world's software is written in C. Again, while the main goal of this lab is not to get good at writing C, it is trying to introduce many new concepts to you that higher-lever, dynamically-typed, interpreted language like JavaScript completely abstracts away from you under the hood. Working with C gets you much closer to the 'bare metal', giving you a much clearer glimpse of what computers are doing under the hood. 

With that being said, C is _really hard_. It is extremely unforgiving, and at the same time, it is a very strict language, in large part due to the fact that it is statically typed. Coming from JavaScript, the idea of have to specify the type of _every_ function, variable, return value, etc. is a little foreign. In essence, shifting to C in the coming weeks is going to be _really difficult_. We are aware of this, and again, these labs and assignments are designed such that you'll have learned a lot even if you only get a fraction of it completed. Try to keep this fact in mind. :)

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

# Assignment

Go through the files in this repository in the following order: 
  - `micro.c`
  - `myprintf.c`
  - `esoterica.c`
  - `pointer_lesson.c`
  - `rap.c`
  - `double_pointer_lesson.c`
  - `review.c`

Work through any exercises presented those files and get them to compile. If you don't understand some function that is used in any of these files, definitely look them up!

# Extra Credit 

Write a C program that: stamps images

- create 3 or more template structs that are created in their own separate file
- these templates can be manually programmed, or you can load them from a file
- create an array of r,g,b values that is 1024x768
- using the templates you created in the other files, copy the templates into your large array
- write the array to a file according to the .PPM file specification, then convert it to .png using GIMP or another tool./

Calling method:

    simple_image_machine -o outputfile.ppm duck 40 100 circle 90  500 turkey 600 600 square 200 200
