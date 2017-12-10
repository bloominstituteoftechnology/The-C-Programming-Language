# Learning New Languages

## Why Learn New Languages?

* Nothing in CS is static. New languages are created all the time.
* Employers often expect employees to learn new languages on-the-fly.
* Learning new languages becomes easier the more languages you learn.
    * You'll start seeing the similaries between them.

Beej has personally hired engineers with zero experience with the language used
in the project. But the person was a good engineer, so they picked up the
language in a couple weeks and got the project done.

## The C Programming Language

* Invented by Dennis Richie at Bell Labs between 1969 and 1973 in order to write
  a new Unix. 

* C is:
    * Compiled (typically this produces a machine-code executable)
    * F-A-S-T fast: doesn't get better than machine-code for speed
    * Strongly-typed: you need to be explict about what the types of your
      variables are

* C is used for:
    * programming operating systems
    * maximum efficiency programming (with minor exceptions in ASM)
    * general purpose development on systems with limited resources or operating systems
    * extending slower languages (e.g. Python, JavaScript) with high-performance modules

You will still find C used at many shops for which it is not the best tool for
the job, but a large existing codebase predicates continuing development into
it.

C can also be compiled to run in-browser, but this is a rare usage.


### References

* K&R C, the canonical book
* Beej's Guide to C
* Beej's C pointer blog


### Objective

The main objective of this lab is, in fact, _not_ to teach you C. The goal here
isn't to get you as comfortable with C as you are with JavaScript. The main
points are the following:

* To get you guys working in a different language, because once you know one
  language very well, you'll reach a point where the language itself starts to
  constrain how you think about problems. Becoming familiar with other languages
  pushes the boundaries of your understanding and skills as developers. 

* A *HUGE* chunk of the world's software is written in C. Again, while the main
  goal of this lab is not to get good at writing C, it is trying to introduce
  many new concepts to you that higher-lever, dynamically-typed, interpreted
  language like JavaScript completely abstracts away from you under the hood.
  Working with C gets you much closer to the 'bare metal', giving you a much
  clearer glimpse of what computers are doing under the hood. 

With that being said, C is _really hard_. It is extremely unforgiving, and at
the same time, it is a very strict language, in large part due to the fact that
it is statically typed. Coming from JavaScript, the idea of have to specify the
type of _every_ function, variable, return value, etc. is a little foreign. In
essence, shifting to C in the coming weeks is going to be _really difficult_. We
are aware of this, and again, these labs and assignments are designed such that
you'll have learned a lot even if you only get a fraction of it completed. Try
to keep this fact in mind. :)

### Order of languages

C was once called a "higher level programming language", meaning that it has
been abstracted far enough away from hardware to enable rapid development.
Today, C is the "lowest level programming language" used in common development,
though there are still a great number of ASM developers who are writing
operating system drivers, graphics card libraries, and custom hardware.
Languages other than C are considered to be higher level, meaning they provide
more abstraction and increased developer productivity as a result of easy to use
libraries, in exchange for pure processing efficiency.

## Let's Hack!

### Hello, world!

Write and build `hello.c`. Know generally what each line means.

```c
#include <stdio.h>

int main(void)
{
  printf("Hello, world!\n");

  return 0;
}
```

Compile with the command:

`gcc -Wall -Wextra -o hello hello.c`

or

`clang -Wall -Wextra -o hello hello.c`

Then run with the command:

`./hello`

### Square-Root of 128934

Write a program that computes and prints the square root of 128934.

Use Google-fu to figure out how to do it.

