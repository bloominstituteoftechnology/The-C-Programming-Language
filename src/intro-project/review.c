
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Makefile
// make

int main(int argc, char** argv) {

  int a = 5;
  printf("Process memory address of a: %p\n", &a);

  int* ap = &a;
  printf("Process memory address of ap: %p\n", ap);

  int* b;
  printf("Process memory address of b: %p\n", b);

  // these are the same: puts is put string
  // printf is print formatted
  puts("b has not been allocated yet");
  printf("%s", "b has not been allocated yet\n");

  //int* c = a;
  //printf("What in the binary value of a: %p",(void*)a);

  b = malloc(sizeof(int));
  puts("b just got allocated");
  printf("Process memory address of b: %p\n", b);

  *b = 6;
  printf("Value of b: %d\n", *b);

  free(b);

  int** d;
  //(cp->cp->c);
  //**c = 7;
  //printf("c: %d", **c); 
  
  char e = 'e';
  char f = 95;

  // javascript way of doing it dynamically:
  //let radical = {};
  //let less_radical = [];
  //less_radical.push(5);
  
  int array[50];
  int i;

  for(i = 0 ; i < 50 ; ++i ) {
    array[i] = i*i;
  }

  int ii;
  for(ii = 0 ; ii < 50 ; ii++ ) {
    printf("%d\n", array[ii]);
  }

  // pre-allocated array - not as useful
  int twoDArrayOldStyle[1000][1000];
  for(i = 0 ; i < 1000; ++i ) {
    for(ii = 0 ; ii < 1000; ii++ ) {
      twoDArrayOldStyle[i][ii] = 1;
    }
  }

  puts("Too big?");
  //int twoDArrayHuge[1000000][1000000];

  // dynamically allocated array
  int m = 100000;
  int n = 100000;
  int diameter = 5;

  // twoDArray is a memory address of an array of memory addresses
  int** twoDArray;

  twoDArray = malloc(m * sizeof(void*));
  for(i = 0 ; i < m ; ++i ) {
    twoDArray[i] = malloc(n * sizeof(int));
  }

  puts("Can I assign memory into my 2d array?");
  for(i = 0 ; i < m; ++i ) {
    for(ii = 0 ; ii < n; ii++ ) {
      if( sqrt(abs(i-m/2)*abs(ii-n/2)) < diameter && sqrt(abs(i-m/2)*abs(ii-n/2) > diameter-1 ) ) {
        twoDArray[i][ii] = 1;
      }
      else {
        twoDArray[i][ii] = 0;
      }
    }
  }

  /*
  for(i = 0 ; i < m ; ++i ) {
    for(ii = 0 ; ii < n; ii++ ) {
      printf("%d", twoDArray[i][ii]);
    }
    printf("\n");
  }
  */

  char x = getc(stdin);
  for(i = 0 ; i < m ; ++i ) {
    free(twoDArray[i]);
  }
  free(twoDArray);
  
  // TODO: how to convert an integer value into a binary output / memory address
}

