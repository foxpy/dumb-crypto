#include <stdlib.h>
#include "unicode.h"
#include "qc.h"

int main() {
    for (char c = 'a', end = 'z'; c <= end; ++c) {
        qc_assert(unicode_symbol_len(&c) == 1, "Expected 1 byte");
    }

    static char* some_russian_symbols[] = {"а", "з", "в", "Я", "у"};
    for (size_t i = 0; i < sizeof(some_russian_symbols)/sizeof(some_russian_symbols[0]); ++i) {
        qc_assert(unicode_symbol_len(some_russian_symbols[i]) == 2, "Expected 2 bytes");
    }

    static char* three_byte_emojis[] = {"❤️"};
    for (size_t i = 0; i < sizeof(three_byte_emojis)/sizeof(three_byte_emojis[0]); ++i) {
        qc_assert(unicode_symbol_len(three_byte_emojis[i]) == 3, "Expected 3 bytes");
    }

    static char* four_byte_emojis[] = {"😼"};
    for (size_t i = 0; i < sizeof(four_byte_emojis)/sizeof(four_byte_emojis[0]); ++i) {
        qc_assert(unicode_symbol_len(four_byte_emojis[i]) == 4, "Expected 4 bytes");
    }

    exit(EXIT_SUCCESS);
}
