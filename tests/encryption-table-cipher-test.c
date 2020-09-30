#include <string.h>
#include "crypto.h"
#include "qc.h"

void test2x2() {
    char* input = "АБВГДЕЁЖЗИЙК";
    char* output = encryption_table_encrypt(input, 2, 2);
    qc_assert(strcmp(output, "АВБГДЁЕЖЗЙИК") == 0, "Encryption table cipher encryption is broken");
}

void test3x3() {
    char* input = "QWАБВГERT";
    char* output = encryption_table_encrypt(input, 3, 3);
    qc_assert(strcmp(output, "QБЕWБRАГT"), "Encryption table cipher encryption is broken");
}

int main() {
    test2x2();
    test3x3();
}
