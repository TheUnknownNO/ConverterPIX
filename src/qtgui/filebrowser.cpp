#include <prerequisites_gui.h>

#include "filebrowser.h"

#include <fs/file.h>
#include <fs/sysfilesystem.h>
#include <fs/uberfilesystem.h>

Q_DECLARE_METATYPE(FileSystem*)
Q_DECLARE_METATYPE(FileSystem::Entry)

FileBrowser::FileBrowser() {}

FileBrowser::FileBrowser(QListWidget *bPaths, QListWidget *dirView, QListWidget *pGView, QLineEdit *pTView, QString fFormats)
{
	basePaths = bPaths;
	directoryView = dirView;
	pathGView = pGView;
	pathTView = pTView;
	fileFormats = fFormats.split(',');

	connect(directoryView, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(directoryViewDoubleClicked(QListWidgetItem*)));
	connect(pathGView, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(gPathClicked(QListWidgetItem*)));
	connect(pathTView, SIGNAL(editingFinished()), this, SLOT(directoryViewRefresh()));
}

FileBrowser::~FileBrowser(){}

bool FileBrowser::entryExists(QListWidget *widget, QListWidgetItem *item)
{
	for (int i = 0; i < widget->count(); ++i)
	{
		QListWidgetItem *cModel = widget->item(i);
		if (cModel->text() == item->text()) return true;
	}
	return false;
}

QString FileBrowser::cleanPath(String input)
{
	return cleanPath((QString)input.c_str());
}

QString FileBrowser::cleanPath(QString input)
{
	QString w = input;
	w = input.replace("//", "/");
	return w;
}

QString FileBrowser::getExtension(String input)
{
	QString w = (QString)input.c_str();
	w = w.section('.', w.split('.').length() - 1);
	return w;
}

QString FileBrowser::noTrailingSlash(String input)
{
	return noTrailingSlash((QString)input.c_str());
}

QString FileBrowser::noTrailingSlash(QString input)
{
	QString w = input;
	if (((w[w.length() - 1] == '/') || (w[w.length() - 1] == '\\'))) {
		w = w.remove(w.length() - 1, 1);
		w = noTrailingSlash(w);
	}

	return w;
}

QString FileBrowser::trailingSlash(String input)
{
	return trailingSlash((QString)input.c_str());
}

QString FileBrowser::trailingSlash(QString input)
{
	QString w = input;
	if (!((w[w.length() - 1] == '/') || (w[w.length() - 1] == '\\')))
		w = w + '/';
	return w;
}

void FileBrowser::directoryViewRefresh()
{
	directoryView->clear();
	pathGView->clear();

	QStringList relPaths = pathTView->text().split('/', QString::SkipEmptyParts);
	QString cPath = "/";

	QListWidgetItem *pathItem = new QListWidgetItem("/");
	pathItem->setData(256, cleanPath(cPath));
	pathGView->addItem(pathItem);

	for (QString p : relPaths)
	{
		QListWidgetItem *pathItem = new QListWidgetItem("> " + p);
		cPath = cPath + "/" + p;
		pathItem->setData(256, cleanPath(cPath));
		pathGView->addItem(pathItem);
	}

	pathGView->setCurrentRow((pathGView->count()-1));

	auto files = getUFS()->readDir(cleanPath(pathTView->text()).toStdString(), false, false);
	if (files) {
		for (const auto &f : *files)
		{
			QString exstention = getExtension(f.GetPath());
			if (!f.IsDirectory() && !fileFormats.contains(exstention)) continue;

			QListWidgetItem *modelItem = new QListWidgetItem((QString)((f.IsDirectory()) ? ("[" + (QString)f.GetPath().c_str() + "]") : f.GetPath().c_str()));
			if (entryExists(directoryView, modelItem)) continue;

			FileSystem *fileSystem = f.GetFileSystem();
			QString base = pathTView->text();
			base = trailingSlash(base);

			/*
			*	256 - FileSystem::Entry item
			*	257 - Relative Path
			*/
			modelItem->setToolTip(cleanPath(fileSystem->root() + base.toStdString() + f.GetPath()));
			modelItem->setData(256, QVariant::fromValue(f));
			modelItem->setData(257, cleanPath(base.toStdString() + f.GetPath()));

			directoryView->addItem(modelItem);
		}
	} 
}

void FileBrowser::directoryViewDoubleClicked(QListWidgetItem *item) {
	FileSystem::Entry entry = qvariant_cast<FileSystem::Entry>(item->data(256));

	if (entry.IsDirectory()) {
		QString path = pathTView->text();

		path = trailingSlash(path);

		pathTView->setText(cleanPath(path.toStdString() + entry.GetPath()));

		directoryViewRefresh();
	}
}

void FileBrowser::gPathClicked(QListWidgetItem *item)
{
	QString path = qvariant_cast<QString>(item->data(256));
	pathTView->setText(path);
	directoryViewRefresh();
}

void FileBrowser::refresh()
{
	directoryViewRefresh();
};

void FileBrowser::reset()
{
	directoryView->clear();
	pathGView->clear();
	pathTView->setText("/");
}

QList<QListWidgetItem*> FileBrowser::selectedItems()
{
	return directoryView->selectedItems();
};

void FileBrowser::enable()
{
	pathGView->setDisabled(false);
	directoryView->setDisabled(false);
	pathTView->setDisabled(false);
};

void FileBrowser::disable()
{
	pathGView->setDisabled(true);
	directoryView->setDisabled(true);
	pathTView->setDisabled(true);
};

/* eof */