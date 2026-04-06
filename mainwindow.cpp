#include "mainwindow.h"
#include "addtaskdialog.h"
#include "connection.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), taskModel(nullptr),
      tableView(nullptr) {
  ui->setupUi(this);

  ui->textEdit_3->setMaximumHeight(
      160); // Prevents it from pushing buttons off the screen

  // Resurrect the beautiful brown color without any padding or font constraints
  // that break Qt's text engine
  QString safeBtnStyle = "QPushButton { background-color: #786E45; color: "
                         "white; border-radius: 4px; border: 1px solid #555; } "
                         "QPushButton:hover { background-color: #473920; }";

  ui->pushButton_3->setText("Add");
  ui->pushButton_2->setText("Modify");
  ui->pushButton->setText("Delete");
  ui->pushButton_4->setText("Sort");
  ui->btnLogTime->setText("Log Time");

  ui->pushButton_3->setStyleSheet(safeBtnStyle);
  ui->pushButton_2->setStyleSheet(safeBtnStyle);
  ui->pushButton->setStyleSheet(safeBtnStyle);
  ui->pushButton_4->setStyleSheet(safeBtnStyle);
  ui->btnLogTime->setStyleSheet(safeBtnStyle);

  ui->pushButton_3->setMinimumHeight(40);
  ui->pushButton_2->setMinimumHeight(40);
  ui->pushButton->setMinimumHeight(40);
  ui->pushButton_4->setMinimumHeight(40);
  ui->btnLogTime->setMinimumHeight(40);

  ui->pushButton_3->setMaximumHeight(45);
  ui->pushButton_2->setMaximumHeight(45);
  ui->pushButton->setMaximumHeight(45);
  ui->pushButton_4->setMaximumHeight(45);
  ui->btnLogTime->setMaximumHeight(45);

  // Instead of squeezing into the vertical layout, put it dynamically on the
  // right side
  tableView = new QTableView(ui->Header);
  tableView->setGeometry(410, 80, 420, 380);
  tableView->setStyleSheet(
      "QTableView { background-color: white; color: black; border-radius: 8px; "
      "border: 1px solid #CCC; gridline-color: #DDD; font-size: 14pt; } "
      "QHeaderView::section { background-color: #786E45; color: white; "
      "font-weight: bold; padding: 5px; border: 1px solid #CCC; }");
  ui->widget->show(); // Show the statistics widget

  displayTasks();
}

MainWindow::~MainWindow() { delete ui; }

QString MainWindow::addTask(const QString &taskName, const QString &description,
                            int assignedWorkerId, const QDate &startDate,
                            const QDate &endDate, const QString &status) {
  // 1. Input Validation: Check for empty string fields
  if (taskName.trimmed().isEmpty() || description.trimmed().isEmpty() ||
      status.trimmed().isEmpty()) {
    return "Task Name, Description, and Status cannot be empty.";
  }

  // Input Validation: Validate assigned worker ID (assuming IDs must be
  // positive integers)
  if (assignedWorkerId <= 0) {
    return "Assigned Worker ID must be valid (greater than 0).";
  }

  // Input Validation: Ensure the end date is not before the start date
  if (endDate < startDate) {
    return "End date cannot be earlier than start date.";
  }

  // 2. Database Insertion
  QSqlQuery query;
  // Oracle requires a value for TASKID if it's not an IDENTITY column.
  // We'll use a subquery to find the next available ID.
  query.prepare("INSERT INTO TASK (TASKID, TASKNAME, DESCRIPTION, "
                "ASSIGNEDWORKERID, STARDATE, ENDDATE, STATUS) "
                "VALUES ((SELECT NVL(MAX(TASKID), 0) + 1 FROM TASK), "
                ":task_name, :description, :assigned_worker_id, "
                "TO_DATE(:start_date, 'YYYY-MM-DD'), TO_DATE(:end_date, "
                "'YYYY-MM-DD'), :status)");

  query.bindValue(":task_name", taskName.trimmed());
  query.bindValue(":description", description.trimmed());
  query.bindValue(":assigned_worker_id", assignedWorkerId);
  query.bindValue(":start_date", startDate.toString(Qt::ISODate));
  query.bindValue(":end_date", endDate.toString(Qt::ISODate));
  query.bindValue(":status", status.trimmed());

  // 3. Execution and Error Handling
  if (!query.exec()) {
    return query.lastError().text();
  }

  qDebug() << "Success: Task added successfully.";
  displayTasks(); // Refresh table
  return "";      // Empty string means success
}

