#include <prerequisites_gui.h>

#include "animationbrowser.h"

#include <fs/file.h>
#include <fs/sysfilesystem.h>
#include <fs/uberfilesystem.h>

Q_DECLARE_METATYPE(FileSystem*)
Q_DECLARE_METATYPE(FileSystem::Entry)

AnimationBrowser::AnimationBrowser(QListWidget *bPaths, QListWidget *dirView, QListWidget *pGView, QLineEdit *pTView, QListWidget *selectedAView, QPushButton *addABtn, QPushButton *removeABtn, QString fFormats)
{
	basePaths = bPaths;
	directoryView = dirView;
	pathGView = pGView;
	pathTView = pTView;
	selectedAnimationsView = selectedAView;
	addAnimationBtn = addABtn;
	removeAnimationBtn = removeABtn;
	fileFormats = fFormats.split(',');

	connect(directoryView, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(directoryViewDoubleClicked(QListWidgetItem*)));
	connect(pathGView, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(gPathClicked(QListWidgetItem*)));
	connect(pathTView, SIGNAL(editingFinished()), this, SLOT(directoryViewRefresh()));

	connect(addAnimationBtn, SIGNAL(clicked()), this, SLOT(addAnimationClicked()));
	connect(removeAnimationBtn, SIGNAL(clicked()), this, SLOT(removeAnimationClicked()));
}

AnimationBrowser::~AnimationBrowser() {}

QList<QListWidgetItem*> AnimationBrowser::selectedItems()
{
	return selectedAnimationsView->selectedItems();
};

void AnimationBrowser::enable()
{
	selectedAnimationsView->setDisabled(false);
	addAnimationBtn->setDisabled(false);
	removeAnimationBtn->setDisabled(false);
};

void AnimationBrowser::disable()
{
	selectedAnimationsView->setDisabled(true);
	addAnimationBtn->setDisabled(true);
	removeAnimationBtn->setDisabled(true);
};

void AnimationBrowser::addAnimationClicked()
{
	QList<QListWidgetItem*> selectedItems = directoryView->selectedItems();

	for (QListWidgetItem *item : selectedItems)
	{
		FileSystem::Entry entry = qvariant_cast<FileSystem::Entry>(item->data(256));
		if (!entry.IsDirectory()) selectedAnimationsView->addItem(item->clone());
	}

}

void AnimationBrowser::removeAnimationClicked()
{
	QList<QListWidgetItem*> selectedItems = selectedAnimationsView->selectedItems();

	for (QListWidgetItem *item : selectedItems)
		selectedAnimationsView->takeItem(selectedAnimationsView->row(item));
	
}

/* eof */