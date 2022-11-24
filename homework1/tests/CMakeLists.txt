cmake_minimum_required(VERSION 3.15)

project(quadratic_solver)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
)

FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 11)
set(TEST_NAME tests_${PROJECT_NAME})

include_directories(
    ${tests_INCLUDE_DIRS}
    ${CMAKE_CURRENT_LIST_DIR}/../src/
)

set(tests_LIBS
    ${PROJECT_NAME}
    GTest::gtest
    GTest::gtest_main
)

file(GLOB_RECURSE tests_SOURCES RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.cpp)
file(GLOB_RECURSE tests_HEADERS RELATIVE ${CMAKE_CURRENT_LIST_DIR} *.h)

list(APPEND tests_SOURCES ${tests_SOURCES})
list(APPEND tests_HEADERS ${tests_HEADERS})

add_executable(${TEST_NAME} ${tests_SOURCES} ${tests_HEADERS})
target_link_libraries(${TEST_NAME} PUBLIC ${tests_LIBS})

enable_testing()
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})