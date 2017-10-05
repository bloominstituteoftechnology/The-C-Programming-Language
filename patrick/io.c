#include <stdio.h>
#include <stdlib.h>

int main() {
  /* create a text file and put some data in it */
  FILE *file = fopen("test.txt", "w+");
  // if (file == NULL) {
  //   printf("Error opening file!\n");
  //   exit(1);
  // }
  /* add some text */
  const char *text = "Where's my Lambda SWAG?";
  fprintf(file, "Some text  : \"%s\"\n", text);
  /* add an integer and float */
  int i = 1;
  float py = 3.1415927;
  fprintf(file, "An integer : %d\nI love Pie git rm --cached FILENAME: %f\n", i, py);
  /* add a single chatacters */
  char c = 'X';
  fprintf(file, "A character: '%c'\n", c);
  /* close the file */
  fclose(file);

  /* read in the file and display it to the console */
  /* How to reassign to "file" ??? */
  FILE *readfile  = fopen("test.txt", "r");
  int p;
  while (1) {
    p = fgetc(readfile);
    if (feof(readfile)) {
      break;
    }
    printf("%c", p);
  }
  fclose(readfile);

  return 0;
}
