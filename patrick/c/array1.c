#include <stdio.h>

int main() {
  int arraySize = 50;
  int array[arraySize];
  int i;
  for (i = 0; i < arraySize; ++i) {
    array[i] = i * i;
    // printf("array[%2d]: %4d at address %p\n", i, array[i], array);
  }
  int j;
  for (j = 0; j <= arraySize + 20; ++j) { // what is this weird stuff?
    printf("array[%2d]: %4d at address %p\n", j, array[j], array);
  }

  printf("%p is the address in memory of the array.\n", array);
  printf("%lu bytes is the array size\n", sizeof(array));
  printf("The compiler's size for a single int is: %lubytes\n", sizeof(int));
  printf("There are %lu bytes constituting the array.\n", sizeof(array));
  int numOfItems = sizeof(array)/sizeof(array[0]);
  printf("(%lu bytes) times (%d items) === (%lu bytes) which make up the array\n", sizeof(int), numOfItems, sizeof(array));
  puts("what are the array values at 50 - 70?");
  printf("size of a void pointer: %lu\n", sizeof(void*));
}
