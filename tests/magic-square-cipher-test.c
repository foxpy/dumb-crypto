#include <string.h>
#include "qc.h"
#include "crypto.h"

void test3x3() {
    char const* input = "ШЛА САША.";
    char* encrypted = magic_square_encrypt(input, 9, (const size_t[]){2, 7, 6, 9, 5, 1, 4, 3, 8});
    qc_assert(strcmp(encrypted, "ЛША.СШ АА") == 0, "Magic square cipher encryption is broken");
    free(encrypted);
}

int main() {
    test3x3();
}
