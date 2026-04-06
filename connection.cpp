#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

connection::connection(QWidget *parent) : QWidget{parent} {}

bool connection::createconnect(QString &errorMsg) {
  bool test = false;

  // Use Oracle ODBC driver to connect to the actual DB
  QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

  // use the full Net Service Descriptor format with SID=XE (common for 11g XE)
  // use the verified parameters from SQL Developer: Host=localhost, Port=1522,
  // SID=xe
  // Consolidating everything into the string sometimes fixes authentication
  // issues with QODBC
  db.setDatabaseName(
      "DRIVER={Oracle in "
      "OraDB21Home1};DBQ=localhost:1522/xe;UID=yousseff;PWD=1234;");

  // Clear these as they are now in the string above
  db.setUserName("");
  db.setPassword("");

  if (db.open()) {
    test = true;
  } else {
    // This will capture Oracle DB errors
    errorMsg = db.lastError().text();
  }

  return test;
}
