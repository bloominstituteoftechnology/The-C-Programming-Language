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
