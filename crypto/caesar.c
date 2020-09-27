#include "crypto.h"
#include "unicode.h"
#include <stddef.h>
#include <string.h>

static char const* shift_table[] = {
        "А", "Б", "В", "Г", "Д", "Е", "Ё", "Ж", "З", "И",
        "Й", "К", "Л", "М", "Н", "О", "П", "Р", "С", "Т",
        "У", "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь",
        "Э", "Ю", "Я",
};

static ptrdiff_t ord(size_t len, const char symbol[static len]) {
    for (size_t i = 0; i < sizeof(shift_table)/sizeof(shift_table[0]); ++i) {
        if (strncmp(shift_table[i], symbol, len) == 0) {
            return i;
        }
    }
    return -1;
}

static char const* chr(size_t index) {
    return shift_table[index];
}

static char* caesar_cipher_impl(const char* input_str, ptrdiff_t shift) {
    size_t i = 0, end = strlen(input_str);
    while (i <= end) {
        size_t symbol_length = unicode_symbol_len(&input_str[i]);
        ptrdiff_t index = ord(symbol_length, &input_str[i]);
        if (index == -1) {
            i += symbol_length;
            continue;
        } else {
            char const* encrypted = chr(index + shift);
            (void) encrypted; // TODO: do something with encrypted symbol
        }
    }
    return NULL;
}
