#include <stdio.h>
#include <string.h>
#include "encrypt.h"
#include <time.h>
#include <stdlib.h>

#ifndef FILEOPERATOR_H
#define FILEOPERATOR_H

void encrypt(char *filename);

void decrypt(char *filename, char *keyFilename);

void keyGen(char *key, int keySize, FILE *File);

#endif