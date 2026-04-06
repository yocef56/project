/********************************************************************************
** Form generated from reading UI file 'addtaskdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTASKDIALOG_H
#define UI_ADDTASKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddTaskDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *taskNameEdit;
    QLabel *label_2;
    QSpinBox *workerIdSpinBox;
    QLabel *label_3;
    QDateEdit *startDateEdit;
    QLabel *label_4;
    QDateEdit *endDateEdit;
    QLabel *label_5;
    QComboBox *statusComboBox;
    QLabel *label_6;
    QTextEdit *descriptionEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddTaskDialog)
    {
        if (AddTaskDialog->objectName().isEmpty())
            AddTaskDialog->setObjectName("AddTaskDialog");
        AddTaskDialog->resize(400, 350);
        verticalLayout = new QVBoxLayout(AddTaskDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(AddTaskDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        taskNameEdit = new QLineEdit(AddTaskDialog);
        taskNameEdit->setObjectName("taskNameEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, taskNameEdit);

        label_2 = new QLabel(AddTaskDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        workerIdSpinBox = new QSpinBox(AddTaskDialog);
        workerIdSpinBox->setObjectName("workerIdSpinBox");
        workerIdSpinBox->setMinimum(1);
        workerIdSpinBox->setMaximum(999999);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, workerIdSpinBox);

        label_3 = new QLabel(AddTaskDialog);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        startDateEdit = new QDateEdit(AddTaskDialog);
        startDateEdit->setObjectName("startDateEdit");
        startDateEdit->setCalendarPopup(true);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, startDateEdit);

        label_4 = new QLabel(AddTaskDialog);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_4);

        endDateEdit = new QDateEdit(AddTaskDialog);
        endDateEdit->setObjectName("endDateEdit");
        endDateEdit->setCalendarPopup(true);

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, endDateEdit);

        label_5 = new QLabel(AddTaskDialog);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_5);

        statusComboBox = new QComboBox(AddTaskDialog);
        statusComboBox->setObjectName("statusComboBox");

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, statusComboBox);

        label_6 = new QLabel(AddTaskDialog);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, label_6);

        descriptionEdit = new QTextEdit(AddTaskDialog);
        descriptionEdit->setObjectName("descriptionEdit");

        formLayout->setWidget(5, QFormLayout::ItemRole::FieldRole, descriptionEdit);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(AddTaskDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AddTaskDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddTaskDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddTaskDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddTaskDialog);
    } // setupUi

    void retranslateUi(QDialog *AddTaskDialog)
    {
        AddTaskDialog->setWindowTitle(QCoreApplication::translate("AddTaskDialog", "Add New Task", nullptr));
        label->setText(QCoreApplication::translate("AddTaskDialog", "Task Name:", nullptr));
        label_2->setText(QCoreApplication::translate("AddTaskDialog", "Worker ID:", nullptr));
        label_3->setText(QCoreApplication::translate("AddTaskDialog", "Start Date:", nullptr));
        label_4->setText(QCoreApplication::translate("AddTaskDialog", "End Date:", nullptr));
        label_5->setText(QCoreApplication::translate("AddTaskDialog", "Status:", nullptr));
        label_6->setText(QCoreApplication::translate("AddTaskDialog", "Description:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddTaskDialog: public Ui_AddTaskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDTASKDIALOG_H
