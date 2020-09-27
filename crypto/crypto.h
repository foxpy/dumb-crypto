#pragma once
#include <stddef.h>

char* caesar_cipher_encrypt(const char* input_str, size_t key);
char* caesar_cipher_decrypt(const char* input_str, size_t key);

char* affine_caesar_cipher_encrypt(const char* input_str, size_t a, size_t b);
char* affine_caesar_cipher_decrypt(const char* input_str, size_t a, size_t b);
