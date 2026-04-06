#ifndef ADDTASKDIALOG_H
#define ADDTASKDIALOG_H

#include <QDate>
#include <QDialog>

namespace Ui {
class AddTaskDialog;
}

class AddTaskDialog : public QDialog {
  Q_OBJECT

public:
  explicit AddTaskDialog(QWidget *parent = nullptr);
  ~AddTaskDialog();

  // Getters for the typed-in data
  QString getTaskName() const;
  QString getDescription() const;
  int getWorkerId() const;
  QDate getStartDate() const;
  QDate getEndDate() const;
  QString getStatus() const;

  // Setters to populate data for editing
  void setTaskName(const QString &name);
  void setDescription(const QString &desc);
  void setWorkerId(int id);
  void setStartDate(const QDate &date);
  void setEndDate(const QDate &date);
  void setStatus(const QString &status);

private slots:
  void on_buttonBox_accepted();
  void on_buttonBox_rejected();

private:
  Ui::AddTaskDialog *ui;
};

#endif // ADDTASKDIALOG_H
