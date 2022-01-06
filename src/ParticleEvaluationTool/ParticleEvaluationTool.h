#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ParticleEvaluationTool.h"

#include "../PartilcleEvaluationModel/EvaluationSettings.h"
#include "../PartilcleEvaluationModel/ParticleEvaluationController.h"
#include <memory>


class ParticleEvaluationTool : public QMainWindow
{
    Q_OBJECT

public:
    ParticleEvaluationTool(QWidget *parent = Q_NULLPTR);

    ~ParticleEvaluationTool() = default;
    
private:
    Ui::ParticleEvaluationToolClass ui;
    
    std::shared_ptr<Model::ParticleEvaluationController> Controller;
    void makeConnections();

	

private slots:
    void openDataFolderForProject();
    void openResultSettings();
    void saveProjectAsXML();
    void openProjectInXML();

};
