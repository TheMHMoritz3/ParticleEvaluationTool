project(ParticleEvaluationToolModel CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_set_vs_runtime()
conan_set_libcxx()
conan_output_dirs_setup()

find_package(Qt6 COMPONENTS Core Network Sql Concurrent Xml Widgets REQUIRED CONFIG)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(SOURCES DatasetParser.cpp
        EvaluationSettings.cpp
        ParticleDataSet.cpp
        ParticleEvaluationController.cpp
        PartilcleEvaluationModel.cpp

        DatasetParser.h
        EvaluationSettings.h
        MeasuringType.h
        ParticleDataSet.h
        ParticleEvaluationController.h
        PartilcleEvaluationModel.h
        partilcleevaluationmodel_global.h)

#qt_wrap_ui(${PROJECT_NAME} src/MainWindow.ui)

add_library(${PROJECT_NAME} ${SOURCES})
# Must compile with "-fPIC" since Qt was built with -reduce-relocations.
#target_compile_options(${PROJECT_NAME} PRIVATE -fPIC)

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets)