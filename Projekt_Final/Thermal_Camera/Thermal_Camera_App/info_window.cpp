/*****************************************************************************
This code is under the following license (unless stated differently inside the source code below)
*****************************************************************************/
/*****************************************************************************
Copyright <2020> <project_ge_wise2019_p2/Stud_1>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*****************************************************************************/

#include "info_window.h"
#include <QDesktopWidget>

#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
#include <QtWidgets>
#else
#include <QtGui>
#endif

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

    setWindowTitle(tr("Information"));
    setLayout(info_query);
}