void MainWindow::on_pushButton_3_clicked() {
  AddTaskDialog dialog(this);
  if (dialog.exec() == QDialog::Accepted) {
    QString error = addTask(dialog.getTaskName(), dialog.getDescription(),
                            dialog.getWorkerId(), dialog.getStartDate(),
                            dialog.getEndDate(), dialog.getStatus());

    if (error.isEmpty()) {
      QMessageBox::information(this, "Success", "Task added successfully!");
    } else {
      QMessageBox::critical(this, "Error",
                            "Failed to add task.\n\nDatabase Error: " + error);
    }
  }
}

QString MainWindow::deleteTask(int taskId) {
  QSqlQuery query;
  query.prepare("DELETE FROM TASK WHERE TASKID = :id");
  query.bindValue(":id", taskId);

  if (query.exec()) {
    if (query.numRowsAffected() > 0) {
      displayTasks(); // Refresh table
      return "";
    } else {
      return "Task ID " + QString::number(taskId) + " not found.";
    }
  } else {
    return query.lastError().text();
  }
}

void MainWindow::on_pushButton_clicked() {
  bool ok;
  int taskId =
      QInputDialog::getInt(this, tr("Delete Task"),
                           tr("Enter the ID of the task you want to delete:"),
                           0, 0, 2147483647, 1, &ok);

  if (ok) {
    QString error = deleteTask(taskId);
    if (error.isEmpty()) {
      QMessageBox::information(this, "Success", "Task deleted successfully!");
    } else {
      QMessageBox::critical(this, "Error",
                            "Failed to delete task.\n\nError: " + error);
    }
  }
}

void MainWindow::displayTasks() {
  if (!taskModel) {
    taskModel = new QSqlTableModel(this);
    tableView->setModel(taskModel);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
  }
  taskModel->setTable("TASK");
  if (!taskModel->select()) {
    QMessageBox::critical(this, "Table Load Error",
                          "Failed to load TASK table.\nError: " +
                              taskModel->lastError().text());
  }
  refreshSmartWidget(); // Update stats
  checkUpcomingDeadlines();
}

void MainWindow::refreshSmartWidget() {
  QSqlQuery query("SELECT STATUS, COUNT(*) FROM TASK GROUP BY STATUS");
  int total = 0;
  int completed = 0;

  while (query.next()) {
    QString status = query.value(0).toString().toUpper();
    int count = query.value(1).toInt();
    total += count;
    if (status == "COMPLETED" || status == "FINISHED" || status == "DONE") {
      completed += count;
    }
  }

  QString statsText =
      QString("📊 <font color='#625838'><b>Workshop Stats</b></font><br><br>"
              "📋 Total Tasks: %1<br>"
              "✅ Completed: %2<br>"
              "⏳ Awareness: %3<br><br>"
              "<font color='#786E45'><i>Keep up the great work!</i></font>")
          .arg(total)
          .arg(completed)
          .arg(total > 0 ? QString::number((completed * 100) / total) + "% Done"
                         : "No Tasks");

  ui->pieLabel->setText(statsText);
}

QString MainWindow::modifyTask(int taskId, const QString &taskName,
                               const QString &description, int assignedWorkerId,
                               const QDate &startDate, const QDate &endDate,
                               const QString &status) {
  QSqlQuery query;
  query.prepare(
      "UPDATE TASK SET TASKNAME = :task_name, DESCRIPTION = :description, "
      "ASSIGNEDWORKERID = :assigned_worker_id, STARDATE = TO_DATE(:start_date, "
      "'YYYY-MM-DD'), "
      "ENDDATE = TO_DATE(:end_date, 'YYYY-MM-DD'), STATUS = :status WHERE "
      "TASKID = :id");

  query.bindValue(":task_name", taskName.trimmed());
  query.bindValue(":description", description.trimmed());
  query.bindValue(":assigned_worker_id", assignedWorkerId);
  query.bindValue(":start_date", startDate.toString(Qt::ISODate));
  query.bindValue(":end_date", endDate.toString(Qt::ISODate));
  query.bindValue(":status", status.trimmed());
  query.bindValue(":id", taskId);

  if (query.exec()) {
    displayTasks(); // Refresh the table
    return "";
  } else {
    return query.lastError().text();
  }
}

