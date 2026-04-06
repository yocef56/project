#include "addtaskdialog.h"
#include "ui_addtaskdialog.h"
#include <QMessageBox>

AddTaskDialog::AddTaskDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::AddTaskDialog) {
  ui->setupUi(this);

  // Set default dates to today
  ui->startDateEdit->setDate(QDate::currentDate());
  ui->endDateEdit->setDate(QDate::currentDate().addDays(1));

  // Populate the status combobox
  ui->statusComboBox->addItem("Pending");
  ui->statusComboBox->addItem("In Progress");
  ui->statusComboBox->addItem("Completed");
}

AddTaskDialog::~AddTaskDialog() { delete ui; }

// Implement the getters to fetch data from the UI fields
QString AddTaskDialog::getTaskName() const { return ui->taskNameEdit->text(); }
QString AddTaskDialog::getDescription() const {
  return ui->descriptionEdit->toPlainText();
}
int AddTaskDialog::getWorkerId() const { return ui->workerIdSpinBox->value(); }
QDate AddTaskDialog::getStartDate() const { return ui->startDateEdit->date(); }
QDate AddTaskDialog::getEndDate() const { return ui->endDateEdit->date(); }
QString AddTaskDialog::getStatus() const {
  return ui->statusComboBox->currentText();
}

void AddTaskDialog::setTaskName(const QString &name) {
  ui->taskNameEdit->setText(name);
}
void AddTaskDialog::setDescription(const QString &desc) {
  ui->descriptionEdit->setPlainText(desc);
}
void AddTaskDialog::setWorkerId(int id) { ui->workerIdSpinBox->setValue(id); }
void AddTaskDialog::setStartDate(const QDate &date) {
  ui->startDateEdit->setDate(date);
}
void AddTaskDialog::setEndDate(const QDate &date) {
  ui->endDateEdit->setDate(date);
}
void AddTaskDialog::setStatus(const QString &status) {
  ui->statusComboBox->setCurrentText(status);
}

void AddTaskDialog::on_buttonBox_accepted() {
  // Basic UI-level validation before closing the dialog
  if (getTaskName().trimmed().isEmpty() ||
      getDescription().trimmed().isEmpty()) {
    QMessageBox::warning(this, "Input Error",
                         "Task Name and Description cannot be empty.");
    return; // Don't close the dialog
  }

  if (getEndDate() < getStartDate()) {
    QMessageBox::warning(this, "Input Error",
                         "End Date cannot be before Start Date.");
    return;
  }

  accept(); // Close the dialog and return QDialog::Accepted
}

void AddTaskDialog::on_buttonBox_rejected() {
  reject(); // Close the dialog and return QDialog::Rejected
}
