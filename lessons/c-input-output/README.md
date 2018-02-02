# Input and Output in C

## Output with `printf`

```c
    int a = 5;
    int f = 3.14;
    double g = 3.14159265358979;

    printf("Hello, world!\n");

    printf("This is an integer: %d\n", a);

    printf("Here's an integer %d and a float %f\n", a, f);

    printf("And a double: %lf\n", g);
```

The first string argument to `printf` is called the _format string_. The
significant letter or letters after the `%` are called the _format specifier_.

`printf` can put leading zeros on, print things in hexadecimal, justify left or
right, set field widths, and all kinds of stuff.

> Fun Fact: The `printf` function actually makes an appearance in Python as the
> `%` string operator.

## Input with `scanf`

```c
    int a;
    char b[100];

    printf("Enter a value: ");
    scanf("%d", &a); // The & is important for non-arrays

    printf("You entered %d\n", a);

    printf("Enter a string: ");
    scanf("%s", b); // No & with arrays (& is implied)

    printf("You entered %s\n", b);
```

## File I/O

You can open a file for reading or writing with `fopen()`. Then use `fprintf()`
to write to it, or `fscanf()` to read from it (just as if it were the screen or
keyboard).

```c
    FILE *fp;

    fp = fopen("myfile.txt", "w"); // or "r" for read

    if (fp == NULL) {
        printf("An error occurred opening the file!\n");
        printf("Probably file not found.\n");
    } else {
        // Print this to the file
        int data = 12;

        fprintf(fp, "Hello, world! Data is %d.\n", data);

        fclose(fp); // All done, close the file
    }
```

## Standard File Names

There are three standard files that are already open for you when you use the `stdio` routines.

* `stdin`: standard input (the keyboard, typically)
* `stdout`: standard output (the screen, typically)
* `stderr`: standard error (also the screen, but used for error messages)

These two lines are equivalent:

```c
printf("Hi!\n");           // prints to stdout
fprintf(stdout, "Hi!\n");  // prints to stdout, too
```

The most common use case is printing errors:

```c
fprintf(stderr, "Oh, man... something awful happened.\n");
```

## References

* [Beej's Guide to C `printf` reference](http://beej.us/guide/bgc/output/html/multipage/printf.html)
* [`printf` `man` page](https://linux.die.net/man/3/printf)

## Let's Hack!

### Print a Countdown

Count down from 10 to 0.

```c
int main(void)
{
    for (int i = 10; i >= 0; i--) {
        printf("%d\n", i);
    }

    return 0;
}
```

### Adder

Read two numbers from the keyboard and print out their sum.
