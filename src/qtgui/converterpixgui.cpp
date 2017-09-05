#include <prerequisites_gui.h>

#include "converterpixgui.h"

#include <resource_lib.h>
#include <model/model.h>
#include <model/animation.h>
#include <texture/texture_object.h>
#include <texture/texture.h>

#include <fs/file.h>
#include <fs/sysfilesystem.h>
#include <fs/uberfilesystem.h>

Q_DECLARE_METATYPE(FileSystem*)
Q_DECLARE_METATYPE(FileSystem::Entry)

ConverterPIXGUI::ConverterPIXGUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	resourceLibrary = std::make_unique<ResourceLibrary>();

	connect(ui.ufs_paths, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(ufsListClicked(QListWidgetItem*)));
	connect(ui.ufs_paths, SIGNAL(currentRowChanged(int)), this, SLOT(ufsListCurrentRowChanged(int)));
	connect(ui.ufs_add_btn, SIGNAL(clicked()), this, SLOT(ufsAddClicked()));
	connect(ui.ufs_unmount_btn, SIGNAL(clicked()), this, SLOT(ufsUnmountClicked()));
	connect(ui.ufs_up_btn, SIGNAL(clicked()), this, SLOT(ufsUpClicked()));
	connect(ui.ufs_down_btn, SIGNAL(clicked()), this, SLOT(ufsDownClicked()));
	connect(ui.export_path_btn, SIGNAL(clicked()), this, SLOT(exportPathBtnClicked()));
	connect(ui.export_path, SIGNAL(editingFinished()), this, SLOT(exportPathEdited()));
	connect(ui.convert_btn, SIGNAL(clicked()), this, SLOT(convertClicked()));
	connect(ui.convert_models_btn, SIGNAL(Clicked()), this, SLOT(convertAllModels()));

	logger = new Logger(ui.model_paths_2);

	animationBrowser = new AnimationBrowser(ui.ufs_paths, ui.animation_paths, ui.animation_g_path, ui.animation_relative_path, ui.animation_selected, ui.animation_add_btn, ui.animation_remove_btn, "pma");
	modelBrowser = new ModelBrowser(ui.ufs_paths, ui.model_paths, ui.listWidget, ui.model_relative_path,animationBrowser, "pmg");
	textureBrowser = new FileBrowser(ui.ufs_paths, ui.texture_paths, ui.texture_relative_grapich, ui.texture_relative_path, "tobj");
}

ConverterPIXGUI::~ConverterPIXGUI()
{

}

QString ConverterPIXGUI::defaultExportpath(QString input) {

	QString w = input;
	if (((w[w.length() - 1] == '/') || (w[w.length() - 1] == '\\'))) //Remove trailing slash
		w = w.remove(w.length() - 1, 1);
	w = w.replace(".scs", "");

	return w + "_exp";
}

/* Base Paths UI */

void ConverterPIXGUI::ufsListClicked(QListWidgetItem *item) {
	ui.ufs_unmount_btn->setEnabled(true);
}

void ConverterPIXGUI::ufsPriorityRefresh() {
	for (int i = 0; i < ui.ufs_paths->count(); ++i) {
		QListWidgetItem *listItem = ui.ufs_paths->item(i);
		FileSystem *filesystem = qvariant_cast<FileSystem*>(listItem->data(256));
		ufsUnmount(filesystem);
		filesystem = ufsMount(listItem->text().toStdString(), true, i+1);
		listItem->setData(256, QVariant::fromValue(filesystem));
	}

	modelBrowser->refresh();
	animationBrowser->refresh();
	textureBrowser->refresh();

	if (ui.ufs_paths->count() == 0) {
		modelBrowser->reset();
		animationBrowser->reset();
		textureBrowser->reset();
	}
}

void ConverterPIXGUI::ufsListCurrentRowChanged(int row) {
	int end = ui.ufs_paths->count() - 1;
	ui.ufs_up_btn->setEnabled((row > 0) ? true : false);
	ui.ufs_down_btn->setEnabled((row < end) ? true : false);
}

