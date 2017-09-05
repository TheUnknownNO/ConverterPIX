#ifndef FILEBROWSER_H
#define FILEBROWSER_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <QtCore/QVariant>

#include "ui_converterpixgui.h"

class FileBrowser : public QMainWindow
{
	Q_OBJECT

public:
	FileBrowser();
	FileBrowser(QListWidget*, QListWidget*, QListWidget*, QLineEdit*, QString);
	~FileBrowser();

	QListWidget *basePaths;
	QListWidget *directoryView;
	QListWidget *pathGView;
	QLineEdit *pathTView;
	QStringList fileFormats;

	void refresh();
	void reset();
	virtual QList<QListWidgetItem*> selectedItems();
	virtual void enable();
	virtual void disable();
	bool entryExists(QListWidget*, QListWidgetItem*);

private:
	QString cleanPath(String);
	QString cleanPath(QString);

	QString getExtension(String);
	QString noTrailingSlash(String);
	QString noTrailingSlash(QString);
	QString trailingSlash(String);
	QString trailingSlash(QString);

private slots:
	void directoryViewDoubleClicked(QListWidgetItem*);
	void gPathClicked(QListWidgetItem*);
	void directoryViewRefresh();
};

#endif // FILEBROWSER_H

/* eof */