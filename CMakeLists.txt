cmake_minimum_required(VERSION 3.16)

project(bot_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Sources for project
set(SOURCES
    # Do not add Sources/bot.cpp due to gTest
    Sources/bot_lib.cpp
    # Add more sources ...
)

# Sources for google test
set(TEST_SOURCES
    SourcesTest/bot_test.cpp
    # Add more sources for test
)

cmake_policy(SET CMP0135 NEW)
include(FetchContent)

# Packages
find_package(PkgConfig REQUIRED)
FetchContent_Declare(CPR GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 1.11.0)
FetchContent_MakeAvailable(CPR)
pkg_check_modules(WEBSOCKETPP REQUIRED websocketpp)

# Bot lib (core logic, no main)
add_library(bot_lib STATIC ${SOURCES})
target_include_directories(bot_lib PUBLIC Sources Sources/ThirdParty/json/include ${WEBSOCKETPP_INCLUDE_DIRS})
target_link_libraries(bot_lib PRIVATE ${CPR_LIBRARIES})
target_compile_options(bot_lib PRIVATE ${CPR_CFLAGS_OTHER})

# Exe
add_executable(bot Sources/bot.cpp)    # main() calls lib
target_link_libraries(bot PRIVATE bot_lib)

# Tests
find_package(GTest REQUIRED)
enable_testing()

set(TEST_SOURCES SourcesTest/bot_test.cpp)
add_executable(tests ${BOT_SOURCES} ${TEST_SOURCES})  # lib sources + tests
target_link_libraries(tests PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
gtest_discover_tests(tests)
include(GoogleTest)