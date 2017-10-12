#include <stdio.h>
int main() {
  int****** wth;
  printf("wth1  :%p & %lu\n", wth, wth);
  int***** why = &wth;
  int**** norly = &why;
  int*** seriz = &norly;
  int** noooo = &seriz;
  int* lame = &noooo;
  int five = 5;
  wth = &five;
  printf("why:   %p & %lu\n", why, why);
  printf("norly: %p & %lu\n", norly, norly);
  printf("seriz: %p & %lu\n", seriz, seriz);
  printf("noooo: %p & %lu\n", noooo, noooo);
  printf("lame:  %p & %lu\n", lame, lame);
  printf("five:  %p & %lu\n", five, five);
  printf("wth2:  %p & %lu\n", wth, wth);
  return 0;
}
