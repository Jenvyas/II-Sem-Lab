cmake_minimum_required(VERSION 3.14)
project(G9)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(std_list_manual std_list_manual.cpp)

add_executable(singly_linked_list_manual singly_linked_list_manual.cpp)

add_executable(sll_unit_tests sll_unit_tests.cpp)

target_link_libraries(sll_unit_tests GTest::gtest_main)

add_executable(std_unit_tests std_unit_tests.cpp)

target_link_libraries(std_unit_tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(sll_unit_tests)
gtest_discover_tests(std_unit_tests)