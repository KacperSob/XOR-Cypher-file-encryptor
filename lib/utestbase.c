#include "utestbase.h"
#include "tests.h"

bool TEST(int num, bool expec, bool act){
    if(act == expec) {
        printf("Test nr %d PASSED\n", num);
        return true;
    } else {
        printf("Test nr %d FAILED\n", num);
        return false;
    }
}

bool TESTS_START(){
    bool out = true;
    out = TEST(1, true, __FGETS_INPUT_TEST());
    out = TEST(2, true, __ENC_DEC_ALGORITHM_TEST());
    //out = TEST(3, true, __ALL_ENC_TEST()); // Shitty test :)
    out = TEST(3, true, __ENCRYPT_FUNC_TEST());
    return out;
}