#include "SettingsDialog.h"


SettignsDialog::SettignsDialog(std::shared_ptr<Model::EvaluationSettings> settings ,QWidget *parent) :
        QDialog(parent)
{
    EvalSettings = settings;
    ui.setupUi(this);
    ui.retranslateUi(this);

    generateLayout();
    makeConnections();
}

void SettignsDialog::makeConnections()
{
	connect(ui.buttonBox, &QDialogButtonBox::accepted, this, &SettignsDialog::onDialogAccepted);
    connect(ui.IPLineEdit, &QLineEdit::textChanged, this, &SettignsDialog::onLineEditChange);
    connect(ui.PingPushButton, &QPushButton::clicked, this, &SettignsDialog::pingServer);
//	connect(ui.buttonBox, &QDialogButtonBox::rejected, this, &ResultSettingsDialog::onDialogRejected);
}

void SettignsDialog::generateLayout() {
    ResultSettingsWidget = new ResultSettingsDialog(EvalSettings);
    QHBoxLayout* hBoxLayout = new QHBoxLayout();
    ui.ParticleSettingsPage->setLayout(hBoxLayout);
    hBoxLayout->addWidget(ResultSettingsWidget);
    ResultSettingsWidget->decorateGuiWithValues();
}

void SettignsDialog::onDialogAccepted() {
    ResultSettingsWidget->onDialogAccepted();
    accept();
}

void SettignsDialog::openPageTwo() {
    ui.toolBox->setCurrentIndex(1);
}

void SettignsDialog::onLineEditChange() {
    if(!ui.IPLineEdit->text().isEmpty())
        ui.buttonBox->buttons().at(0)->setEnabled(false);
}

void SettignsDialog::pingServer() {
    ui.buttonBox->buttons().at(0)->setEnabled(true);

}
