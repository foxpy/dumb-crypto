add_library(Crypto
    caesar.c
    affine_caesar.c
    encryption_table.c
    encryption_table_single_permutation.c
    magic_square.c
    caesar_keyword.c
    trithemius.c
    playfair.c
    vigenere.c
)
target_link_libraries(Crypto PUBLIC Unicode String)
target_include_directories(Crypto INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
