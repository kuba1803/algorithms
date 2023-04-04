cmake_minimum_required(VERSION 3.14)
project(test)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(sort_test sort_test.cc)
target_link_libraries(
        sort_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(sort_test)
