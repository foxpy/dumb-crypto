#include <stddef.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "crypto.h"
#include "qc.h"
#include "str.h"
#include "unicode.h"

static bool is_magic_square(size_t len, size_t const square[static len]) {
    size_t a = sqrt(len);
    if (a * a != len) {
        return false;
    } else {
        size_t sum = 0, target_sum = 0;
        for (size_t i = 0; i < a; ++i) {
            target_sum += square[i];
        }
        for (size_t i = 0; i < a; ++i) {
            sum = 0;
            for (size_t j = 0; j < a; ++j) {
                sum += square[i*a + j];
            }
            if (sum != target_sum) {
                return false;
            }
        }
        for (size_t i = 0; i < a; ++i) {
            sum = 0;
            for (size_t j = 0; j < a; ++j) {
                sum += square[j*a + i];
            }
            if (sum != target_sum) {
                return false;
            }
        }
        sum = 0;
        for (size_t i = 0; i < a; ++i) {
            sum += square[i*a + i];
        }
        if (sum != target_sum) {
            return false;
        }
        return true;
    }
}

static size_t to_index(size_t len, size_t const square[static len], size_t num) {
    for (size_t i = 0; i < len; ++i) {
        if (square[i] == num) {
            return i;
        }
    }
    UNREACHABLE_CODE();
}

char* magic_square_encrypt(const char* input_str, size_t len, size_t const square[static len]) {
    assert(input_str != NULL);
    assert(is_magic_square(len, square));
    str* encrypted = str_new();
    char const** mat = emalloc(len * sizeof(char const*));
    size_t i = 0, j = 1, end = strlen(input_str);
    while (i <= end) {
        size_t symbol_length = unicode_symbol_len(&input_str[i]);
        if (j > len) {
            j = 1;
            for (size_t k = 0; k < len; ++k) {
                char buf[8];
                strncpy(buf, mat[k], unicode_symbol_len(mat[k]));
                buf[unicode_symbol_len(mat[k])] = '\0';
                str_push_back(encrypted, buf);
            }
        }
        mat[to_index(len, square, j)] = &input_str[i];
        ++j;
        i += symbol_length;
    }
    free(mat);
    return str_to_c(encrypted);
}
