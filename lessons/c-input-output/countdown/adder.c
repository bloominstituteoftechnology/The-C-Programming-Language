#include <stdio.h>
#include <math.h>


int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int a;
    int b;

    printf("Enter a value: ");
    scanf("%d", &a);

    printf("Enter another value: ");
    scanf("%d", &b);

    int result = add(a, b);

    printf("%d + %d = %d\n", a, b, result);

    return 0;
}