void MainWindow::on_pushButton_2_clicked() {
  bool ok;
  int taskId =
      QInputDialog::getInt(this, tr("Modify Task"),
                           tr("Enter the ID of the task you want to modify:"),
                           0, 0, 2147483647, 1, &ok);

  if (ok) {
    // Fetch current details
    QSqlQuery query;
    query.prepare("SELECT * FROM TASK WHERE TASKID = :id");
    query.bindValue(":id", taskId);

    if (query.exec() && query.next()) {
      AddTaskDialog dialog(this);
      // Populate fields using Oracle column names exactly
      dialog.setTaskName(query.value("TASKNAME").toString());
      dialog.setDescription(query.value("DESCRIPTION").toString());
      dialog.setWorkerId(query.value("ASSIGNEDWORKERID").toInt());
      dialog.setStartDate(QDate::fromString(
          query.value("STARDATE").toString().left(10), Qt::ISODate));
      dialog.setEndDate(QDate::fromString(
          query.value("ENDDATE").toString().left(10), Qt::ISODate));
      dialog.setStatus(query.value("STATUS").toString());

      if (dialog.exec() == QDialog::Accepted) {
        QString error =
            modifyTask(taskId, dialog.getTaskName(), dialog.getDescription(),
                       dialog.getWorkerId(), dialog.getStartDate(),
                       dialog.getEndDate(), dialog.getStatus());
        if (error.isEmpty()) {
          QMessageBox::information(this, "Success",
                                   "Task modified successfully!");
        } else {
          QMessageBox::critical(this, "Error",
                                "Failed to update task.\n\nError: " + error);
        }
      }
    } else {
      QMessageBox::warning(this, "Error", "Task ID not found.");
    }
  }
}
// This searches for the typed text specifically in the DESCRIPTION column
void MainWindow::on_searchLineEdit_textChanged(const QString &arg1) {
  if (!taskModel)
    return;
  // We search for the keyword in the DESCRIPTION column
  taskModel->setFilter(QString("DESCRIPTION LIKE '%%1%'").arg(arg1));
  taskModel->select();
}

void MainWindow::on_textBrowser_textChanged() {
  // Placeholder slot for UI signal
}

void MainWindow::sortByDate(bool ascending) {
  if (!taskModel)
    return;
  // Index 4 is the 'STARDATE' column in your Oracle TASK table
  taskModel->setSort(4, ascending ? Qt::AscendingOrder : Qt::DescendingOrder);
  taskModel->select();
}

void MainWindow::on_pushButton_4_clicked() { sortByDate(true); }

void MainWindow::on_btnExportPDF_clicked() { exportTasksToPDF(); }

// 2. The PDF Logic
void MainWindow::exportTasksToPDF() {
  QString fileName =
      QFileDialog::getSaveFileName(this, "Export PDF", QString(), "*.pdf");
  if (fileName.isEmpty())
    return;

  QPdfWriter pdf(fileName);
  pdf.setPageSize(QPageSize(QPageSize::A4));
  pdf.setCreator("Carpentry Smart System");

  QPainter painter(&pdf);
  painter.setPen(Qt::black);
  painter.setFont(QFont("Arial", 20));

  // Title
  painter.drawText(400, 500, "Carpentry Workshop - Task Report");

  painter.setFont(QFont("Arial", 12));
  int y = 1000; // Starting vertical position

  // Iterate through your database model (Read operation)
  for (int i = 0; i < taskModel->rowCount(); ++i) {
    QString taskName = taskModel->data(taskModel->index(i, 1))
                           .toString(); // Column 1: TASKNAME
    QString status =
        taskModel->data(taskModel->index(i, 6)).toString(); // Column 6: STATUS

    painter.drawText(100, y,
                     QString("Task: %1 | Status: %2").arg(taskName, status));
    y += 500; // Move down for the next line
  }

  painter.end();
  QMessageBox::information(this, "Export Success",
                           "Task report has been saved as PDF.");
}
void MainWindow::on_pushButton_5_clicked() { exportTasksToPDF(); }

