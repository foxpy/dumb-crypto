#pragma once
#include <stddef.h>

char* caesar_cipher_encrypt(const char* input_str, size_t key);
char* caesar_cipher_decrypt(const char* input_str, size_t key);
