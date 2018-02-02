# C build process

C is a compiled language. This means that the syntax and tokens that you write
in your `.c` file are converted from the "higher level language" of C directly
into machine language, and are loaded into and executed deterministically by the
CPU.

C is more than compiled, however; C programs are built in a series of steps.

Normally these steps are hidden in a single command:

`gcc -o foo foo.c`

or 

`clang -o foo foo.c`

But if we want, we can interrupt at any one of the internal steps the C compiler takes:

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

## Let's Hack!

### Preprocessor output

Run this program through the C preprocessor. Examine the output.

```c
#include <stdio.h>

#define GOAT_COUNT 12
#define SHEEP_COUNT 20

int main(void)
{
    int total = GOAT_COUNT + SHEEP_COUNT;
    printf("I have %d animals\n", total);

    return 0;
}
```

### Assembly Output

Generate assembly for the above program. Examine it and try to figure out which
instructions correspond to which lines of assembly code correspond to which
lines of C code.
