#include <assert.h>
#include <string.h>
#include "crypto.h"
#include "unicode.h"
#include "qc.h"
#include "str.h"

static char const* alphabet[] = {
        "А", "Б", "В", "Г", "Д", "Е", "Ж", "З", "И", "Й",
        "К", "Л", "М", "Н", "О", "П", "Р", "С", "Т", "У",
        "Ф", "Х", "Ц", "Ч", "Ш", "Щ", "Ъ", "Ы", "Ь", "Э",
        "Ю", "Я"
};
#define ALPHABET_LENGTH (sizeof(alphabet)/sizeof(alphabet[0]))

static ptrdiff_t table_lookup(size_t len, char const* table[static len], char const* symbol) {
    for (size_t i = 0; i < len; ++i) {
        if (table[i] != NULL && strncmp(table[i], symbol, unicode_symbol_len(symbol)) == 0) {
            return i;
        }
    }
    return -1;
}

static void playfair_lookup(char const** out1, char const** out2,
                            char const* in1, char const* in2,
                            size_t len, char const* table[static len]) {
    // TODO: proper implementation with table lookup
    *out1 = "А";
    *out2 = "Б";
}

static char const** create_table(size_t x, size_t y, char const* key) {
    char const** mat = emalloc(x * y * sizeof(char const*));
    for (size_t i = 0; i < x * y; ++i) {
        mat[i] = NULL;
    }
    size_t mat_fill = 0;
    {
        size_t i = 0, end = strlen(key);
        while (i < end) {
            size_t symbol_length = unicode_symbol_len(&key[i]);
            if (table_lookup(x * y, mat, &key[i]) == -1) {
                mat[mat_fill] = &key[i];
                ++mat_fill;
            }
            i += symbol_length;
        }
    }
    for (size_t i = 0; i < ALPHABET_LENGTH; ++i) {
        if (table_lookup(x * y, mat, alphabet[i]) == -1) {
            mat[mat_fill] = alphabet[i];
            ++mat_fill;
        }
    }
    assert(mat_fill == x * y);
    return mat;
}

static char const* next_unicode_character(char const* string) {
    if (string == NULL) {
        return NULL;
    }
    size_t len = strlen(string);
    size_t symbol_length = unicode_symbol_len(string);
    if (symbol_length <= len) {
        return &string[symbol_length];
    } else {
        return NULL;
    }
}

static char* bigraphic_substitution(char const* input) {
    str* bigraphed = str_new();
    char const* b1, * b2;
    do {
        b1 = input;
        b2 = next_unicode_character(b1);
        input = next_unicode_character(b2);
        if (b1 == NULL || b2 == NULL) {
            break;
        }
        if (strncmp(b2, "", unicode_symbol_len(b2)) == 0) {
            str_push_unicode_character_back(bigraphed, b1);
            str_push_unicode_character_back(bigraphed, "Ъ");
        } else if (strncmp(b1, b2, unicode_symbol_len(b1)) != 0) {
            str_push_unicode_character_back(bigraphed, b1);
            str_push_unicode_character_back(bigraphed, b2);
        } else {
            str_push_unicode_character_back(bigraphed, b1);
            str_push_unicode_character_back(bigraphed, "Ъ");
            input = b2;
        }
    } while(true);
    return str_to_c(bigraphed);
}

char* playfair_cipher_encrypt(char const* input_str, size_t x, size_t y, char const* key) {
    str* encrypted = str_new();
    char* bigraphed = bigraphic_substitution(input_str);
    char const** table = create_table(x, y, key);
    size_t i = 0, end = strlen(bigraphed);
    while (i <= end) {
        size_t symbol_length1 = unicode_symbol_len(&bigraphed[i]);
        char* plaintext_character1 = &bigraphed[i];
        i += symbol_length1;
        char* plaintext_character2 = &bigraphed[i];
        size_t symbol_length2 = unicode_symbol_len(&bigraphed[i]);
        i += symbol_length2;
        char const* ciphertext_character1;
        char const* ciphertext_character2;
        playfair_lookup(&ciphertext_character1, &ciphertext_character2,
                        plaintext_character1, plaintext_character2, x * y, table);
        str_push_unicode_character_back(encrypted, ciphertext_character1);
        str_push_unicode_character_back(encrypted, ciphertext_character2);
    }
    free(bigraphed);
    free(table);
    return str_to_c(encrypted);
}
