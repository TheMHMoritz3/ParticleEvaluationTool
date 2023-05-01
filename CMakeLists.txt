cmake_minimum_required(VERSION 3.23)

set(CMAKE_VERBOSE_MAKEFILE TRUE)
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake" "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

project(ParticleEvaluationToolModel CXX C)

find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
conan_set_vs_runtime()
conan_set_libcxx()
conan_output_dirs_setup()

list(APPEND CMAKE_PREFIX_PATH "C:/Qt/6.3.2/msvc2019_64")

find_package(Qt6 COMPONENTS Core Network Sql Concurrent Xml Widgets REQUIRED CONFIG)

#find_package(Qt6 COMPONENTS Core Network Sql Concurrent Xml Widgets REQUIRED CONFIG)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_subdirectory(src)
