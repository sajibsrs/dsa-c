cmake_minimum_required(VERSION 3.15)
project(dsa VERSION 0.1.0 LANGUAGES C)
file(GLOB_RECURSE LIB_SRC src/*.c)
add_executable(dsa main.c ${LIB_SRC})
target_include_directories(dsa PRIVATE src)

# Enable testing
include(CTest)
enable_testing()

# Test executables
add_executable(search_test tests/search_test.c ${LIB_SRC})
target_include_directories(search_test PRIVATE src)

add_executable(list_test tests/list_test.c ${LIB_SRC})
target_include_directories(list_test PRIVATE src)

add_executable(stack_test tests/stack_test.c ${LIB_SRC})
target_include_directories(stack_test PRIVATE src)

add_executable(tree_test tests/tree_test.c ${LIB_SRC})
target_include_directories(tree_test PRIVATE src)

add_executable(trie_test tests/trie_test.c ${LIB_SRC})
target_include_directories(trie_test PRIVATE src)

add_executable(agr_test tests/agr_test.c ${LIB_SRC})
target_include_directories(agr_test PRIVATE src)

add_executable(sgr_test tests/sgr_test.c ${LIB_SRC})
target_include_directories(sgr_test PRIVATE src)

add_executable(queue_test tests/queue_test.c ${LIB_SRC})
target_include_directories(queue_test PRIVATE src)

add_executable(dijkstra_test tests/dijkstra_test.c ${LIB_SRC})
target_include_directories(dijkstra_test PRIVATE src)

# Registers tests
add_test(NAME search_test COMMAND search_test)
add_test(NAME list_test COMMAND list_test)
add_test(NAME stack_test COMMAND stack_test)
add_test(NAME tree_test COMMAND tree_test)
add_test(NAME trie_test COMMAND trie_test)
add_test(NAME agr_test COMMAND agr_test)
add_test(NAME sgr_test COMMAND sgr_test)
add_test(NAME queue_test COMMAND queue_test)
add_test(NAME dijkstra_test COMMAND dijkstra_test)
