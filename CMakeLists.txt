cmake_minimum_required(VERSION 3.24.4)
project(lib_num_converters C)
set(CMAKE_C_STANDARD 11)

add_library(num_converters lib_num_converters.c)
target_include_directories(num_converters PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(num_converters_tests tests.c)
target_include_directories(num_converters_tests PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(num_converters_tests PUBLIC num_converters m)


enable_testing()

add_test(
    NAME num_converters_tests
    COMMAND $<TARGET_FILE:num_converters_tests>
)

