cmake_minimum_required(VERSION 3.15)
project(dsa VERSION 0.1.0 LANGUAGES C)
file(GLOB_RECURSE LIB_SRC src/*.c)
add_executable(dsa main.c ${LIB_SRC})
target_include_directories(dsa PRIVATE src)

# Enable testing
include(CTest)
enable_testing()

# Test executables
add_executable(slist_test tests/slist_test.c ${LIB_SRC})
target_include_directories(slist_test PRIVATE src src/dtst)

add_executable(dlist_test tests/dlist_test.c ${LIB_SRC})
target_include_directories(dlist_test PRIVATE src src/dtst)

add_executable(trie_test tests/trie_test.c ${LIB_SRC})
target_include_directories(trie_test PRIVATE src src/dtst)

# Registers tests
add_test(NAME slist_test COMMAND slist_test)
add_test(NAME dlist_test COMMAND dlist_test)
add_test(NAME trie_test COMMAND trie_test)
