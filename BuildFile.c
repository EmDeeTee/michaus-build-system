#include "BuildFile.h"
#include "Parser.h"

extern char FilesToBuild[1024];
extern char CompilerFlags[1024];
extern char CompilerToUse[128];

void ReadBuildFile() {
    config_option_t co;
    if ((co = read_config_file("mbs")) == NULL) {
        perror("Can't find the 'mbs' file! I'm giving up :(");
        exit(-1);
    }
    while(1) {
        //printf("Key: %s\nValue: %s\n", co->key, co->value);
        if (strcmp(co->key, "FILES") == 0)
            strcpy(FilesToBuild, co->value);
        if (strcmp(co->key, "COMPILER") == 0) {
            strcpy(CompilerToUse, co->value);
            strcat(CompilerToUse, " ");
        }
        if (strcmp(co->key, "FLAGS") == 0) {
            strcpy(CompilerFlags, co->value);
            strcat(CompilerFlags, " ");
        }

        // Replace comas for dots in file string and flags string
        for(int i=0;FilesToBuild[i]!='\0';i++) {
            if(FilesToBuild[i]==',') {
                    FilesToBuild[i] = ' ';
            }
            else
                continue;
        }
        for(int i=0;CompilerFlags[i]!='\0';i++) {
            if(CompilerFlags[i]==',') {
                    CompilerFlags[i] = ' ';
            }
            else
                continue;
        }

        if (co->prev != NULL) {
            co = co->prev;
        } else {break;}
    }
}
