/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCount_steps;
    QAction *actionCount_keywords;
    QAction *actionFind_lines_not_starting_with_an_actor;
    QAction *actionCut_to_depth;
    QAction *actionLoad_JSON;
    QAction *actionGenerate_numbered_list;
    QAction *actionLoad_JSON2;
    QAction *actionHost;
    QAction *actionPort;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout_2;
    QLabel *titleLabel;
    QLabel *actorsLabel;
    QGridLayout *gridLayout_2;
    QPushButton *addPushButton;
    QPushButton *removePushButton;
    QListWidget *actorsListWidget;
    QLabel *systemActorLabel;
    QComboBox *actorsComboBox;
    QTextEdit *titleTextEdit;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menuCommands;
    QMenu *menuFile;
    QMenu *menuSettings;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setDocumentMode(false);
        actionCount_steps = new QAction(MainWindow);
        actionCount_steps->setObjectName(QString::fromUtf8("actionCount_steps"));
        actionCount_keywords = new QAction(MainWindow);
        actionCount_keywords->setObjectName(QString::fromUtf8("actionCount_keywords"));
        actionFind_lines_not_starting_with_an_actor = new QAction(MainWindow);
        actionFind_lines_not_starting_with_an_actor->setObjectName(QString::fromUtf8("actionFind_lines_not_starting_with_an_actor"));
        actionCut_to_depth = new QAction(MainWindow);
        actionCut_to_depth->setObjectName(QString::fromUtf8("actionCut_to_depth"));
        actionLoad_JSON = new QAction(MainWindow);
        actionLoad_JSON->setObjectName(QString::fromUtf8("actionLoad_JSON"));
        actionGenerate_numbered_list = new QAction(MainWindow);
        actionGenerate_numbered_list->setObjectName(QString::fromUtf8("actionGenerate_numbered_list"));
        actionLoad_JSON2 = new QAction(MainWindow);
        actionLoad_JSON2->setObjectName(QString::fromUtf8("actionLoad_JSON2"));
        actionHost = new QAction(MainWindow);
        actionHost->setObjectName(QString::fromUtf8("actionHost"));
        actionPort = new QAction(MainWindow);
        actionPort->setObjectName(QString::fromUtf8("actionPort"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(19, 13, 761, 541));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        formLayout_2->setRowWrapPolicy(QFormLayout::DontWrapRows);
        formLayout_2->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        titleLabel = new QLabel(verticalLayoutWidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, titleLabel);

        actorsLabel = new QLabel(verticalLayoutWidget);
        actorsLabel->setObjectName(QString::fromUtf8("actorsLabel"));
        actorsLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, actorsLabel);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 0, -1, -1);
        addPushButton = new QPushButton(verticalLayoutWidget);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        gridLayout_2->addWidget(addPushButton, 0, 1, 1, 1);

        removePushButton = new QPushButton(verticalLayoutWidget);
        removePushButton->setObjectName(QString::fromUtf8("removePushButton"));

        gridLayout_2->addWidget(removePushButton, 1, 1, 1, 1);

        actorsListWidget = new QListWidget(verticalLayoutWidget);
        actorsListWidget->setObjectName(QString::fromUtf8("actorsListWidget"));

        gridLayout_2->addWidget(actorsListWidget, 0, 0, 2, 1);


        formLayout_2->setLayout(1, QFormLayout::FieldRole, gridLayout_2);

        systemActorLabel = new QLabel(verticalLayoutWidget);
        systemActorLabel->setObjectName(QString::fromUtf8("systemActorLabel"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, systemActorLabel);

        actorsComboBox = new QComboBox(verticalLayoutWidget);
        actorsComboBox->setObjectName(QString::fromUtf8("actorsComboBox"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, actorsComboBox);

        titleTextEdit = new QTextEdit(verticalLayoutWidget);
        titleTextEdit->setObjectName(QString::fromUtf8("titleTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(titleTextEdit->sizePolicy().hasHeightForWidth());
        titleTextEdit->setSizePolicy(sizePolicy1);
        titleTextEdit->setMaximumSize(QSize(16777215, 30));
        titleTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, titleTextEdit);


        verticalLayout->addLayout(formLayout_2);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(textEdit);

        MainWindow->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuCommands = new QMenu(menuBar);
        menuCommands->setObjectName(QString::fromUtf8("menuCommands"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuCommands->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuCommands->addAction(actionCount_steps);
        menuCommands->addAction(actionCount_keywords);
        menuCommands->addAction(actionFind_lines_not_starting_with_an_actor);
        menuCommands->addAction(actionCut_to_depth);
        menuCommands->addAction(actionGenerate_numbered_list);
        menuFile->addAction(actionLoad_JSON2);
        menuSettings->addAction(actionHost);
        menuSettings->addAction(actionPort);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionCount_steps->setText(QApplication::translate("MainWindow", "Count steps", nullptr));
        actionCount_keywords->setText(QApplication::translate("MainWindow", "Count keywords", nullptr));
        actionFind_lines_not_starting_with_an_actor->setText(QApplication::translate("MainWindow", "Find lines not starting with an actor", nullptr));
        actionCut_to_depth->setText(QApplication::translate("MainWindow", "Cut to depth", nullptr));
        actionLoad_JSON->setText(QApplication::translate("MainWindow", "Load JSON", nullptr));
        actionGenerate_numbered_list->setText(QApplication::translate("MainWindow", "Generate numbered list", nullptr));
        actionLoad_JSON2->setText(QApplication::translate("MainWindow", "Load JSON", nullptr));
        actionHost->setText(QApplication::translate("MainWindow", "Host", nullptr));
        actionPort->setText(QApplication::translate("MainWindow", "Port", nullptr));
        titleLabel->setText(QApplication::translate("MainWindow", "Title", nullptr));
        actorsLabel->setText(QApplication::translate("MainWindow", "Actors", nullptr));
        addPushButton->setText(QApplication::translate("MainWindow", "Add", nullptr));
        removePushButton->setText(QApplication::translate("MainWindow", "Remove", nullptr));
        systemActorLabel->setText(QApplication::translate("MainWindow", "System actor", nullptr));
        menuCommands->setTitle(QApplication::translate("MainWindow", "Commands", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
