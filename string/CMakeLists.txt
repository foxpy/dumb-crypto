add_library(String
    str_new.c
    str_to_c.c
    str_push_back.c
)
target_link_libraries(String PUBLIC qc)
target_include_directories(String INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
