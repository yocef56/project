#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDate>
#include <QFileDialog>
#include <QListWidgetItem>
#include <QMainWindow>
#include <QPainter>
#include <QPdfWriter>
#include <QString>


class QSqlTableModel;
class QTableView;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  // Task Management Methods (Return empty string on success, error message on
  // failure)
  QString addTask(const QString &taskName, const QString &description,
                  int assignedWorkerId, const QDate &startDate,
                  const QDate &endDate, const QString &status);
  QString deleteTask(int taskId);
  QString modifyTask(int taskId, const QString &taskName,
                     const QString &description, int assignedWorkerId,
                     const QDate &startDate, const QDate &endDate,
                     const QString &status);
  void displayTasks();
  void refreshSmartWidget();
  void checkUpcomingDeadlines();

private slots:
  void on_pushButton_3_clicked(); // Add Button
  void on_pushButton_clicked();   // Delete Button
  void on_pushButton_2_clicked(); // Modify Button
  void on_searchLineEdit_textChanged(const QString &arg1);

  void on_listWidget_itemDoubleClicked(QListWidgetItem *item);
  void on_textBrowser_textChanged();

  void on_pushButton_4_clicked();
  void on_btnLogTime_clicked();
  void on_btnExportPDF_clicked();

  void on_pushButton_5_clicked();

private:
  Ui::MainWindow *ui;
  QSqlTableModel *taskModel;
  QTableView *tableView;
  void sortByDate(bool ascending);
  void exportTasksToPDF();
};
#endif // MAINWINDOW_H
