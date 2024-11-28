#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encrypt.h"
#include "fileoperator.h"

bool __FGETS_INPUT_TEST(){
    FILE* input = fopen("inputtexttest.txt", "r");
    
    char buffer[4][2000];
    char output[4][2000] = {{"Hello its a me mario!"}, {"Hello its a me mario!"}, {"Hello its a me mario!"}, {"I like cars."}};
    int i = 0;

    while (fgets(buffer[i], 2000, input) != NULL)
    {
        buffer[i][strcspn(buffer[i], "\r\n")] = '\0';
        i++;
    }

    for(int i = 0; i < 4; i++){
        if(strcmp(buffer[i], output[i]) != 0) return false;
    }
    
    fclose(input);
    
    return true;
}

bool __ENC_DEC_ALGORITHM_TEST(){
    srand(time(NULL)); 
    char input[4][2000] = {{"Hello its a me mario!"}, {"Hello its a me mario!\n"}, {"Hello its a me mario!"}, {"I like cars."}};

    /*
        Algorithm does not like \n so there's a need to replece them with \0
    */
    input[0][strcspn(input[0], "\r\n")] = '\0';
    input[1][strcspn(input[1], "\r\n")] = '\0';
    input[2][strcspn(input[2], "\r\n")] = '\0';
    input[3][strcspn(input[3], "\r\n")] = '\0';

    char output[4][2000];
    char outputD[4][2000];
    int keySize = rand()%900+100;
    char *key = (char *)malloc(keySize*sizeof(char));

    for(int i = 0; i < keySize; i++){
        key[i] = (char)(rand()%255);
    }

    for(int i = 0; i < 4; i++){
        encrpyt_decrypt(key, input[i], output[i]);
    }
    for(int i = 0; i < 4; i++){
        encrpyt_decrypt(key, output[i], outputD[i]);
    }
    for(int i = 0; i < 4; i++){
        //printf("%s\n", outputD[i]);
        if(strcmp(outputD[i], input[i]) != 0 ) return false;
    }

    return true;
}

bool __ENCRYPT_FUNC_TEST(){
    encrypt("inputtexttest.txt");
    decrypt("encrypted.txt", "encrypted.key");

    FILE *decrypted = fopen("decrypted.txt", "r");
    FILE *encrypted = fopen("inputtexttest.txt", "r");

    char ebuffer[2000];
    char dbuffer[2000];

    while (fgets(ebuffer, 2000, encrypted) != NULL)
    {
        fgets(dbuffer, 2000, decrypted);
        ebuffer[strcspn(ebuffer, "\r\n")] = 0;
        dbuffer[strcspn(dbuffer, "\r\n")] = 0;
        //printf("%s | %s", ebuffer, dbuffer);
        if(strcmp(ebuffer, dbuffer) != 0) return false;
    }
    
    return true;
}

bool __ALL_ENC_TEST(){
    srand(time(NULL));


    int strSize = rand()%300+50;
    char *str = (char*)malloc(strSize*sizeof(char));
    int keySize = rand()%900+100;
    char *key = (char *)malloc(keySize*sizeof(char));
    int i, index;

    char output[2000], outputd[2000];

    for(int i = 0; i < 100; i++) {
        for (i = 0; i < strSize-1; i++) {
           index = rand() % 62;
           str[i] = random_char(index);
        }
        str[i] = '\0';
        testKeyGen(key, keySize);

        encrpyt_decrypt(key, str, output);
        encrpyt_decrypt(key, output, outputd);

        memset(str,0,strlen(str));
        memset(output,0,strlen(output));
        memset(outputd,0,strlen(outputd));

        if(strcmp(str, outputd) != 0) return false;
    } 
    
    return true;
}

void testKeyGen(char *key, int keySize){
    for(int i = 0; i < keySize; i++){
        key[i] = (char)(rand()%255);
    }
}

char random_char(int index) {char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";return charset[index];}