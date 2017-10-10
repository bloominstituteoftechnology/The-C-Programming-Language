// C array[][]

//  1024x768
const image = [
  [ [24, 125, 256], [44, 125, 256], [24, 66, 77], [24, 125, 256], [24, 125, 256]],
  [ [234, 33, 256], [24, 125, 256], [33, 33, 77], [24, 125, 256], [24, 125, 256]],
  [ [24, 125, 256], [24, 125, 256], [22, 125, 55], [24, 125, 256], [24, 125, 256]],
]

int main() {
  const int width = 1024, height = 768;
  const int max = 255;

  /* WRITE PPM HEADER INFORMATION */
  /* NESTED FOR LOOP COLOR MAGICKS */
  for (let row = 0; row < height; ++row) {
    for (let col = 0; col < width; ++col) {
      let red = abs(row * (max + 1) / width - 35);
      let green = abs(col * (max + 1) / width - 112);
      int blue = abs(col * (max + 1) / width - 92);
      if (col == width - 1) {
        fprintf(imageFile, "%d %d %d\n", red, green, blue);
      } else {
        fprintf(imageFile, "%d %d %d  ", red, green, blue);
      }
    }
  }

  // for rows 40 thru 50 by colums 100 through 110 write rgb values 0, 0, 0 read in another PPM files



  fclose(imageFile);

  return 0;
}
