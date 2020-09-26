#include <stdlib.h>
#include "unicode.h"

int main() {
    for (char c = 'a', end = 'z'; c <= end; ++c) {
        if (unicode_symbol_len(&c) != 1) {
            exit(EXIT_FAILURE);
        }
    }

    static char* some_russian_symbols[] = {"а", "з", "в", "Я", "у"};
    for (size_t i = 0; i < sizeof(some_russian_symbols)/sizeof(some_russian_symbols[0]); ++i) {
        if (unicode_symbol_len(some_russian_symbols[i]) != 2) {
            exit(EXIT_FAILURE);
        }
    }

    static char* three_byte_emojis[] = {"❤️"};
    for (size_t i = 0; i < sizeof(three_byte_emojis)/sizeof(three_byte_emojis[0]); ++i) {
        if (unicode_symbol_len(three_byte_emojis[i]) != 3) {
            exit(EXIT_FAILURE);
        }
    }

    static char* four_byte_emojis[] = {"😼"};
    for (size_t i = 0; i < sizeof(four_byte_emojis)/sizeof(four_byte_emojis[0]); ++i) {
        if (unicode_symbol_len(four_byte_emojis[i]) != 4) {
            exit(EXIT_FAILURE);
        }
    }

    exit(EXIT_SUCCESS);
}
