// gcc -Wall -Wextra -o testls testls.c



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**

* Main

*/

int main(void)
{
//char *word = malloc(sizeof(char) * 8);
	char  word[] = {'h','a','n','g','m','a','n'};
  int size = sizeof(word)/sizeof(word[0]);
  printf("%c\n", word[7]);
  printf("%d\n", size);


  for (int i = 0; i < strlen(word); i++) {
    printf("%c\n", word[i]);
  }
  // free(word);
 return 0;

}