void ConverterPIXGUI::ufsAddClicked() {
	QString basePathDir;

	QMessageBox msgBox;
	msgBox.setWindowTitle("ConverterPIX - Add base");
	msgBox.setText("Please choose the filesystem type you want to add");
	QAbstractButton* folderButton = msgBox.addButton("Folder", QMessageBox::NoRole);
	QAbstractButton* hashFsButton = msgBox.addButton("HashFS", QMessageBox::NoRole);
	msgBox.addButton("Cancel", QMessageBox::NoRole);
	msgBox.exec();

	if (msgBox.clickedButton() == folderButton) {
		basePathDir = QFileDialog::getExistingDirectory(this, tr("Select base path"), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	}else if (msgBox.clickedButton() == hashFsButton) {
		basePathDir = QFileDialog::getOpenFileName(this, tr("Select HashFS file"), "", tr("SCS File (*.scs)"));
	}else return;
	
	if (basePathDir.length() == 0)
		return;

	FileSystem *fs = ufsMount(basePathDir.toStdString(), true, 0);

	if (ui.ufs_paths->count() == 0)
		ui.export_path->setText(defaultExportpath(basePathDir));


	QListWidgetItem *listItem = new QListWidgetItem(basePathDir);

	listItem->setData(256, QVariant::fromValue(fs));
	ui.ufs_paths->addItem(listItem);

	ufsPriorityRefresh();
	
	
}

void ConverterPIXGUI::ufsUnmountClicked() {
	QListWidgetItem *listItem = ui.ufs_paths->item(ui.ufs_paths->currentRow());
	FileSystem *filesystem = qvariant_cast<FileSystem*>(listItem->data(256));
	ufsUnmount(filesystem);

	ui.ufs_paths->takeItem(ui.ufs_paths->currentRow());
	if (ui.ufs_paths->count() == 0) {
		ui.ufs_unmount_btn->setEnabled(false);
		ui.ufs_up_btn->setEnabled(false);
		ui.ufs_down_btn->setEnabled(false);
	}

	ufsPriorityRefresh();
}

void ConverterPIXGUI::ufsUpClicked() {
	
	int currIndex = ui.ufs_paths->currentRow();
	int prevIndex = currIndex - 1;

	QListWidgetItem *current = ui.ufs_paths->takeItem(currIndex);
	ui.ufs_paths->insertItem(prevIndex, current);
	ui.ufs_paths->setCurrentRow(prevIndex);

	ufsPriorityRefresh();
}

void ConverterPIXGUI::ufsDownClicked() {
	int currIndex = ui.ufs_paths->currentRow();
	int nextIndex = currIndex + 1;

	QListWidgetItem *current = ui.ufs_paths->takeItem(currIndex);
	ui.ufs_paths->insertItem(nextIndex, current);
	ui.ufs_paths->setCurrentRow(nextIndex);

	ufsPriorityRefresh();
}

/* EXPORT PATH GUI */
void ConverterPIXGUI::exportPathBtnClicked() {
	QString exportPath = QFileDialog::getExistingDirectory(this, tr("Select export path"), "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	if (QDir(exportPath).exists()) {
		ui.export_path->setText(exportPath);
	} if (exportPath.length() == 0) {
		if (ui.ufs_paths->count() > 0)
			ui.export_path->setText(ui.ufs_paths->item(0)->text().left(ui.ufs_paths->item(0)->text().length() - 1));
	} else
		QMessageBox::critical(this, "ConverterPIX - Error", exportPath + "\n\nis not a valid directory path.");
}

void ConverterPIXGUI::exportPathEdited() {
	if (!QDir(ui.export_path->text()).exists()) {
		if (ui.ufs_paths->count() > 0)
			ui.export_path->setText(ui.ufs_paths->item(0)->text().left(ui.ufs_paths->item(0)->text().length() - 1));
		QMessageBox::critical(this, "ConverterPIX - Error", ui.export_path->text() + "\n\nis not a valid directory path.");
	}
}

/* CONVERSION */

void ConverterPIXGUI::convertModel() {
	int p = 0;
	QList<QListWidgetItem*> selectedModels = modelBrowser->selectedItems();

	if (selectedModels.count() == 0) {
		QMessageBox::critical(this, "ConvertPIX - Convert", "No models have been selected!");
		return;
	}

	for (int i = 0; i < selectedModels.count(); ++i) {
		QListWidgetItem *listItem = selectedModels.at(i);

		FileSystem::Entry f = qvariant_cast<FileSystem::Entry>(listItem->data(256));
		if (f.IsDirectory())
			continue;

		p = true;
		QString fullPathQ = qvariant_cast<QString>(listItem->data(257));
		String fullPath = fullPathQ.toStdString();
		fullPath = fullPath.substr(0, fullPath.rfind('.'));

		auto model = std::make_shared<Model>();
		if (!model->load(fullPath))
		{
			QMessageBox::critical(this, "ConvertPIX - Critical Error", "Unable to load model at path:\n" + (QString)f.GetFileSystem()->root().c_str() + (QString)fullPath.c_str());
			return;
		}
		model->saveToMidFormat(ui.export_path->text().toStdString(), true);
		if (selectedModels.count() == 1) {
			QList<QListWidgetItem*> selectedAnimations = animationBrowser->selectedItems();

			for (int i = 0; i < selectedAnimations.count(); ++i) {
				QListWidgetItem *listItem = selectedAnimations.at(i);
				QString fullPathQ = qvariant_cast<QString>(listItem->data(257));
				String fullPath = fullPathQ.toStdString();
				fullPath = fullPath.substr(0, fullPath.rfind('.'));

				Animation anim;
				if (!anim.load(model, fullPath))
				{
					QMessageBox::critical(this, "ConvertPIX - Critical Error", "Unable to load animation at path:\n" + (QString)f.GetFileSystem()->root().c_str() + (QString)fullPath.c_str());
					return;
				}
				anim.saveToPia(ui.export_path->text().toStdString());
			}
			QMessageBox::information(this, "ConvertPIX - Convert", "Model and animation(s) have successfully been converted.");
			return;
		}
	}
	if (p)
		QMessageBox::information(this, "ConvertPIX - Convert", "Model(s) have successfully been converted.");
	else
		QMessageBox::critical(this, "ConvertPIX - Critical Error", "No models selected!");
}
void ConverterPIXGUI::convertTexture() {
	int p = 0;
	QList<QListWidgetItem*> selectedTextures = textureBrowser->selectedItems();

	if (selectedTextures.count() == 0) {
		QMessageBox::critical(this, "ConvertPIX - Convert", "No textures selected!");
		return;
	}

	for (int i = 0; i < selectedTextures.count(); ++i) {
		QListWidgetItem *listItem = selectedTextures.at(i);

		FileSystem::Entry f = qvariant_cast<FileSystem::Entry>(listItem->data(256));
		if (f.IsDirectory())
			continue;

		p = true;
		QString fullPathQ = qvariant_cast<QString>(listItem->data(257));
		String fullPath = fullPathQ.toStdString();

		TextureObject tobj;
		if (!tobj.load(fullPath))
		{
			QMessageBox::critical(this, "ConvertPIX - Critical Error", "Unable to load texture at path:\n" + (QString)f.GetFileSystem()->root().c_str() + (QString)fullPath.c_str());
			return;
		}
		tobj.saveToMidFormats(ui.export_path->text().toStdString());
	}
	if (p)
		QMessageBox::information(this, "ConvertPIX - Convert", "Texture(s) have successfully been converted.");
	else
		QMessageBox::critical(this, "ConvertPIX - Critical Error", "No textures selected!");
}

void ConverterPIXGUI::convertClicked() {
	if (ui.ufs_paths->count() == 0) {
		QMessageBox::critical(this, "ConvertPIX - Critical Error", "No base paths added!");
		return;
	}

	ui.convert_btn->setText("Converting...");
	ui.convert_btn->repaint();

	if (ui.input_tabs->currentIndex() == 0)
		convertModel();
	else 
		convertTexture();

	ui.convert_btn->setText("Convert selected files");

}

void ConverterPIXGUI::convertAllModels() {
	if (ui.ufs_paths->count() == 0) {
		QMessageBox::critical(this, "ConvertPIX - Critical Error", "No base paths added!");
		return;
	}

	ui.convert_btn->setText("Converting...");
	ui.convert_btn->repaint();

	if (ui.input_tabs->currentIndex() == 0)
		convertModel();
	else
		convertTexture();

	ui.convert_btn->setText("Convert selected files");

}

/* eof */