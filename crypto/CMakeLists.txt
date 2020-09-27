add_library(Crypto
    caesar.c
)
target_link_libraries(Crypto PUBLIC Unicode String)
target_include_directories(Crypto INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
