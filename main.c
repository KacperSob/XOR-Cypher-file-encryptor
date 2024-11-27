#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib/fileoperator.h"

#define ERROR_MSG "Wrong usage!\n\nPlease use\n$ encrypt.exe filename -e|-d <keyname.key>\n\n-e        \tENCRYPT FILE\n-d key.key\tDECRYPT FILE\n\n"

int main(int argc, char* argv[]){
    if(argc < 3 || argc > 4){
        printf(ERROR_MSG);
        return 0;
    }

    if(strcmp(argv[2], "-e") == 0) {
        encrypt(argv[1]);
    } else if(strcmp(argv[2], "-d") == 0){
        decrypt(argv[1], argv[3]);
    } else {
        for(int i = 0; i<argc; i++){
            printf("%s\n", argv[i]);
        }
        printf(ERROR_MSG);        
    }
    return 0;
}