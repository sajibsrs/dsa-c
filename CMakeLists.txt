cmake_minimum_required(VERSION 3.15)
project(dsa VERSION 0.1.0 LANGUAGES C)

file(GLOB_RECURSE SOURCE_FILES src/*c)

add_executable(
    dsa
    main.c
    ${SOURCE_FILES}
)

target_include_directories(
    dsa PRIVATE
    src
)

# Enable testing
# include(CTest)
# enable_testing()

# Tests


