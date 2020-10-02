#include <string.h>
#include "qc.h"
#include "crypto.h"

int main() {
    char const* input = "РАЗУМА ЛИШАЕТ НЕ СОМНЕНИЕ, А УВЕРЕННОСТЬ";
    char* encrypted = caesar_keyword_cipher_encrypt(input, 5, "ВЕСНА");
    qc_assert(strcmp(encrypted, "ЙЫНМЁЫДАУЫВЛЖВКЗЁЖВЖАВЫМЭВЙВЖЖЗКЛЧ") == 0, "Caesar keyword cipher encryption is broken");
    free(encrypted);
}
