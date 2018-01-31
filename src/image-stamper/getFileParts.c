/////////////////////////////////////////////////////////
//
// Example:
// Given path == "C:\\dir1\\dir2\\dir3\\file.exe"
// will return path_ as   "C:\\dir1\\dir2\\dir3"
// Will return base_ as   "file"
// Will return ext_ as    "exe"
//
/////////////////////////////////////////////////////////
#define debugging false
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <spawn.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdbool.h> 

#define MAX_PATHNAME_LEN 4080
#define MAX_EXT_LENGTH 40

const char *get_filename_ext(const char *filename)
{
    const char *dot = strrchr(filename, '.');
    if (!dot || dot == filename)
        return "";
    return dot + 1;
}
void GetFileParts(char *path, char *path_, char *base_, char *ext_)
{

#if debugging
    printf("GetFileParts init path: %s, path_: %s base_: %s ext_: %s\n", path, path_, base_, ext_);
#endif    
    char *base;
    char *ext;
    char nameKeep[MAX_PATHNAME_LEN];
    char pathKeep[MAX_PATHNAME_LEN];
    char pathKeep2[MAX_PATHNAME_LEN]; //preserve original input string
    char File_Ext[MAX_EXT_LENGTH];
    char baseK[MAX_EXT_LENGTH];
    int lenFullPath, lenExt_, lenBase_;
    char *sDelim={0};
    int   iDelim=0;
    int  rel=0, i;

    if(path)
    {   //determine type of path string (C:\\, \\, /, ./, .\\)
        if(  (strlen(path) > 1) &&

            (
            ((path[1] == ':' ) &&
             (path[2] == '\\'))||

             (path[0] == '\\') ||

             (path[0] == '/' ) ||

            ((path[0] == '.' ) &&
             (path[1] == '/' ))||

            ((path[0] == '.' ) &&
             (path[1] == '\\'))
            )
        )
        {
            sDelim = (char *)calloc(5, sizeof(char));
            /*  //   */if(path[0] == '\\') iDelim = '\\', strcpy(sDelim, "\\");
            /*  c:\\ */if(path[1] == ':' ) iDelim = '\\', strcpy(sDelim, "\\"); // also satisfies path[2] == '\\'
            /*  /    */if(path[0] == '/' ) iDelim = '/' , strcpy(sDelim, "/" );
            /* ./    */if((path[0] == '.')&&(path[1] == '/')) iDelim = '/' , strcpy(sDelim, "/" );
            /* .\\   */if((path[0] == '.')&&(path[1] == '\\')) iDelim = '\\' , strcpy(sDelim, "\\" );
            /*  \\\\ */if((path[0] == '\\')&&(path[1] == '\\')) iDelim = '\\', strcpy(sDelim, "\\");
            if(path[0]=='.')
            {
                rel = 1;
                path[0]='*';
            }

            if(!strstr(path, "."))  // if no filename, set path to have trailing delim,
            {                      //set others to "" and return
                lenFullPath = strlen(path);
                if(path[lenFullPath-1] != iDelim)
                {
                    strcat(path, sDelim);
                    path_[0]=0;
                    base_[0]=0;
                    ext_[0]=0;
                }
            }
            else
            {
                nameKeep[0]=0;         //works with C:\\dir1\file.txt
                pathKeep[0]=0;
                pathKeep2[0]=0;        //preserves *path
                File_Ext[0]=0;
                baseK[0]=0;

                //Get lenth of full path
                lenFullPath = strlen(path);

                strcpy(nameKeep, path);
                strcpy(pathKeep, path);
                strcpy(pathKeep2, path);
                strcpy(path_, path); //capture path

                //Get length of extension:
                for(i=lenFullPath-1;i>=0;i--)
                {
                    if(pathKeep[i]=='.') break; 
                }
                lenExt_ = (lenFullPath - i) -1;

                base = strtok(path, sDelim);
                while(base)
                {
                    strcpy(File_Ext, base);
                    base = strtok(NULL, sDelim);
                }


                strcpy(baseK, File_Ext);
                lenBase_ = strlen(baseK) - lenExt_;
                baseK[lenBase_-1]=0;
                strcpy(base_, baseK);
#if debugging   
                printf("GetFileParts base_: %s\n", base_);
#endif
                path_[lenFullPath -lenExt_ -lenBase_ -1] = 0;

                ext = strtok(File_Ext, ".");
                ext = strtok(NULL, ".");
                if(ext) strcpy(ext_, ext);
                else strcpy(ext_, "");
            }
            memset(path, 0, lenFullPath);
            strcpy(path, pathKeep2);
            if(rel)path_[0]='.';//replace first "." for relative path
            free(sDelim);
        }
    }
}