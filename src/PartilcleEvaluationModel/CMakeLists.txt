
set(SOURCES DatasetParser.cpp
        EvaluationSettings.cpp
        ParticleDataSet.cpp
        ParticleEvaluationController.cpp
        PartilcleEvaluationModel.cpp
        StringUtitlities.cpp

        DatasetParser.h
        EvaluationSettings.h
        MeasuringType.h
        ParticleDataSet.h
        ParticleEvaluationController.h
        PartilcleEvaluationModel.h
        StringUtitlities.h
        partilcleevaluationmodel_global.h ParticleEvaluator.cpp ParticleEvaluator.h EvaluationDataPoint.cpp EvaluationDataPoint.h)

#qt_wrap_ui(${PROJECT_NAME} src/MainWindow.ui)

add_library(${PROJECT_NAME} ${SOURCES})
# Must compile with "-fPIC" since Qt was built with -reduce-relocations.
#target_compile_options(${PROJECT_NAME} PRIVATE -fPIC)

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets)