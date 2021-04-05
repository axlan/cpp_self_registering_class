cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(link_test VERSION 1.0)

set (CMAKE_CXX_STANDARD 17)

add_library(base_lib base_lib.cc)

add_library(foo_lib foo.cc)
target_link_libraries(foo_lib
  PRIVATE
    base_lib
)

add_library(test_lib test.cc)
target_link_libraries(test_lib
  PRIVATE
    base_lib
)

add_executable(link_test main.cc)
target_link_libraries(link_test
  PRIVATE
    foo_lib
    test_lib
)

# See https://www.bfilipek.com/2018/02/static-vars-static-lib.html
add_executable(link_test2 main.cc)
target_link_libraries(link_test2
  PRIVATE
    "-Wl,-force_load;foo_lib"
    test_lib
)


add_custom_target(print_symbols
    DEPENDS
        "${CMAKE_CURRENT_BINARY_DIR}/generated_file"
)

add_custom_command(
    OUTPUT
        "${CMAKE_CURRENT_BINARY_DIR}/generated_file"
    COMMAND
        ./test_script.sh > ${CMAKE_CURRENT_BINARY_DIR}/generated_file
    WORKING_DIRECTORY
        ${CMAKE_SOURCE_DIR}
    DEPENDS
        link_test
        link_test2
)
