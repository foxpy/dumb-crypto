#include <stdio.h>
#include <string.h>
#include "qc.h"
#include "crypto.h"

int main(int argc, char* argv[]) {
    char* mode;
    char* key;
    qc_args* args = qc_args_new();
    qc_args_string_default(args, "mode", "encrypt", &mode, "encrypt | decrypt (default: encrypt)");
    qc_args_string(args, "key", &key, "key used for encryption");
    char* err;
    if (qc_args_parse(args, argc, argv, &err) == -1) {
        fprintf(stderr, "Failed to parse command line: %s\n", err);
        exit(EXIT_FAILURE);
    }
    if (qc_args_positionals_count(args) != 1) {
        fprintf(stderr, "Failed to parse command line: provide input message as last argument\n");
    } else {
        char* cipher_output;
        if (strcmp(mode, "encrypt") == 0) {
            cipher_output = playfair_cipher_encrypt(argv[qc_args_positionals_index(args)], 8, 4, key);
        } else {
            cipher_output = playfair_cipher_decrypt(argv[qc_args_positionals_index(args)], 8, 4,  key);
        }
        printf("%s\n", cipher_output);
        free(cipher_output);
    }
    free(mode);
    free(key);
    qc_args_free(args);
}
