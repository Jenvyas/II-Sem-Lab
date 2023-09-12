cmake_minimum_required(VERSION 3.0.0)
project(H12)

set(CMAKE_CXX_STANDARD 20)

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

add_library(Date Date/Date.cpp Date/DateFile.cpp Date/BufferDate.cpp)

add_executable(H12 main.cpp)
target_link_libraries(H12 Date)

add_executable(tests tests.cpp)
target_link_libraries(tests Date GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
