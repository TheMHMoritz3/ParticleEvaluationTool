project(ParticleEvaluationTool CXX)

set(SOURCES main.cpp
        ParticleEvaluationTool.cpp
        ResultSettingsDialog.cpp
        
        ParticleEvaluationTool.h
        ResultSettingsDialog.h

        SettingsDialog.h
        SettingsDialog.cpp

        ParticleEvaluationTool.ui
        ResultSettingsDialog.ui
        SettingsDialog.ui

        ParticleEvaluationTool.qrc)

#qt_wrap_ui(${PROJECT_NAME} src/MainWindow.ui)

add_executable(${PROJECT_NAME} ${SOURCES})
# Must compile with "-fPIC" since Qt was built with -reduce-relocations.
#target_compile_options(${PROJECT_NAME} PRIVATE -fPIC)

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets ParticleEvaluationToolModel)