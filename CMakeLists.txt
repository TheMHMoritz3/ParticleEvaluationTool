cmake_minimum_required(VERSION 3.17)

project(ParticleEvaluationTool CXX)

set(CMAKE_VERBOSE_MAKEFILE TRUE)
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake" "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_set_vs_runtime()
conan_set_libcxx()
conan_output_dirs_setup()

find_package(Qt6 COMPONENTS Core Network Sql Concurrent Xml Widgets REQUIRED CONFIG)
   
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(SOURCES src/main.cpp
	src/MainWindow.h
	src/MainWindow.cpp
	src/MainWindow.ui)

#qt_wrap_ui(${PROJECT_NAME} src/MainWindow.ui)

add_executable(${PROJECT_NAME} ${SOURCES})
# Must compile with "-fPIC" since Qt was built with -reduce-relocations.
#target_compile_options(${PROJECT_NAME} PRIVATE -fPIC)

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets)
