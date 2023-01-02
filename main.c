// THIS WAS A MASSIVE MISTAKE. INSTANT REGRET. C++ IS BETTER CHANGE MY MIND



#include <stdio.h>
#include <string.h>
#include "BuildFile.h"

char FilesToBuild[1024];
char CompilerFlags[1024];
char CompilerToUse[128];

int main() {
    printf("Welcome to Michau's Build System - MBS\n");
    ReadBuildFile();
    printf("Files that will be included: %s\n", FilesToBuild);
    printf("Project will be compiled using: %s\n", CompilerToUse);
    printf("Compiler will get the following flags: %s\n", CompilerFlags);
    char *new_str ;
    if((new_str = malloc(strlen(CompilerToUse)+strlen(FilesToBuild)+1)) != NULL){
        new_str[0] = '\0';   // ensures the memory is an empty string
        strcat(new_str,CompilerToUse);
        strcat(new_str,CompilerFlags);
        strcat(new_str,FilesToBuild);
    } else {
        perror("malloc failed! AAAAAAAAAAAAAAAAAAAAAAA\n");
        exit(-1);
    }
    printf("Running the compiler...\n");
    system(new_str);
    free(new_str);
    printf("DONE!\n");
    return 0;
}
