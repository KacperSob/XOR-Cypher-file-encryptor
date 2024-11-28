#include <stdbool.h>

#ifndef TESTS_H
#define TESTS_H

bool __FGETS_INPUT_TEST();
bool __ENC_DEC_ALGORITHM_TEST();
bool __ENCRYPT_FUNC_TEST();
bool __ALL_ENC_TEST();
void testKeyGen(char *, int);
char random_char(int);

#endif