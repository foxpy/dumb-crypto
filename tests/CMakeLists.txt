set(RUNTIME_OUTPUT_DIRECTORY tests)

function(dc_add_test target)
    add_executable(${target} ${target}.c)
    target_link_libraries(${target} PUBLIC qc)
    add_test(NAME ${target} COMMAND ${target})
endfunction()

dc_add_test(unicode-len-test)
target_link_libraries(unicode-len-test PUBLIC Unicode)
