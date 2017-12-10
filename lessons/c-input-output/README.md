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
    int b[100];

    printf("Enter a value: ");
    scanf("%d", &a); // The & is important for non-arrays

    printf("You entered %d\n", a);

    printf("Enter a string: ");
    scanf("%s", b); // No & with arrays (& is implied)

    printf("You entered %s\n", b);
```

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
