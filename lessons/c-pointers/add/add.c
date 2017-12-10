/**
 * Function to add two ints
 * 
 * Compile with
 * 
 *   gcc -Wall -Wextra -o add add.c
 * 
 * or 
 * 
 *   clang -Wall -Wextra -o add add.c
 * 
 * Then run with
 * 
 *   ./add
 */

#include <stdio.h>

void add(int a, int b, int *result)
{
	*result = a + b;
}

int main(void)
{
	int sum;

	// Pass a pointer to sum so the function can change it
	add(3, 4, &sum);

    printf("%d\n", sum); // Prints 7
    
    return 0;
}