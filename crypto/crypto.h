#pragma once
#include <stddef.h>

char* encryption_table_encrypt(char const* input_str, size_t x, size_t y);
char* encryption_table_decrypt(char const* input_str, size_t x, size_t y);

char* caesar_cipher_encrypt(char const* input_str, size_t key);
char* caesar_cipher_decrypt(char const* input_str, size_t key);

char* affine_caesar_cipher_encrypt(char const* input_str, size_t a, size_t b);
char* affine_caesar_cipher_decrypt(char const* input_str, size_t a, size_t b);

char* magic_square_encrypt(char const* input_str, size_t len, size_t const square[static len]);
char* magic_square_decrypt(char const* input_str, size_t len, size_t const square[static len]);
