#include "ParticleEvaluationTool.h"
#include "ResultSettingsDialog.h"
#include "SettingsDialog.h"

#include <QFileDialog>

ParticleEvaluationTool::ParticleEvaluationTool(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    makeConnections();
	
    Controller = std::make_shared<Model::ParticleEvaluationController>();
	
    if (!Controller->getSettings()->areSettingsAvailable())
        openResultSettings();

    ui.DataTableView->setModel(Controller->getModel().get());
    ui.ResultsTable->setModel(Controller->getEvaluation());
}

void ParticleEvaluationTool::openDataFolderForProject()
{
    auto data = QFileDialog::getOpenFileNames(this,tr("Opens the Datafiles"), QDir::currentPath(), "Textfiles (*.txt);;Binaryfiles (*.bin)",nullptr);
	
    Controller->importData(data);
}

void ParticleEvaluationTool::makeConnections()
{
    connect(ui.ActionResultSettings, &QAction::triggered, this, &ParticleEvaluationTool::openResultSettings);
    connect(ui.ActionImportData, &QAction::triggered, this, &ParticleEvaluationTool::openDataFolderForProject);
    connect(ui.ActionSaveProject, &QAction::triggered, this, &ParticleEvaluationTool::saveProjectAsXML);
    connect(ui.ActionOpenProject, &QAction::triggered, this, &ParticleEvaluationTool::openProjectInXML);
    connect(ui.CalcualteResultsButton, &QPushButton::clicked,this,&ParticleEvaluationTool::evaluate);
    connect(ui.ActionProgrammSettings, &QAction::triggered, this, &ParticleEvaluationTool::openSettings);
}

void ParticleEvaluationTool::openResultSettings()
{
    SettignsDialog dialog(Controller->getSettings(), this);
    dialog.exec();
}

void ParticleEvaluationTool::saveProjectAsXML()
{
    QFileDialog::getSaveFileName();
}

void ParticleEvaluationTool::openProjectInXML()
{
    QFileDialog::getOpenFileName();
}

void ParticleEvaluationTool::evaluate() {
    Controller->evaluate();
}

void ParticleEvaluationTool::openSettings() {
    SettignsDialog dialog(Controller->getSettings(), this);
    dialog.openPageTwo();
    dialog.exec();
}
