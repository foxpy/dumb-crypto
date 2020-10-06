#include <string.h>
#include "qc.h"
#include "crypto.h"

void simple_test() {
    char const* input = "ПРИЛЕТАЮЗАВТРА";
    char* encrypted = playfair_cipher_encrypt(input, 8, 4, "РАБОТА");
    qc_assert(strcmp(encrypted, "НАЙМЙРГЩЖБГВАБ") == 0, "Playfair cipher encryption is broken");
    free(encrypted);
}

int main() {
    simple_test();
}
