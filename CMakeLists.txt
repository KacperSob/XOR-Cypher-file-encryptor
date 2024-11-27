cmake_minimum_required(VERSION 3.28)
project(passwd_vault)
add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} encrypt_lib)

add_subdirectory(lib)