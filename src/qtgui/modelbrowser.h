#ifndef MODELBROWSER_H
#define MODELBROWSER_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <QtCore/QVariant>

#include "ui_converterpixgui.h"
#include "filebrowser.h"
#include "animationbrowser.h"

class ModelBrowser : public FileBrowser
{
	Q_OBJECT

public:
	ModelBrowser(QListWidget*, QListWidget*, QListWidget*, QLineEdit*, FileBrowser*, QString);
	~ModelBrowser();

private:
	FileBrowser *animationBrowser;

private slots:
	void modelSelectionChanged();
};

#endif // MODELBROWSER_H

/* eof */