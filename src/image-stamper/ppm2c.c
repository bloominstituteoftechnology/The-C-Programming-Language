#define debug false
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
extern void run_cmd(char *cmd);
extern void GetFileParts(char *path, char *path_, char *base_, char *ext_);

#define MAX_PATHNAME_LENGTH 4080
#define TARGET_PATH "/home/mark/lambda/The-C-Programming-Language/src/image-stamper/ppm/"
#define MAX_LINE_LENGTH 512
#define MAX_PPM_LINE_FIELDS 100
#define MAX_EXT_LENGTH 40
#define MaxIncludeLength 100
#define MaxFiles 100
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
        printf("must be a single arg with name of image file\n");
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
    char outputFile[MAX_PATHNAME_LENGTH];
    strcpy(outputFile, TARGET_PATH);
    char c[MAX_LINE_LENGTH];
    char hBuf[MAX_LINE_LENGTH * 100];
    hBuf[0] = 0;
#if debug
    printf("just after TARGET_PATH copy ext: %s outputFile: %s\n", ext, outputFile);
#endif
    char *fileName = malloc(MAX_PATHNAME_LENGTH * sizeof(char));
    char *ext_ = malloc(MAX_EXT_LENGTH * sizeof(char));
    char *path = malloc(MAX_PATHNAME_LENGTH * sizeof(char));
    GetFileParts(inFile, path, fileName, ext_);
#if debug
    printf("after parts inFile: %s fileName: %s ext_: %s path: %s\n", inFile, fileName, ext_, path);
#endif

    

    char *hPath = (char *)malloc(MAX_PATHNAME_LENGTH * sizeof(char));
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

    FILE *f = fopen(outputFile, "r");
    if (f == NULL) {
        printf("convert failed, likely bad file name %s\n", outputFile);
        free(hPath);
        return 1;
    }
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
        printf("bad PPM file, second line doesn't have numeric width and height %s\n", hBuf);
        return 1;
    }
    fileName = malloc(MAX_PATHNAME_LENGTH * sizeof(char));
    ext_ = malloc(MAX_EXT_LENGTH * sizeof(char));
    path = malloc(MAX_PATHNAME_LENGTH * sizeof(char));
    fileName[0] = 0;
    ext_[0] = 0;
    path[0] = 0;
    GetFileParts(outputFile, path, fileName, ext_);
#if debug
    printf("after parts outputFile: %s fileName: %s ext_: %s path: %s\n", outputFile, fileName, ext_, path);
#endif   
    FILE * allH = fopen("allPPM.h","a+");
    char * allBuf = malloc(MaxIncludeLength*MaxFiles); // max number of files implimented
    allBuf[0] = 0;
    do {
        fgets(c, MaxIncludeLength, allH);
        if (feof(allH)) break;
        strcat(allBuf, c);
    } while(true);
    sprintf(hBuf, "\t#include \"./ppm/%s.h\"\n", fileName);
    if (strstr(allBuf,hBuf) == NULL) {
        fputs(hBuf, allH);
    }
    free(allBuf);
    fclose(allH);

    char * capFileName = strdup(fileName);
    capFileName[0] = toupper(capFileName[0]);
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
#if debug
    printf("before h while hPath %s  out->_flags: %d\n", hPath, out->_flags);
#endif    
    while(fgets(c, MAX_LINE_LENGTH, in))
    {
        strcat(hBuf, c);
    }
    fclose(in);
#if debug
    printf("hBuf %s, fileName: %s\n",hBuf, fileName);
#endif    
    fprintf(out, hBuf, capFileName);
    fclose(out);
    strcpy(hPath, TARGET_PATH);
    strcat(hPath, fileName);
    strcat(hPath, ".c");
#if debug
    printf("c hPath: %s\n",hPath);
    // const int maxLines = 10;
    int lines = 0;
#endif     
    unlink(hPath);
    out = fopen(hPath, "w");
    in = fopen("base.c.txt", "r");  
    hBuf[0] = 0;
 
    // while (fscanf(in, "%[^\n]", c) == 1)
    do 
    {
        fgets(c, MAX_LINE_LENGTH, in);
        strcat(hBuf, c);
        if (feof(in)) {
#if debug
           printf("c input lines: %d\n", lines);
#endif            
            break;
        }     
#if debug
        lines++;
#endif         
    } while(true);
    fclose(in);
#if debug
    printf("before c frpintf fileName: %s, w: %d, h: %d, outputFile: %s  hBuf length: %d  out->_flags: %d\n", fileName, w, h, outputFile,
                (int)strlen(hBuf),out->_flags);
    //fputs("0", out);
    // printf("after test fputs of 0\n");
    // return 0;
#endif     
    fprintf(out, hBuf, fileName, capFileName, w, h, outputFile);
#if debug    
    printf("after fprintf\n");
#endif
    fclose(out);
#if debug    
    printf("after close\n");
#endif    
    free(fileName);
    free(capFileName);
#if debug    
    printf("after free fileName\n");
#endif       
    free(hPath);
    return 0;
}