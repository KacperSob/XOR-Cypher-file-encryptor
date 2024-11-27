#include "fileoperator.h"
#include "encrypt.h"

void encrypt(char *filename){
    printf("ENCRYPTING . . .\n");

    FILE *file = fopen(filename, "r");
    if(file == NULL) return;
    FILE *keyOut = fopen("encrypted.key", "w");
    FILE *fileOut = fopen("encrypted.txt", "w");

    int keySize = rand()%1000;
    char *key = (char *)malloc(keySize*sizeof(char));

    keyGen(key, keySize, keyOut);

    char buffer[2000];
    char enc_buffer[2000];

    printf("ENCRYPTING . . .\n");

    while (fgets(buffer, 2000, file) != NULL)
    {
        encrpyt_decrypt(key, buffer, enc_buffer);
        fprintf(fileOut, "%s\n", enc_buffer);
        strcpy(enc_buffer, "");
        strcpy(buffer, "");
    }

    free(key);

    fclose(file);
    fclose(keyOut);
    fclose(fileOut);

    printf("ENCRYPTED . . .\n");
}

void keyGen(char *key, int keySize, FILE *File){
    for(int i = 0; i < keySize; i++){
        key[i] = (char)(rand()%128);
    }
    fprintf(File, "%s", key);
}

void decrypt(char *filename, char *keyFilename){
    printf("DECRYPTING . . .\n");

    FILE *file = fopen(filename, "r");
    if(file == NULL) return;
    FILE *keyIn = fopen(keyFilename, "r");
    FILE *fileOut = fopen("decrypted.txt", "w");

    char key[1000];
    fgets(key, 1000, keyIn);

    char buffer[2000];
    char enc_buffer[2000];

    printf("DECRYPTING . . .\n");

    while (fgets(buffer, 2000, file) != NULL)
    {
        encrpyt_decrypt(key, buffer, enc_buffer);
        fprintf(fileOut, "%s", enc_buffer);
    }

    fclose(file);
    fclose(keyIn);
    fclose(fileOut);

    printf("DECRYPTED . . .\n");
}