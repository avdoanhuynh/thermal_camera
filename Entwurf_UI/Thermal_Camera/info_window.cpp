
#include "info_window.h"
#include <QDesktopWidget>
#include <QtWidgets>
#include <QApplication>
#include <QWidget>

void InfoWindow::okButtonPushed()
{
    if(name->text().isEmpty() || id->text().isEmpty())
    {
        info_check=false;
        name_string = "";
        date_string = "";
        id_string = "";
        QMessageBox::information(this, "Error", "Please don't leave empty space");
    }
    else
    {
        info_check=true;
        name_string = name->text();
        id_string=id->text();
        date_string= QString::number(day->value())+"."+QString::number(month->value())+"."+QString::number(year->value());
        this->close();
    }
}

void InfoWindow::cancelButtonPushed()
{
    info_check=false;
    this->close();
}

InfoWindow::InfoWindow() : QDialog()
{
    info_check = false;
    QHBoxLayout *name_frame = new QHBoxLayout();
        name = new QLineEdit();
        name_label = new QLabel("Name");
        name_frame->addWidget(name_label);
        name_frame->addWidget(name);

    QHBoxLayout *dateOfBirth = new QHBoxLayout();
        date_label = new QLabel("DOB:");
        day = new QSpinBox();
            day->setPrefix("Day:  ");
            day->setMinimum(1);
            day->setMaximum(31);
            day->setValue(1);

        month = new QSpinBox();
            month->setPrefix("Month:  ");
            month->setMinimum(1);
            month->setMaximum(12);
            month->setValue(1);

        year = new QSpinBox();
            year->setPrefix("Year:  ");
            year->setMinimum(1900);
            year->setMaximum(2020);
            year->setValue(1990);

        dateOfBirth->addWidget(date_label);
        dateOfBirth->addWidget(day);
        dateOfBirth->addWidget(month);
        dateOfBirth->addWidget(year);

    QHBoxLayout *id_frame = new QHBoxLayout();
        id = new QLineEdit();
        id_label = new QLabel("ID-Nr.");
        id_frame->addWidget(id_label);
        id_frame->addWidget(id);

    QHBoxLayout *button_frame = new QHBoxLayout();
        ok_button = new QPushButton("OK");
        cancel_button = new QPushButton("Cancel");
        button_frame->addWidget(ok_button);
        button_frame->addWidget(cancel_button);
        QObject::connect(ok_button, SIGNAL(clicked()), this, SLOT(okButtonPushed()));
        QObject::connect(cancel_button, SIGNAL(clicked()), this, SLOT(cancelButtonPushed()));

    QVBoxLayout *info_query = new QVBoxLayout();
    info_query->addLayout(name_frame);
    info_query->addLayout(dateOfBirth);
    info_query->addLayout(id_frame);
    info_query->addLayout(button_frame);

    setLayout(info_query);
}
