#include "ParticleEvaluationTool.h"
#include "ResultSettingsDialog.h"

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
}

void ParticleEvaluationTool::openDataFolderForProject()
{
    auto data = QFileDialog::getOpenFileNames(this,tr("Opens the Datafiles"), QDir::currentPath(), "Textfiles *.txt;;Binaryfiles *.bin", nullptr);
	
    Controller->importData(data);
}

void ParticleEvaluationTool::makeConnections()
{
    connect(ui.ActionResultSettings, &QAction::triggered, this, &ParticleEvaluationTool::openResultSettings);
    connect(ui.ActionImportData, &QAction::triggered, this, &ParticleEvaluationTool::openDataFolderForProject);
    connect(ui.ActionSaveProject, &QAction::triggered, this, &ParticleEvaluationTool::saveProjectAsXML);
    connect(ui.ActionOpenProject, &QAction::triggered, this, &ParticleEvaluationTool::openProjectInXML);
}

void ParticleEvaluationTool::openResultSettings()
{
    auto dialog = std::make_unique<ResultSettingsDialog>(Controller->getSettings(), this);
    dialog->decorateGuiWithValues();
    dialog->exec();
}

void ParticleEvaluationTool::saveProjectAsXML()
{
    QFileDialog::getSaveFileName();
}

void ParticleEvaluationTool::openProjectInXML()
{
    QFileDialog::getOpenFileName();
}
