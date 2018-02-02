# Pointers in C

*Pointers are a hard concept. Once they click, they're easy. But they are really
the only conceptually difficult thing in C.*

## The Main Problems

### Multiple return values from functions

Functions have one return value. What if you want to have them change multiple
things?

Spoiler: you can pass pointers to those things to the function, and then the
function can manipulate those things via the pointers.

### Large objects can be inefficient to copy

When you pass an argument to a function, a copy of that argument is made. If the
argument is, say, a large `struct`ure, it might take a relatively long time to
copy on.

Spoiler: a pointer is just a 32-bit or 64-bit number, so it's quick to copy on
as an argument, so pass a pointer to the `struct` instead.

## What's a Pointer?

Remember how memory in a computer is like a big array that hold bytes?

Remember how the indexes into that array are called _addresses_?

A _pointer_ is another name for _address_ in C.

You can have pointers to specific addresses, like so:

```c
char *p = (char *)0x372;
```

but nearly 100% of the time we're more interested in a pointer to a variable
we've declared or we're passing into a function. We want to know what its
address is.

## Getting the Address of a Variable

*AKA getting the pointer to an object from the object.*

Use the _address-of_ operator, and store the result in a variable of
_pointer-type_:

```c
    int a = 12;  // a is a regular variable
    int *p = &a; // int-pointer p points to a
```

For the address of the first element in an array, you can just leave off the
brackets on the array name. This is shorthand for "pointer to the first element
in the array":

```c
    int a[3] = {10, 20, 30};
	int *p = a; // p points to first element in a
```

## Dereferencing

*AKA getting the object from a pointer to that object.*

If you have a pointer to an object, you can refer to the original object by
_dereferencing_ the pointer with the `*` operator.

```c
	int a = 12;
	int *p = &a; // Pointer declaration, NOT a dereference!

	*p = 99; // That's a dereference
	printf("%d\n", a); // Prints 99! Why?
```

Don't get confused by all the uses of `*` in C. It's all in the context.

```c
	/* This is a comment */

	int a = 12;
	int *p = &a; // Declaring a variable, * means this is a pointer variable

	*p = 99;    // Dereference, manipulating object p points to, a

	a *= 12;    // Multiply, not a dereference
```

## Passing Pointers into Functions

So you have a pointer to another object, who cares? Why not just use the object?

Check this out:

```c
void add(int a, int b, int *result)
{
	// result is the local name for the &sum argument that got passed in.
	
	// >> result points to sum back out in main()!! <<

	// We use the dereference operator '*' to manipulate the thing
	// result points to:

	*result = a + b;  // <-- MAGIC HERE
}

int main(void)
{
	int sum;

	// Pass a pointer to sum so the function can change it
	add(3, 4, &sum);

	printf("%d\n", sum); // Prints 7

	return 0;
}
```

You can pass as many pointers as you want as arguments.

What happened on that dereference line?

```c
	*result = a + b;
```

We're saying, "Compute the sum `a + b` and then set whatever `results` points at to that sum."

## Dynamic Memory

When allocating objects or arrays to use at runtime, pointers are used to track
the object or the first element of the allocated array.

> You'd dynamically allocate objects if you didn't know at compile-time how many
> objects you needed.

**Be sure to free memory when you're done with it!** Failure to do so will
result in a _memory leak_.

```c
// Allocate 10 ints
int *a = malloc(sizeof(int) * 10);

// a[0] is the 0th element in the array
// a[1] is the 1st element

// ....

// When done, free it:
free(a);
```

```c
// Allocate a single new animal structure
struct animal *x = malloc(sizeof(struct animal));

// Use the arrow operator to access fields of the struct pointer:
// x->leg_count

// ....

// When done, free it:
free(x);
```

## The Heap and Stack

> Though the concept of stack and heap do not appear in the C language
> specification, and so theoretically do not exist, they are actually
> things that do exist that all C programmer are aware of.

When you allocate memory with `malloc()`, it goes in an area of memory
called _the heap_. It persists on the heap until explicitly freed with
`free()`, or until the program exits.

Because the memory persists, it makes it legal to do something like this:

```c
int *give_me_an_int(void)
{
	int *p = malloc(sizeof(int));

	return p;
}
```

On the other hand, local variables, including local arrays, are
allocated on _the stack_. When a function returns, all its local
variables are popped off the stack and thrown away.

This is why it's bad to do this:

```c
int *give_me_an_int_badly(void)
{
	int x = 12;

	return &x;
}
```

When the function returns, the local variable `x` is automatically
destroyed. The pointer to it is invalid and undefined behavior will
result if it is accessed.

## `NULL` Pointer

`NULL` is a special value a pointer can be given to indicate that the pointer points at nothing.

```c
int *p = NULL;

if (p == NULL) {
	p = malloc(100);
}
```

## References

* [Pointers in Beej's Guide to C](http://beej.us/guide/bgc/output/html/multipage/pointers.html)
* [Beej's Blog entry on pointers in C](http://beej.us/blog/data/c-pointers/)

## Let's Hack!

### Pass arguments to functions

```c
void add(int a, int b, int *result)
{
	*result = a + b;
}
```

### Add-Subtract

Write the function `add_subtract` to make this code output "SUCCESS" two times:

```c
int main(void)
{
	int a = 30, b = 5;

	add_subtract(&a, &b);

	if (a == 35 && b == 25) {
		printf("SUCCESS\n");
	}

	a = 100;
	b = 50;

	add_subtract(&a, &b);

	if (a == 150 && b == 50) {
		printf("SUCCESS\n");
	}

	return 0;
}
```
