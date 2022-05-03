#ifndef INFO_WINDOW_H
#define INFO_WINDOW_H
#include <QApplication>
#include <QWidget>
#include <QtWidgets>

class InfoWindow : public QDialog
{

  Q_OBJECT

  public:
    InfoWindow();

  public:
    QLineEdit *name;
    QLabel *name_label;
    QSpinBox *day;
    QSpinBox *month;
    QSpinBox *year;
    QLineEdit *id;
    QLabel *id_label;
    QLabel *date_label;
    QPushButton *ok_button;
    QPushButton *cancel_button;
    bool info_check;
    QString name_string,date_string,id_string;

  public slots:
      void okButtonPushed();
      void cancelButtonPushed();

};
#endif // INFO_WINDOW_H
