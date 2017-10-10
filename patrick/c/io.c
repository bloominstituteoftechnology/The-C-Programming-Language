#include <stdio.h>
#include <stdlib.h>

int main() {
  /* create a text file and put some data in it */
  FILE *file = fopen("test.txt", "w+");

  /* add some text */
  const char *text = "Where's my Lambda SWAG?";
  fprintf(file, "Some text  : \"%s\"\n", text);

  /* add an integer and float */
  int i = 1;
  float py = 3.14159265; // <~~~~ gets rounded!!!
  fprintf(file, "An integer : %d\nI love Pie : %f\n", i, py);

  /* add a single chatacters */
  char c = 'X';
  fprintf(file, "A character: '%c'\n", c);

  /* close the file */
  fclose(file);

  /* read in the file and display it to the console */
  /* How to reassign to "file" ??? */
  FILE *readfile  = fopen("test.txt", "r");
  int filecontents;
  while (1) {
    filecontents = fgetc(readfile);
    if (feof(readfile)) {
      break;
    }
    printf("%c", filecontents);
  }
  fclose(readfile);

  return 0;
}
