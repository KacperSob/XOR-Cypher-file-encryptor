add_library(encrypt_lib SHARED encrypt.c fileoperator.c)

target_include_directories(encrypt_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})