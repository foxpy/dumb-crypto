#pragma once
#include <stddef.h>

char* encryption_table_encrypt(char const* input_str, size_t x, size_t y);
char* encryption_table_decrypt(char const* input_str, size_t x, size_t y);

char* encryption_table_single_permutation_encrypt(char const* input_str, char const* key, size_t y);
char* encryption_table_single_permutation_decrypt(char const* input_str, char const* key, size_t y);

char* caesar_cipher_encrypt(char const* input_str, size_t key);
char* caesar_cipher_decrypt(char const* input_str, size_t key);

char* affine_caesar_cipher_encrypt(char const* input_str, size_t a, size_t b);
char* affine_caesar_cipher_decrypt(char const* input_str, size_t a, size_t b);

char* caesar_keyword_cipher_encrypt(const char* input_str, size_t k, char const* key);
char* caesar_keyword_cipher_decrypt(const char* input_str, size_t k, char const* key);

char* magic_square_encrypt(char const* input_str, size_t len, size_t const square[static len]);
char* magic_square_decrypt(char const* input_str, size_t len, size_t const square[static len]);

char* trithemius_cipher_encrypt(char const* input_str, size_t x, size_t y, char const* key);
char* trithemius_cipher_decrypt(char const* input_str, size_t x, size_t y, char const* key);

char* playfair_cipher_encrypt(char const* input_str, size_t x, size_t y, char const* key);
char* playfair_cipher_decrypt(char const* input_str, size_t x, size_t y, char const* key);

char* vigenere_cipher_encrypt(char const* input_str, char const* key);
char* vigenere_cipher_decrypt(char const* input_str, char const* key);

char* wheatstone_two_square_encrypt(char const* input_str);
char* wheatstone_two_square_decrypt(char const* input_str);
