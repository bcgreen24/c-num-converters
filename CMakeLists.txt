cmake_minimum_required(VERSION 3.24.4)
project(num_converters C)
set(CMAKE_C_STANDARD 11)

add_library(num_converters lib_num_converters.c)
target_include_directories(num_converters PUBLIC /Users/bcgreen/include)

add_executable(num_converters_tests tests.c)
target_link_libraries(num_converters_tests /Users/bcgreen/CLionProjects/lib_num_converters/build/libnum_converters.a)
target_link_libraries(num_converters_tests /Users/bcgreen/lib/libcunit.a)
target_include_directories(num_converters_tests PUBLIC /Users/bcgreen/include)

enable_testing()

add_test(
    NAME num_converters_tests
    COMMAND $<TARGET_FILE:num_converters_tests>
)

