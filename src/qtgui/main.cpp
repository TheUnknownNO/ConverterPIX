#include <prerequisites_gui.h>

#include "converterpixgui.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ConverterPIXGUI w;
	w.show();
	return a.exec();
}