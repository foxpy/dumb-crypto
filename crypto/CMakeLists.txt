add_library(Crypto lib.c)
target_include_directories(Crypto INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
