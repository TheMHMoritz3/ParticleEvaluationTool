#include "ResultSettingsDialog.h"

#include <QDebug>

ResultSettingsDialog::ResultSettingsDialog(std::shared_ptr<Model::EvaluationSettings> settings, QWidget *parent)
	: QDialog(parent),
	Settings(settings)
{
	ui.setupUi(this);
	makeConnections();
}

void ResultSettingsDialog::decorateGuiWithValues()
{
	qDebug() << ui.SettingsDataWidget->rowCount();
	ui.SettingsDataWidget->setItem(0, 0, new QTableWidgetItem(tr("%1").arg(Settings->ppm10LawViolationValueDay())));
	ui.SettingsDataWidget->setItem(1, 0, new QTableWidgetItem(tr("%1").arg(Settings->ppm10LawViolationValueYear())));
	ui.SettingsDataWidget->setItem(2, 0, new QTableWidgetItem(tr("%1").arg(Settings->ppm25LawViolationValueDay())));
	ui.SettingsDataWidget->setItem(3, 0, new QTableWidgetItem(tr("%1").arg(Settings->ppm25LawViolationValueYear())));
	ui.SettingsDataWidget->setItem(4, 0, new QTableWidgetItem(tr("%1").arg(Settings->numberViolatedDays())));
	ui.SettingsDataWidget->setItem(5, 0, new QTableWidgetItem(tr("%1").arg(Settings->ppm10WHOViolationValueDay())));
	ui.SettingsDataWidget->setItem(6, 0, new QTableWidgetItem(tr("%1").arg(Settings->ppm10WHOViolationValueYear())));
	ui.SettingsDataWidget->setItem(7, 0, new QTableWidgetItem(tr("%1").arg(Settings->ppm25WHOViolationValueDay())));
	ui.SettingsDataWidget->setItem(8, 0, new QTableWidgetItem(tr("%1").arg(Settings->ppm25WHOViolationValueYear())));
}

void ResultSettingsDialog::makeConnections()
{
	connect(ui.buttonBox, &QDialogButtonBox::accepted, this, &ResultSettingsDialog::onDialogAccepted);
	connect(ui.buttonBox, &QDialogButtonBox::rejected, this, &ResultSettingsDialog::onDialogRejected);
}

void ResultSettingsDialog::onDialogAccepted()
{
	Settings->setPpm10LawViolationPerDay(ui.SettingsDataWidget->item(0, 0)->text().toDouble());
	Settings->setPpm10LawViolationPerYear(ui.SettingsDataWidget->item(1, 0)->text().toDouble());
	Settings->setPpm25LawViolationPerDay(ui.SettingsDataWidget->item(2, 0)->text().toDouble());
	Settings->setPpm25LawViolationPerYear(ui.SettingsDataWidget->item(3, 0)->text().toDouble());
	Settings->setNumberOfViolatedDays(ui.SettingsDataWidget->item(4, 0)->text().toDouble());
	Settings->setPpm10WHOViolationPerDay(ui.SettingsDataWidget->item(5, 0)->text().toDouble());
	Settings->setPpm10WHOViolationPerYear(ui.SettingsDataWidget->item(6, 0)->text().toDouble());
	Settings->setPpm25WHOViolationPerDay(ui.SettingsDataWidget->item(7, 0)->text().toDouble());
	Settings->setPpm25WHOViolationPerYear(ui.SettingsDataWidget->item(8, 0)->text().toDouble());

	Settings->updateSettings();

	accept();
}

void ResultSettingsDialog::onDialogRejected()
{
	reject();
}
