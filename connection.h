#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QWidget>


class connection : public QWidget {
  Q_OBJECT
public:
public:
  explicit connection(QWidget *parent = nullptr);
  bool createconnect(QString &errorMsg);

signals:
};

#endif // CONNECTION_H
