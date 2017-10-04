
#include <stdio.h>
#include <stdlib.h>

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
  
  // TODO: how to convert an integer value into a binary output / memory address
}

