#include <stddef.h>
#include <string.h>
#include "str.h"
#include "crypto.h"
#include "qc.h"
#include "unicode.h"

static char const** mat_shuffle(char const** mat, size_t x, size_t y) {
    char const** tmp = emalloc(x * y * sizeof(char const*));
    for (size_t i = 0; i < x; ++i) {
        for (size_t j = 0; j < y; ++j) {
            tmp[x*j + i] = mat[y*i + j];
        }
    }
    free(mat);
    return tmp;
}

char* encryption_table_encrypt(const char* input_str, size_t x, size_t y) {
    str* encrypted = str_new();
    char const** mat = emalloc(x * y * sizeof(char const*));
    size_t mat_fill = 0;
    size_t i = 0, end = strlen(input_str);
    while (i <= end) {
        size_t symbol_length = unicode_symbol_len(&input_str[i]);
        if (mat_fill == x * y) {
            mat_fill = 0;
            mat = mat_shuffle(mat, x, y);
            char buf[8];
            for (size_t j = 0; j < x * y; ++j) {
                strncpy(buf, mat[j], unicode_symbol_len(mat[j]));
                buf[unicode_symbol_len(mat[j])] = '\0';
                str_push_back(encrypted, buf);
            }
        }
        mat[mat_fill] = &input_str[i];
        ++mat_fill;
        i += symbol_length;
    }
    free(mat);
    return str_to_c(encrypted);
}

char* encryption_table_decrypt(const char* input_str, size_t x, size_t y) {
    return NULL;
}
