#ifndef CONVERTERPIXGUI_H
#define CONVERTERPIXGUI_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <QtCore/QVariant>

#include "logger.h"
#include "filebrowser.h"
#include "animationbrowser.h"
#include "modelbrowser.h"

#include "ui_converterpixgui.h"

class ConverterPIXGUI : public QMainWindow
{
	Q_OBJECT

public:
	ConverterPIXGUI(QWidget *parent = 0);
	~ConverterPIXGUI();

private:
	Ui::MainWindow ui;
	Logger *logger;
	FileBrowser *modelBrowser;
	FileBrowser *animationBrowser;
	FileBrowser *textureBrowser;
	void ufsPriorityRefresh();
	std::unique_ptr<ResourceLibrary> resourceLibrary;
	QString defaultExportpath(QString);

	void convertModel();
	void convertTexture();

private slots:
	void ufsListClicked(QListWidgetItem*);
	void ufsListCurrentRowChanged(int);
	void ufsAddClicked();
	void ufsUnmountClicked();
	void ufsUpClicked();
	void ufsDownClicked();
	void exportPathBtnClicked();
	void exportPathEdited();
	void convertClicked();
	void convertAllModels();
};

#endif // CONVERTERPIXGUI_H
