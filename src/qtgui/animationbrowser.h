#ifndef ANIMATIONBROWSER_H
#define ANIMATIONBROWSER_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <QtCore/QVariant>

#include "ui_converterpixgui.h"
#include "filebrowser.h"

class AnimationBrowser : public FileBrowser
{
	Q_OBJECT

public:
	AnimationBrowser(QListWidget*, QListWidget*, QListWidget*, QLineEdit*, QListWidget*, QPushButton*, QPushButton*, QString);
	~AnimationBrowser();

	QListWidget *selectedAnimationsView;
	QPushButton *addAnimationBtn;
	QPushButton *removeAnimationBtn;

	QList<QListWidgetItem*> selectedItems();

	void enable();
	void disable();

private slots:
	void addAnimationClicked();
	void removeAnimationClicked();
};

#endif // ANIMATIONBROWSER_H

/* eof */