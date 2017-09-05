#include <prerequisites_gui.h>

#include "logger.h"

Logger *Logger::_instance = 0;

Logger::Logger(QListWidget *logList) {
	widget = logList;

	logList->clear();

	_instance = this;
}

Logger::~Logger() { }

Logger* Logger::instance()
{
	return _instance;
}

/*
TYPE
0 - INFO
1 - WARNING
2 - ERROR
*/

void Logger::write(String level, String file, String msg, int type = 0) {
	QListWidgetItem *modelItem = new QListWidgetItem((QString)(("[" + level + "] " + file + ": " + msg).c_str()));

	switch (type)
	{
	case 1:
		modelItem->setBackground(QBrush(QColor(255, 213, 79, 255)));
		break;
	case 2:
		modelItem->setBackground(QBrush(QColor(229, 115, 115, 255)));
		break;
	default:
		break;
	}

	widget->addItem(modelItem);
}

void(*info)(const String &level, const String &file, const String &msg)
= [](const String &level, const String &file, const String &msg) -> void
{
	Logger* logger = Logger::instance();
	logger->write(level, file, msg, 0);
};

void(*error)(const String &level, const String &file, const String &msg)
= [](const String &level, const String &file, const String &msg) -> void
{
	Logger* logger = Logger::instance();
	logger->write(level, file, msg, 2);
};

void(*warning)(const String &level, const String &file, const String &msg)
= [](const String &level, const String &file, const String &msg) -> void
{
	Logger* logger = Logger::instance();
	logger->write(level, file, msg, 1);
};

/* eof */