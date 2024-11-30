#include "fileoperator.h"
#include "encrypt.h"
#include "time.h"

#define KEY_SIZE 255

void encrypt(char *filename){
    srand(time(NULL));
    //printf("ENCRYPTING . . .\n");

    FILE *file = fopen(filename, "r");
    if(file == NULL) return;
    FILE *keyOut = fopen("encrypted.key", "w");
    FILE *fileOut = fopen("encrypted.txt", "w");

    int keySize = rand()%900+100;
    char *key = (char *)malloc(keySize*sizeof(char));

    keyGen(key, keySize, keyOut);

    char buffer[2000];
    char enc_buffer[3000];

    //printf("ENCRYPTING . . .\n");

    while (fgets(buffer, 2000, file) != NULL)
    {
        buffer[strcspn(buffer, "\r\n")] = 0;
        memset(enc_buffer,0,3000);
        encrpyt_decrypt(key, buffer, enc_buffer, strlen(buffer));
        fprintf(fileOut, "%s\n", enc_buffer);
        memset(buffer,0,2000);
    }

    free(key);

    fclose(file);
    fclose(keyOut);
    fclose(fileOut);

    //printf("ENCRYPTED . . .\n");
}

void keyGen(char *key, int keySize, FILE *File){
    srand(time(NULL)); 
    for(int i = 0; i < keySize; i++){
        key[i] = (char)(rand()%KEY_SIZE);
    }
    key[strcspn(key, "\r\n")] = 0;
    fprintf(File, "%s", key);
}

void decrypt(char *filename, char *keyFilename){
    //printf("DECRYPTING . . .\n");

    FILE *file = fopen(filename, "r");
    if(file == NULL) return;
    FILE *keyIn = fopen(keyFilename, "r");
    FILE *fileOut = fopen("decrypted.txt", "w");

    char key[2000];
    fgets(key, 2000, keyIn);

    char buffer[2000];
    char enc_buffer[3000];

    //printf("DECRYPTING . . .\n");

    while (fgets(buffer, 2000, file) != NULL)
    {
        buffer[strcspn(buffer, "\r\n")] = 0;
        memset(enc_buffer,0,3000);
        encrpyt_decrypt(key, buffer, enc_buffer, strlen(buffer));
        fprintf(fileOut, "%s\n", enc_buffer);
        memset(buffer,0,2000);
    }

    fclose(file);
    fclose(keyIn);
    fclose(fileOut);

    //printf("DECRYPTED . . .\n");
}