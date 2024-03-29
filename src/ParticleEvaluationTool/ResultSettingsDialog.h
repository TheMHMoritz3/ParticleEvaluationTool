#pragma once

#include <QWidget>
#include "ui_ResultSettingsDialog.h"
#include "../PartilcleEvaluationModel/EvaluationSettings.h"
#include <memory>


class ResultSettingsDialog : public QWidget
{
	Q_OBJECT

public:
	ResultSettingsDialog(std::shared_ptr<Model::EvaluationSettings> settings, QWidget *parent = Q_NULLPTR);
	~ResultSettingsDialog() = default;

	void decorateGuiWithValues();

private:
	void makeConnections();
	std::shared_ptr<Model::EvaluationSettings> Settings;
	Ui::ResultSettingsDialog ui;

public slots:
	void onDialogAccepted();
};
