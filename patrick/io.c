#include <stdio.h>
#include <stdlib.h>

int main() {
  /* create a text file and put some data in it */
  FILE *f = fopen("test.txt", "w+");
  if (f == NULL) {
    printf("Error opening file!\n");
    exit(1);
  }
  /* add some text */
  const char *text = "Where's my Lambda SWAG?";
  fprintf(f, "Some text: \"%s\"\n", text);
  /* add an integer and float */
  int i = 1;
  float py = 3.1415927;
  fprintf(f, "An integer: %d\nI love Pie: %f\n", i, py);
  /* add a single chatacters */
  char c = 'X';
  fprintf(f, "A character: '%c'\n", c);
  /* close the file */
  fclose(f);

  /* read in the file and display it to the console */
  FILE *o  = fopen("test.txt", "r");
  int p;
  while (1) {
    p = fgetc(o);
    if (feof(o)) {
      break;
    }
    printf("%c", p);
  }
  fclose(o);

  return 0;
}
