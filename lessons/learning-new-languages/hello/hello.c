/**
 * Classic hello, world
 * 
 * Compile with
 * 
 *   gcc -Wall -Wextra -o hello hello.c
 * 
 * or 
 * 
 *   clang -Wall -Wextra -o hello hello.c
 * 
 * Then run with
 * 
 *   ./hello
 */

// // 1st challenge

// #include <stdio.h>

// int main(void)
// {
//     printf("Hello, world!\n");

//     return 0;
// }

// // 2nd challenge

// #include "stdio.h" //is a statement which tells the compiler to insert the contents of stdio at that particular place.
// #include "math.h"

// int main(void) {
//   int a, result;
  
//   printf("Enter the value: ");
//   scanf("%d", &a); // The & is important for non-arrays

//   result = sqrt(a);
//   printf("Square root of %d = %d\n", a, result);

//   return 0;
// }

// // 3rd challenge
// #include "stdio.h" //is a statement which tells the compiler to insert the contents of stdio at that particular place.
// #include "math.h"

// int main(void) {
//   int a;
//   int b;
//   int sum;
  
//   printf("Enter the first value: ");
//   scanf("%d", &a); // The & is important for non-arrays

//   printf("Enter the second value: ");
//   scanf("%d", &b); // The & is important for non-arrays

//   sum = a + b;
//   printf("the sum of two numbers is %d\n", sum);

// }

// 4th challenge

//-------------- Examples
// void add(int a, int b, int *result)
// {
// 	// result is the local name for the &sum argument that got passed in.

// 	// >> result points to sum back out in main()!! <<

// 	// We use the dereference operator '*' to manipulate the thing
// 	// result points to:

// 	*result = a + b;  // <-- MAGIC HERE
// }

// void mul(int a, int b, int *result)
// {
// 	// result is the local name for the &sum argument that got passed in.

// 	// >> result points to sum back out in main()!! <<

// 	// We use the dereference operator '*' to manipulate the thing
// 	// result points to:

// 	*result = a * b;  // <-- MAGIC HERE
// }

// int main(void)
// {
// 	int result;

// 	// Pass a pointer to sum so the function can change it
// 	add(3, 4, &result);

// 	printf("%d\n", result); // Add func = Prints 7, Mul func = Print 12

// 	return 0;
// }
// --------------- Examples above ---------------

void add_subtract(int a, int b, int *a, int *b)
{
	// result is the local name for the &sum argument that got passed in.

	// >> result points to sum back out in main()!! <<

	// We use the dereference operator '*' to manipulate the thing
	// result points to:

	*a = a + b;  // <-- MAGIC HERE
	*b = a - b;
}

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