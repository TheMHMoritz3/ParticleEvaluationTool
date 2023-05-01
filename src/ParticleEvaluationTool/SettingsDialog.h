#pragma once

#include "ResultSettingsDialog.h"
#include <QDialog>
#include "ui_SettingsDialog.h"

class SettignsDialog : public QDialog
{
public:
    SettignsDialog()=delete;
    SettignsDialog(std::shared_ptr<Model::EvaluationSettings> settings, QWidget* parent = NULL);
    ~SettignsDialog() = default;

    void openPageTwo();

private:
    void makeConnections();
    void generateLayout();

    std::shared_ptr<Model::EvaluationSettings> EvalSettings;
    ResultSettingsDialog *ResultSettingsWidget;
    Ui::Dialog ui;

private slots:
    void onDialogAccepted();
    void onLineEditChange();
    void pingServer();
};