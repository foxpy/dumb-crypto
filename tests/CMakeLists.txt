set(RUNTIME_OUTPUT_DIRECTORY tests)

add_executable(unicode-len-test unicode-len-test.c)
target_link_libraries(unicode-len-test PUBLIC Unicode)
add_test(NAME unicode-len-test COMMAND unicode-len-test)
