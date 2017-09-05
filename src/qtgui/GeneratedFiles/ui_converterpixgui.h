/********************************************************************************
** Form generated from reading UI file 'converterpixgui.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTERPIXGUI_H
#define UI_CONVERTERPIXGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *input_tabs;
    QWidget *model_tab;
    QListWidget *model_paths;
    QLineEdit *model_relative_path;
    QLabel *model_relative_path_lbl;
    QListWidget *listWidget;
    QListWidget *animation_selected;
    QLabel *animations_selected_lbl;
    QListWidget *animation_g_path;
    QListWidget *animation_paths;
    QLabel *animations_paths_lbl;
    QPushButton *animation_remove_btn;
    QPushButton *animation_add_btn;
    QLineEdit *animation_relative_path;
    QWidget *texture_tab;
    QListWidget *texture_paths;
    QLabel *texture_relative_path_lbl;
    QLineEdit *texture_relative_path;
    QListWidget *texture_relative_grapich;
    QLabel *label;
    QLabel *ufs_paths_lbl;
    QPushButton *ufs_add_btn;
    QListWidget *ufs_paths;
    QPushButton *ufs_unmount_btn;
    QPushButton *ufs_up_btn;
    QPushButton *ufs_down_btn;
    QPushButton *convert_btn;
    QPushButton *export_path_btn;
    QLineEdit *export_path;
    QLabel *export_path_lbl;
    QListWidget *model_paths_2;
    QLabel *log_label;
    QPushButton *convert_models_btn;
    QPushButton *convert_all_btn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1162, 912);
        MainWindow->setMinimumSize(QSize(1162, 912));
        MainWindow->setMaximumSize(QSize(1162, 912));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        input_tabs = new QTabWidget(centralwidget);
        input_tabs->setObjectName(QStringLiteral("input_tabs"));
        input_tabs->setGeometry(QRect(20, 230, 1121, 431));
        model_tab = new QWidget();
        model_tab->setObjectName(QStringLiteral("model_tab"));
        model_paths = new QListWidget(model_tab);
        model_paths->setObjectName(QStringLiteral("model_paths"));
        model_paths->setGeometry(QRect(20, 60, 471, 311));
        model_paths->setSelectionMode(QAbstractItemView::ExtendedSelection);
        model_paths->setSortingEnabled(true);
        model_relative_path = new QLineEdit(model_tab);
        model_relative_path->setObjectName(QStringLiteral("model_relative_path"));
        model_relative_path->setGeometry(QRect(20, 370, 471, 20));
        model_relative_path_lbl = new QLabel(model_tab);
        model_relative_path_lbl->setObjectName(QStringLiteral("model_relative_path_lbl"));
        model_relative_path_lbl->setGeometry(QRect(20, 12, 71, 16));
        listWidget = new QListWidget(model_tab);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(20, 30, 471, 21));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setTextElideMode(Qt::ElideRight);
        listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        listWidget->setFlow(QListView::LeftToRight);
        animation_selected = new QListWidget(model_tab);
        animation_selected->setObjectName(QStringLiteral("animation_selected"));
        animation_selected->setEnabled(true);
        animation_selected->setGeometry(QRect(510, 30, 221, 341));
        animation_selected->setSelectionMode(QAbstractItemView::ExtendedSelection);
        animation_selected->setSortingEnabled(true);
        animations_selected_lbl = new QLabel(model_tab);
        animations_selected_lbl->setObjectName(QStringLiteral("animations_selected_lbl"));
        animations_selected_lbl->setGeometry(QRect(510, 10, 101, 16));
        animation_g_path = new QListWidget(model_tab);
        animation_g_path->setObjectName(QStringLiteral("animation_g_path"));
        animation_g_path->setGeometry(QRect(820, 30, 271, 21));
        animation_g_path->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        animation_g_path->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        animation_g_path->setTextElideMode(Qt::ElideRight);
        animation_g_path->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        animation_g_path->setFlow(QListView::LeftToRight);
        animation_paths = new QListWidget(model_tab);
        animation_paths->setObjectName(QStringLiteral("animation_paths"));
        animation_paths->setGeometry(QRect(820, 60, 271, 311));
        animation_paths->setSelectionMode(QAbstractItemView::ExtendedSelection);
        animation_paths->setSortingEnabled(true);
        animations_paths_lbl = new QLabel(model_tab);
        animations_paths_lbl->setObjectName(QStringLiteral("animations_paths_lbl"));
        animations_paths_lbl->setGeometry(QRect(820, 10, 91, 16));
        animation_remove_btn = new QPushButton(model_tab);
        animation_remove_btn->setObjectName(QStringLiteral("animation_remove_btn"));
        animation_remove_btn->setEnabled(true);
        animation_remove_btn->setGeometry(QRect(740, 180, 75, 23));
        animation_add_btn = new QPushButton(model_tab);
        animation_add_btn->setObjectName(QStringLiteral("animation_add_btn"));
        animation_add_btn->setEnabled(true);
        animation_add_btn->setGeometry(QRect(740, 210, 75, 23));
        animation_relative_path = new QLineEdit(model_tab);
        animation_relative_path->setObjectName(QStringLiteral("animation_relative_path"));
        animation_relative_path->setGeometry(QRect(820, 370, 271, 20));
        input_tabs->addTab(model_tab, QString());
        texture_tab = new QWidget();
        texture_tab->setObjectName(QStringLiteral("texture_tab"));
        texture_paths = new QListWidget(texture_tab);
        texture_paths->setObjectName(QStringLiteral("texture_paths"));
        texture_paths->setGeometry(QRect(20, 60, 1071, 311));
        texture_paths->setSelectionMode(QAbstractItemView::ExtendedSelection);
        texture_paths->setSortingEnabled(true);
        texture_relative_path_lbl = new QLabel(texture_tab);
        texture_relative_path_lbl->setObjectName(QStringLiteral("texture_relative_path_lbl"));
        texture_relative_path_lbl->setGeometry(QRect(20, 12, 71, 16));
        texture_relative_path = new QLineEdit(texture_tab);
        texture_relative_path->setObjectName(QStringLiteral("texture_relative_path"));
        texture_relative_path->setGeometry(QRect(20, 370, 1071, 20));
        texture_relative_grapich = new QListWidget(texture_tab);
        texture_relative_grapich->setObjectName(QStringLiteral("texture_relative_grapich"));
        texture_relative_grapich->setGeometry(QRect(20, 30, 1071, 21));
        texture_relative_grapich->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        texture_relative_grapich->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        texture_relative_grapich->setTextElideMode(Qt::ElideRight);
        texture_relative_grapich->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        texture_relative_grapich->setFlow(QListView::LeftToRight);
        input_tabs->addTab(texture_tab, QString());
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 10, 1161, 51));
        QFont font;
        font.setPointSize(26);
        label->setFont(font);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        ufs_paths_lbl = new QLabel(centralwidget);
        ufs_paths_lbl->setObjectName(QStringLiteral("ufs_paths_lbl"));
        ufs_paths_lbl->setGeometry(QRect(340, 61, 71, 16));
        ufs_add_btn = new QPushButton(centralwidget);
        ufs_add_btn->setObjectName(QStringLiteral("ufs_add_btn"));
        ufs_add_btn->setGeometry(QRect(790, 80, 75, 23));
        ufs_paths = new QListWidget(centralwidget);
        ufs_paths->setObjectName(QStringLiteral("ufs_paths"));
        ufs_paths->setGeometry(QRect(340, 80, 431, 101));
        ufs_paths->setSelectionBehavior(QAbstractItemView::SelectRows);
        ufs_paths->setSortingEnabled(false);
        ufs_unmount_btn = new QPushButton(centralwidget);
        ufs_unmount_btn->setObjectName(QStringLiteral("ufs_unmount_btn"));
        ufs_unmount_btn->setEnabled(false);
        ufs_unmount_btn->setGeometry(QRect(790, 110, 75, 23));
        ufs_unmount_btn->setCheckable(false);
        ufs_unmount_btn->setChecked(false);
        ufs_unmount_btn->setFlat(false);
        ufs_up_btn = new QPushButton(centralwidget);
        ufs_up_btn->setObjectName(QStringLiteral("ufs_up_btn"));
        ufs_up_btn->setEnabled(false);
        ufs_up_btn->setGeometry(QRect(320, 80, 21, 23));
        ufs_up_btn->setFlat(true);
        ufs_down_btn = new QPushButton(centralwidget);
        ufs_down_btn->setObjectName(QStringLiteral("ufs_down_btn"));
        ufs_down_btn->setEnabled(false);
        ufs_down_btn->setGeometry(QRect(320, 157, 21, 23));
        ufs_down_btn->setFlat(true);
        convert_btn = new QPushButton(centralwidget);
        convert_btn->setObjectName(QStringLiteral("convert_btn"));
        convert_btn->setGeometry(QRect(790, 140, 201, 41));
        export_path_btn = new QPushButton(centralwidget);
        export_path_btn->setObjectName(QStringLiteral("export_path_btn"));
        export_path_btn->setGeometry(QRect(790, 199, 75, 23));
        export_path = new QLineEdit(centralwidget);
        export_path->setObjectName(QStringLiteral("export_path"));
        export_path->setGeometry(QRect(340, 200, 431, 20));
        export_path_lbl = new QLabel(centralwidget);
        export_path_lbl->setObjectName(QStringLiteral("export_path_lbl"));
        export_path_lbl->setGeometry(QRect(341, 185, 71, 16));
        model_paths_2 = new QListWidget(centralwidget);
        new QListWidgetItem(model_paths_2);
        new QListWidgetItem(model_paths_2);
        new QListWidgetItem(model_paths_2);
        new QListWidgetItem(model_paths_2);
        new QListWidgetItem(model_paths_2);
        model_paths_2->setObjectName(QStringLiteral("model_paths_2"));
        model_paths_2->setGeometry(QRect(20, 690, 1121, 201));
        model_paths_2->setSelectionMode(QAbstractItemView::NoSelection);
        model_paths_2->setSortingEnabled(true);
        log_label = new QLabel(centralwidget);
        log_label->setObjectName(QStringLiteral("log_label"));
        log_label->setGeometry(QRect(21, 671, 31, 16));
        convert_models_btn = new QPushButton(centralwidget);
        convert_models_btn->setObjectName(QStringLiteral("convert_models_btn"));
        convert_models_btn->setGeometry(QRect(880, 80, 111, 23));
        convert_all_btn = new QPushButton(centralwidget);
        convert_all_btn->setObjectName(QStringLiteral("convert_all_btn"));
        convert_all_btn->setGeometry(QRect(880, 110, 111, 23));
        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(ufs_paths, ufs_add_btn);
        QWidget::setTabOrder(ufs_add_btn, ufs_unmount_btn);
        QWidget::setTabOrder(ufs_unmount_btn, ufs_up_btn);
        QWidget::setTabOrder(ufs_up_btn, ufs_down_btn);
        QWidget::setTabOrder(ufs_down_btn, input_tabs);
        QWidget::setTabOrder(input_tabs, listWidget);
        QWidget::setTabOrder(listWidget, model_paths);
        QWidget::setTabOrder(model_paths, model_relative_path);
        QWidget::setTabOrder(model_relative_path, animation_g_path);
        QWidget::setTabOrder(animation_g_path, animation_add_btn);
        QWidget::setTabOrder(animation_add_btn, animation_paths);
        QWidget::setTabOrder(animation_paths, animation_remove_btn);
        QWidget::setTabOrder(animation_remove_btn, animation_selected);
        QWidget::setTabOrder(animation_selected, animation_relative_path);

        retranslateUi(MainWindow);

        input_tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ConverterPIX", Q_NULLPTR));
        model_relative_path->setText(QApplication::translate("MainWindow", "/", Q_NULLPTR));
        model_relative_path_lbl->setText(QApplication::translate("MainWindow", "Relative path:", Q_NULLPTR));
        animations_selected_lbl->setText(QApplication::translate("MainWindow", "Selected animations:", Q_NULLPTR));
        animations_paths_lbl->setText(QApplication::translate("MainWindow", "Select animations:", Q_NULLPTR));
        animation_remove_btn->setText(QApplication::translate("MainWindow", ">>>", Q_NULLPTR));
        animation_add_btn->setText(QApplication::translate("MainWindow", "<<<", Q_NULLPTR));
        animation_relative_path->setText(QApplication::translate("MainWindow", "/", Q_NULLPTR));
        input_tabs->setTabText(input_tabs->indexOf(model_tab), QApplication::translate("MainWindow", "Model", Q_NULLPTR));
        texture_relative_path_lbl->setText(QApplication::translate("MainWindow", "Relative path:", Q_NULLPTR));
        texture_relative_path->setText(QApplication::translate("MainWindow", "/", Q_NULLPTR));
        input_tabs->setTabText(input_tabs->indexOf(texture_tab), QApplication::translate("MainWindow", "Texture", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "ConverterPIX", Q_NULLPTR));
        ufs_paths_lbl->setText(QApplication::translate("MainWindow", "Base paths: ", Q_NULLPTR));
        ufs_add_btn->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        ufs_unmount_btn->setText(QApplication::translate("MainWindow", "Unmount", Q_NULLPTR));
        ufs_up_btn->setText(QApplication::translate("MainWindow", "\342\206\221", Q_NULLPTR));
        ufs_down_btn->setText(QApplication::translate("MainWindow", "\342\206\223", Q_NULLPTR));
        convert_btn->setText(QApplication::translate("MainWindow", "Convert selected items", Q_NULLPTR));
        export_path_btn->setText(QApplication::translate("MainWindow", "Choose...", Q_NULLPTR));
        export_path_lbl->setText(QApplication::translate("MainWindow", "Export path:", Q_NULLPTR));

        const bool __sortingEnabled = model_paths_2->isSortingEnabled();
        model_paths_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = model_paths_2->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = model_paths_2->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = model_paths_2->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem3 = model_paths_2->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "New Item", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem4 = model_paths_2->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MainWindow", "New Item", Q_NULLPTR));
        model_paths_2->setSortingEnabled(__sortingEnabled);

        log_label->setText(QApplication::translate("MainWindow", "Log:", Q_NULLPTR));
        convert_models_btn->setText(QApplication::translate("MainWindow", "Convert all models", Q_NULLPTR));
        convert_all_btn->setText(QApplication::translate("MainWindow", "Convert entire base", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTERPIXGUI_H
