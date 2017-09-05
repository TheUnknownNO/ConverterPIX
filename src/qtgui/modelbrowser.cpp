#include <prerequisites_gui.h>

#include "modelbrowser.h"

#include "animationbrowser.h"

#include <fs/file.h>
#include <fs/sysfilesystem.h>
#include <fs/uberfilesystem.h>

Q_DECLARE_METATYPE(FileSystem*)
Q_DECLARE_METATYPE(FileSystem::Entry)

ModelBrowser::ModelBrowser(QListWidget *bPaths, QListWidget *dirView, QListWidget *pGView, QLineEdit *pTView, FileBrowser *aBrowser, QString fFormats)
{
	basePaths = bPaths;
	directoryView = dirView;
	pathGView = pGView;
	pathTView = pTView;
	fileFormats = fFormats.split(',');
	animationBrowser = aBrowser;

	connect(directoryView, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(directoryViewDoubleClicked(QListWidgetItem*)));
	connect(directoryView, SIGNAL(itemSelectionChanged()), this, SLOT(modelSelectionChanged()));
	connect(pathGView, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(gPathClicked(QListWidgetItem*)));
	connect(pathTView, SIGNAL(editingFinished()), this, SLOT(directoryViewRefresh()));

}

ModelBrowser::~ModelBrowser() {}

void ModelBrowser::modelSelectionChanged() {
	if (directoryView->selectedItems().count() > 1)
		animationBrowser->disable();
	else
		animationBrowser->enable();
}

/* eof */