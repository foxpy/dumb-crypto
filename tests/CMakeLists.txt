set(RUNTIME_OUTPUT_DIRECTORY tests)

add_executable(works works.c)
add_test(NAME works COMMAND works)
