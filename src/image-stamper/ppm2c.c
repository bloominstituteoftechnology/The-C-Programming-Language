#define debug true
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
extern void run_cmd(char *cmd);
extern void GetFileParts(char *path, char *path_, char *base_, char *ext_);

#define MAX_PATHNAME_LEN 4080
#define TARGET_PATH "/home/mark/lambda/The-C-Programming-Language/src/image-stamper/ppm/"
#define MAX_LINE_LENGTH 512
#define MAX_PPM_LINE_FIELDS 100
#define MAX_EXT_LENGTH 40
extern const char *get_filename_ext(const char *filename);
int main(int argc, char **argv)
{

#if debug
    printf("in main\n");
#endif
#if debug
    printf("starting argc %d\n", argc);
#endif
    if (argc != 2)
    {
        printf("must be a single arg with name of image file");
        return 1;
    }
    char *inFile = argv[1];
#if debug
    printf("starting argc %d argv[1]: %s\n", argc, inFile);
#endif
    const char *ext = get_filename_ext(inFile);
#if debug
    printf("ext: %s\n", ext);
#endif
    char outputFile[MAX_PATHNAME_LEN];
    strcpy(outputFile, TARGET_PATH);

#if debug
    printf("just after TARGET_PATH copy ext: %s outputFile: %s\n", ext, outputFile);
#endif
    char *fileName = malloc(MAX_PATHNAME_LEN * sizeof(char));
    char *ext_ = malloc(MAX_EXT_LENGTH * sizeof(char));
    char *path = malloc(MAX_PATHNAME_LEN * sizeof(char));
    GetFileParts(inFile, path, fileName, ext_);
#if debug
    printf("after parts inFile: %s fileName: %s ext_: %s path: %s\n", inFile, fileName, ext_, path);
#endif
    char *hPath = (char *)malloc(MAX_PATHNAME_LEN * sizeof(char));
    strcat(outputFile, fileName);
    free(fileName);
    free(ext_);
    free(path);
    strcat(outputFile, ".ppm");

#if debug
    printf("outputFile: %s\n", outputFile);
#endif
    if ((strlen(ext) == 3) ? (strncasecmp(ext, "ppm", 3) != 0) : false)
    {
        char *buf = (char *)malloc(256 * sizeof(char));
        sprintf(buf, "convert %s -compress none %s", argv[1], outputFile);
#if debug
        printf("ext: %s command: |%s| outputFile: |%s|\n", ext, buf, outputFile);
#endif
        run_cmd(buf);
        free(buf);
    }
    else
    {
        rename(inFile, outputFile);
    }
    char c[MAX_LINE_LENGTH];
    char hBuf[MAX_LINE_LENGTH * 100];
    hBuf[0] = 0;
    FILE *f = fopen(outputFile, "r");
    fgets(hBuf, MAX_LINE_LENGTH, f);
    hBuf[strlen(hBuf) - 1] = 0; // remove trailing /n
    int h, w;
    if ((h = strcmp(hBuf, "P3")) != 0)
    {
        printf("bad PPM file, header should be 'P3', was %s  length %d strcmp return: %d\n", hBuf,(int)strlen(hBuf), h);
        return 1;
    }
    fgets(hBuf, MAX_LINE_LENGTH, f);

    if (sscanf(hBuf, "%d %d", &h, &w) != 2)
    {
        printf("bad PPM file, second line doesn't have numeric width and height %s", hBuf);
        return 1;
    }
    /*
    int scanCount = 0;

    while (fscanf(f, "%d") == 1) {

        scanCount++;
    }
    
    char *format = (char *)malloc(MAX_PPM_LINE_FIELDS * 3 + 1);
    format[0] = 0;
    strcpy(hBuf, "%d ");
    for (int i = 0; i < MAX_PPM_LINE_FIELDS; i++)
        strcat(format, hBuf);
    hBuf[strlen(hBuf) - 1] = 0;
    int *li = (int *)malloc(100 * sizeof(int));
    while (fgets(hBuf, MAX_LINE_LENGTH, f))
    {
        sscanf(hBuf, format, 
        li, li+1,li+2, li+3,li+4,li+5, li+6, li+7, li+8, li+9,
        li+10, li+11,li+12, li+13,li+14,li+15, li+16, li+17, li+18, li+19,
        li+20, li+1,li+22, li+23,li+24,li+25, li+26, li+27, li+28, li+29,
        li+30, li+31,li+32, li+33,li+34,li+5, li+6, li+7, li+8, li+9,
        li+40, li+41,li+42, li+43,li+44,li+5, li+6, li+7, li+8, li+9,
        li+50, li+51,li+52, li+53,li+54,li+5, li+6, li+7, li+8, li+9,
        li+60, li+61,li+62, li+63,li+64,li+5, li+6, li+7, li+8, li+9,
        li+70, li+71,li+72, li+73,li+74,li+5, li+6, li+7, li+8, li+9,
        li+80, li+81,li+82, li+83,li+84,li+5, li+6, li+7, li+8, li+9,
        li+90, li+91,li+92, li+93,li+94,li+5, li+6, li+7, li+8, li+9,
    }
*/
    fileName = malloc(MAX_PATHNAME_LEN * sizeof(char));
    ext_ = malloc(MAX_EXT_LENGTH * sizeof(char));
    path = malloc(MAX_PATHNAME_LEN * sizeof(char));
    GetFileParts(outputFile, path, fileName, ext_);
    strcpy(hPath, TARGET_PATH);
    strcat(hPath, fileName);
    strcat(hPath, ".h");
    // free(fileName);
    free(ext_);
    free(path);
    unlink(hPath);
    FILE *out = fopen(hPath, "w");
    FILE *in = fopen("base.h.txt", "r");

    hBuf[0] = 0;
    while (fscanf(in, "%[^\n]", c) == 1)
    {
        strcat(hBuf, strcat(c, "\n"));
    }
    fclose(in);
    fprintf(out, hBuf, fileName);
    fclose(out);
    strcpy(hPath, TARGET_PATH);
    strcat(hPath, fileName);
    strcat(hPath, ".c");
    unlink(hPath);
    out = fopen(hPath, "w");
    in = fopen("base.c.txt", "r");
    hBuf[0] = 0;
    while (fscanf(in, "%[^\n]", c) == 1)
    {
        strcat(hBuf, strcat(c, "\n"));
    }
    fclose(in);
    fprintf(out, hBuf, fileName, fileName, fileName, w, h, outputFile);
    fclose(out);
    free(fileName);
    free(hPath);
}