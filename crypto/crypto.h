#pragma once
#include <stddef.h>

char* encryption_table_encrypt(const char* input_str, size_t x, size_t y);
char* encryption_table_decrypt(const char* input_str, size_t x, size_t y);

char* caesar_cipher_encrypt(const char* input_str, size_t key);
char* caesar_cipher_decrypt(const char* input_str, size_t key);

char* affine_caesar_cipher_encrypt(const char* input_str, size_t a, size_t b);
char* affine_caesar_cipher_decrypt(const char* input_str, size_t a, size_t b);

char* magic_square_encrypt(const char* input_str, size_t len, size_t const square[static len]);
char* magic_square_decrypt(const char* input_str, size_t len, size_t const square[static len]);
