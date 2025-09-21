cmake_minimum_required(VERSION 3.15)
project(dsa VERSION 0.1.0 LANGUAGES C)

file(GLOB_RECURSE LIB_SRC src/*.c)

add_executable(dsa main.c ${LIB_SRC})

target_include_directories(dsa PRIVATE src)

# Enable testing
include(CTest)
enable_testing()

# Test executables
add_executable(test_slist tests/slist_test.c ${LIB_SRC})
target_include_directories(test_slist PRIVATE src src/dtst)

add_executable(test_dlist tests/dlist_test.c ${LIB_SRC})
target_include_directories(test_dlist PRIVATE src src/dtst)

# Registers tests
add_test(NAME TestSList COMMAND test_slist)
add_test(NAME TestDList COMMAND test_dlist)
