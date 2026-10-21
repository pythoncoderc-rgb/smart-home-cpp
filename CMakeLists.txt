cmake_minimum_required(VERSION 3.20)
project(smart_home_cpp VERSION 2.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(smart_home_lib src/smart_home.cpp)
target_include_directories(smart_home_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(smart_home src/main.cpp)
target_link_libraries(smart_home PRIVATE smart_home_lib)

include(CTest)
if(BUILD_TESTING)
    add_executable(smart_home_tests tests/test_smart_home.cpp)
    target_link_libraries(smart_home_tests PRIVATE smart_home_lib)
    add_test(NAME smart_home_tests COMMAND smart_home_tests)
endif()
