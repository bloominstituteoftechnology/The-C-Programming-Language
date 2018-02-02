# Intro to C

## Header Files

Listed at the top of the program:

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
```

Each `#include`d _header file_ gives access to the functionality declared in
that header file.

* Only `#include` the files you need
* Consult the `man` page for the function to see what you want to `#include`
    * If the `man` page doesn't look right, like it's for another language, try
      other manual sections, especially 2 and 3:
        * `man 2 fork`
        * `man 3 printf`

## Types

### Numeric Types

```c
// Sample declarations

int a;    // a is an integer
long a;   // a is a long integer--holds bigger values

float f;  // floating point number, like 3.14159
double f; // double-precision floating point number--holds more precise values

char c;   // 1-byte integer value, or a charcter
```

Initialization:

```c
int a = 12;
float f = 32.9;
```

### Arrays

```c
int a[20];      // array of 20 ints
float f[2][20]; // 2D array, 2 rows of 20 columns of floats
```

Initialization:

```c
int a[5] = {4, 7, 2, 9, 3};
int b[2][3] = { { 1,2,3}, {4,5,6} };

// Autosize the array to 3 elements:
int c[] = {10, 50, 100};
```

### Strings

Strings are stored as a pointer to the first element. The string terminates with
a `NUL` (`\0`) character. That is, a `NUL` is found at the end of the string.

```c
char *s; // s is a pointer to a char, or string
```

Initialization:

```c
char *s = "Hello, world!";

// Or into an array:
char t[] = "This is the secret message";
char *u = t; // t and u both refer to the same string
```

### Functions

```c
// Function that accepts an int, a float, and retuns a double

double analyze_data(int d, float f)
{
    double result;

    //... do something very complicated ...

    return result
}

// Function that accepts a string and returns its length:
int string_length(char *s)
{
    // ... compute string length ...
    return len;
}
```

### Flow Control

Works just like JavaScript for the most part:

```c
    if (a == b) {
        // ...
    }

    for (i = 0; i < 10; i++) {
        // ...
    }

    while (!done) { // booleans are "int"s, 0 is false
        // ...
    }

    do {
        // ...
    } while (x < 100);
```

## Let's Hack!

### Function with arguments

Write a function that accepts two arguments and returns the sum.

```c
#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int result = add(3, 4);

    printf("3 + 4 = %d", result);

    return 0;
}
```

Compiling and running:

```
gcc -Wall -Wextra -o add add.c

./add
```

### Square Roots of Integers

Write a function called `intsqrt` that accepts an `int` as as argument, computes
the square root of the argument, and returns the result as a `double`.

Use Google-fu to help find the answer.
