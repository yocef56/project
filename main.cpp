#include "connection.h"
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  connection c;
  QString errorMsg;
  bool test = c.createconnect(errorMsg);

  MainWindow w;
  if (test) {
    w.show();
    QMessageBox::information(nullptr, QObject::tr("Database is open"),
                             QObject::tr("Connection successful.\n"
                                         "Click Cancel to exit."),
                             QMessageBox::Cancel);
  } else {
    QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                          QObject::tr("Connection failed.\nError: %1\n"
                                      "Click Cancel to exit.")
                              .arg(errorMsg),
                          QMessageBox::Cancel);
  }

  return a.exec();
}
