#include "BuildFile.h"
#include "Parser.h"

extern char FilesToBuild[1024];

void ReadBuildFile() {
    config_option_t co;
        if ((co = read_config_file("mbs")) == NULL) {
            perror("Can't find the 'mbs' file! I'm giving up :(");
            exit(-1);
        }
        while(1) {
            //printf("Key: %s\nValue: %s\n", co->key, co->value);
            strcpy(FilesToBuild, co->value);
            for(int i=0;FilesToBuild[i]!='\0';i++) {
                if(FilesToBuild[i]==',') {
                        FilesToBuild[i] = ' ';
                }
                else
                        continue;
            }
            if (co->prev != NULL) {
                co = co->prev;
            } else {
                break;
            }
        }
}
