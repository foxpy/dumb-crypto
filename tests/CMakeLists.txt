set(RUNTIME_OUTPUT_DIRECTORY tests)

function(dc_add_test target)
    add_executable(${target} ${target}.c)
    target_link_libraries(${target} PUBLIC qc Unicode Crypto String)
    add_test(NAME ${target} COMMAND ${target})
endfunction()

dc_add_test(unicode-len-test)
dc_add_test(caesar-cipher-test)
dc_add_test(string-test)