void MainWindow::checkUpcomingDeadlines() {
  ui->listWidget->clear();
  ui->notificationsBrowser->hide(); // Hide the old browser

  QDate today = QDate::currentDate();
  QDate deadlineLimit = today.addDays(2);

  QSqlQuery query;
  query.prepare("SELECT TASKID, TASKNAME, ENDDATE, TIMESPENT_MINUTES FROM TASK "
                "WHERE STATUS != 'COMPLETED'");

  if (query.exec()) {
    while (query.next()) {
      int id = query.value(0).toInt();
      QString name = query.value(1).toString();
      QDate date = query.value(2).toDate();
      int timeSpent = query.value(3).toInt();

      QString alertText;
      QListWidgetItem *item = nullptr;

      if (date < today) {
        // OVERDUE
        alertText =
            "🔴 En retard : " + name + " (" + date.toString("dd/MM/yyyy") + ")";
        item = new QListWidgetItem(alertText);
        item->setForeground(QBrush(Qt::red));
      } else if (date <= deadlineLimit) {
        // DUE SOON
        alertText =
            "🟡 Urgent : " + name + " (" + date.toString("dd/MM/yyyy") + ")";
        item = new QListWidgetItem(alertText);
        item->setForeground(QBrush(QColor("#D68910"))); // Dark orange
      } else if (timeSpent == 0) {
        // STALLED
        alertText = "🔵 À l'arrêt : " + name;
        item = new QListWidgetItem(alertText);
        item->setForeground(QBrush(Qt::blue));
      }

      if (item) {
        item->setData(Qt::UserRole, id);
        QFont font = item->font();
        font.setBold(true);
        item->setFont(font);
        ui->listWidget->addItem(item);
      }
    }

    if (ui->listWidget->count() == 0) {
      ui->listWidget->addItem("✅ Aucune alerte.");
    }
  }
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item) {
  if (!item)
    return;

  bool ok;
  int targetId = item->data(Qt::UserRole).toInt(&ok);
  if (!ok)
    return; // Ignore clicks on generic messages like "Aucune alerte"

  // Find the row in taskModel with this ID
  for (int row = 0; row < taskModel->rowCount(); ++row) {
    int id = taskModel->data(taskModel->index(row, 0))
                 .toInt(); // Assuming TASKID is column 0
    if (id == targetId) {
      tableView->selectRow(row);
      break;
    }
  }
}

void MainWindow::on_btnLogTime_clicked() {
  if (!tableView || !tableView->selectionModel())
    return;

  QModelIndexList selectedRows = tableView->selectionModel()->selectedRows();
  if (selectedRows.isEmpty()) {
    QMessageBox::warning(this, "Selection Error",
                         "Please select a task from the table to log time.");
    return;
  }

  int rowIndex = selectedRows.first().row();
  int taskId = taskModel->data(taskModel->index(rowIndex, 0)).toInt();

  bool ok;
  int minutes = QInputDialog::getInt(this, tr("Log Time"),
                                     tr("Enter time spent (in minutes):"), 0, 0,
                                     10000, 1, &ok);
  if (ok && minutes > 0) {
    QSqlQuery query;
    query.prepare("UPDATE TASK SET TIMESPENT_MINUTES = NVL(TIMESPENT_MINUTES, "
                  "0) + :added_minutes WHERE TASKID = :id");
    query.bindValue(":added_minutes", minutes);
    query.bindValue(":id", taskId);

    if (query.exec()) {
      QMessageBox::information(
          this, "Success",
          QString("Logged %1 minutes successfully!").arg(minutes));
      displayTasks();
    } else {
      QString errorText = query.lastError().text();
      if (errorText.contains("invalid identifier") ||
          errorText.contains("ORA-00904")) {
        QMessageBox::critical(this, "Database Error",
                              "The TIMESPENT_MINUTES column does not exist. "
                              "Please run in Oracle:\n\nALTER TABLE TASK ADD "
                              "TIMESPENT_MINUTES NUMBER DEFAULT 0;");
      } else {
        QMessageBox::critical(this, "Error",
                              "Failed to log time.\n\nError: " + errorText);
      }
    }
  }
}
