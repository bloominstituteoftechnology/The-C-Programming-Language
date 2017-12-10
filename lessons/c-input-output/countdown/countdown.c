/**
 * Count down from 10 to 0
 * 
 * Compile with
 * 
 *   gcc -Wall -Wextra -o countdown countdown.c
 * 
 * or 
 * 
 *   clang -Wall -Wextra -o countdown countdown.c
 * 
 * Then run with
 * 
 *   ./countdown
 */

int main(void)
{
    for (int i = 10; i >= 0; i--) {
        printf("%d\n", i);
    }

    return 0;
}