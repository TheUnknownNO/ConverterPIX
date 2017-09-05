#ifndef LOGGER_H
#define LOGGER_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <QtCore/QVariant>

#include "ui_converterpixgui.h"
class Logger
{

public:
	Logger(QListWidget*);
	~Logger();

	static Logger* instance();
	void write(String, String, String, int);

private:
	static Logger* _instance;
	QListWidget *widget;

};

#endif // LOGGER_H

/* eof */