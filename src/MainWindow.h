#pragma once

#include <qmainwindow.h>

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	MainWindow();
	virtual ~MainWindow() = default;

private:
	Ui::MainWindow ui;
};

