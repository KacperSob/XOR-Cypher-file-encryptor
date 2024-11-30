#include "encrypt.h"
#include <string.h>

void encrpyt_decrypt(char *key, char *input, char *output, int inputLength){
    for(int i = 0; i < strlen(input); i++){
        output[i] = input [i] ^ key [i % strlen(key)];
    }
}