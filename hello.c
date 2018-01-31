#include <stdio.h>

int main(void)
{
   /* Your code here */
	char answer[8] = "hangman";
	char guess[1];
  printf("%s\n", answer);
  printf("enter a letter: ");	
	scanf("%s", guess);	
  printf("%s\n", guess);

  for(int i = 0; i < answer.length(); i++) {

  }
   
  return 0;
}