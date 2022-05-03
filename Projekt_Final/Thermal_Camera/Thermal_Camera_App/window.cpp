/*****************************************************************************
This code is under the following license (unless stated differently inside the source code below)
*****************************************************************************/
/*****************************************************************************
Copyright <2020> <project_ge_wise2019_p2/Stud_1>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*****************************************************************************/

#include "window.h"
#include "screenshot.h"
#include "info_window.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QWidget>
#include <cmath>
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
#include <QtWidgets>
#else
#include <QtGui>
#endif

void Window::mousePressEvent (QMouseEvent *ev)
{
    Coordinate = thermal_display->mapFrom(this,ev->pos());
}

//Check if unit is Celsius or Fahrenheit --> Display
void Window::changeSymbol()
{
    if(conversion_c->isChecked()==true)
    {
        degree_symbol="\xB0 C";
    }
    else
    {
        degree_symbol="\xB0 F";
    }
}

//Change the color scale display when temperature range is changed
void Window::changeDisplayTemp()
{
    changeSymbol();
    temp_interval = (temp1-temp5)/4.0;
    temp2 = temp1-temp_interval;
    temp3 = temp2-temp_interval;
    temp4 = temp3-temp_interval;

    frame_temp1->setText(">="+QString::number(temp1)+degree_symbol);
    frame_temp2->setText(QString::number(temp2)+degree_symbol);
    frame_temp3->setText(QString::number(temp3)+degree_symbol);
    frame_temp4->setText(QString::number(temp4)+degree_symbol);
    frame_temp5->setText("<="+QString::number(temp5)+degree_symbol);

}

//Max temperature range changed
void Window::changeDisplayMax(int tempe1)
{
    temp1 = tempe1;
    temp5 = range_min->value();
    changeDisplayTemp();
    frame_range_max_factor->setText(QString::number(range_max->value())+degree_symbol);
}

//Min temperature range changed
void Window::changeDisplayMin(int tempe5)
{
    temp5 = tempe5;
    temp1 = range_max->value();
    changeDisplayTemp();
    frame_range_min_factor->setText(QString::number(range_min->value())+degree_symbol);
}

//Zoom factor changed
void Window::changeZoomFactor(int factor)
{
    factor_zoom = factor;
    QString factor_zoom_string = "x "+ QString::number(factor_zoom);
    frame_zoom_factor->setText(factor_zoom_string);
}

//Rotation angle changed
void Window::changeRotationFactor(int factor)
{
    factor_rotation=factor;
    QString factor_string = QString::number(factor)+"\xB0";
    frame_rotation_grade->setText(factor_string);
}

//When unit is change from Celcius to Fahrenheit or vice versa
void Window::changeUnit()
{
    if(conversion_c->isChecked()==true)
    {
        range_max->setMinimum(10);
        range_max->setMaximum(50);
        range_max->setValue(32);
        frame_range_max_factor->setText(QString::number(range_max->value())+"\xB0 C");


        range_min->setMinimum(10);
        range_min->setMaximum(50);
        range_min->setValue(22);
        frame_range_min_factor->setText(QString::number(range_min->value())+"\xB0 C");
    }
    else
    {
        range_max->setMinimum(50);
        range_max->setMaximum(122);
        range_max->setValue(89);
        frame_range_max_factor->setText(QString::number(range_max->value())+"\xB0 F");

        range_min->setMinimum(50);
        range_min->setMaximum(122);
        range_min->setValue(71);
        frame_range_min_factor->setText(QString::number(range_min->value())+"\xB0 F");
    }

    temp1 = range_max->value();
    temp5 = range_min->value();
    changeDisplayTemp();
}

//When Freeze button is pushed
void Window::freezePushed()
{
    freeze_check = !freeze_check;
    if(freeze_check==true)
    {
        frame_freeze->setText("UNFREEZE");
    }
    else
    {
        frame_freeze->setText("FREEZE");
    }
}

//When Screen shot button is pushed
void Window::savePushed()
{
    Screenshot screenshot;
    screenshot.setModal(true);
    screenshot.exec();
}

//When Change Information button is pushed
void Window::changeInfoPushed()
{
    InfoWindow info_window;
    info_window.setModal(true);
    info_window.exec();
    if(info_window.info_check)
    {
        frame_info->setText("Name:\t\t"+info_window.name_string+"\nDay Of Birth:\t"+info_window.date_string+"\nID-Number:\t"+info_window.id_string);
    }
}

//When Edge Detection button is pushed
void Window::detectionPushed()
{
    detection_check =!detection_check;
    if(detection_check)
    {
        frame_detection_button->setText("EGDE DETECTION: ON");
    }
    else
    {
        frame_detection_button->setText("EGDE DETECTION: OFF");
    }
}

//Threshold for Edge Detection changed
void Window::detectionSliderChange(int value)
{
    frame_detection_grade->setText(QString::number(value));
}

//Shut down button Pushed
void Window::shutDownPushed()
{
    QCoreApplication::exit();
    system("shutdown -P now");
}

Window::Window() : QWidget()
{
    QFont font,font2;
    font.setPointSize(10);
    font2.setPointSize(11);

    resize(QDesktopWidget().availableGeometry(this).size() * 1);        //Set size of main window
    this->setStyleSheet("background-color:black;");                     //Set style of main window

    // //////////////////////////////////////////////////////////////////////////////////////////
    //Setting menu (on the right side on the main window)
    // //////////////////////////////////////////////////////////////////////////////////////////

    QVBoxLayout *setting_menu = new QVBoxLayout();

    //Setting Range Max
    frame_range_max_label = new QLabel("MAX");
        frame_range_max_label->setStyleSheet("QFrame{color:white;}");
        frame_range_max_label->setAlignment(Qt::AlignCenter);
        frame_range_max_label->setFont(font);
    range_max = new QSlider(Qt::Horizontal);
        range_max->setMinimum(10);
        range_max->setMaximum(50);
        range_max->setValue(32);
        range_max->setFont(font);
    frame_range_max_factor = new QLabel(QString::number(range_max->value())+"\xB0 C");
        frame_range_max_factor->setStyleSheet("QFrame{color:white;}");
        frame_range_max_factor->setFont(font);

    QHBoxLayout *frame_range_max = new QHBoxLayout();
        frame_range_max->addWidget(frame_range_max_label);
        frame_range_max->addWidget(range_max);
        frame_range_max->addWidget(frame_range_max_factor);

    QObject::connect(range_max, SIGNAL(valueChanged(int)), this, SLOT(changeDisplayMax(int)));

    //Setting Range Min
    frame_range_min_label = new QLabel("MIN");
        frame_range_min_label->setStyleSheet("QFrame{color:white;}");
        frame_range_min_label->setAlignment(Qt::AlignCenter);
        frame_range_min_label->setFont(font);
    range_min = new QSlider(Qt::Horizontal);
        range_min->setMinimum(10);
        range_min->setMaximum(50);
        range_min->setValue(22);
        range_min->setFont(font);
    frame_range_min_factor = new QLabel(QString::number(range_min->value())+"\xB0 C");
        frame_range_min_factor->setStyleSheet("QFrame{color:white;}");
        frame_range_min_factor->setFont(font);

    QHBoxLayout *frame_range_min = new QHBoxLayout();
        frame_range_min->addWidget(frame_range_min_label);
        frame_range_min->addWidget(range_min);
        frame_range_min->addWidget(frame_range_min_factor);

    QObject::connect(range_min, SIGNAL(valueChanged(int)), this, SLOT(changeDisplayMin(int)));


    //Setting Zoom Factor
    factor_zoom = 1;
    frame_zoom_label = new QLabel("ZOOM");
        frame_zoom_label->setStyleSheet("QFrame{color:white;}");
        frame_zoom_label->setAlignment(Qt::AlignCenter);
        frame_zoom_label->setFont(font);
    frame_zoom_slider = new QSlider(Qt::Horizontal);
        frame_zoom_slider->setMinimum(1);
        frame_zoom_slider->setMaximum(5);
        frame_zoom_slider->setFont(font);
    frame_zoom_factor = new QLabel("x 1");
        frame_zoom_factor->setStyleSheet("QFrame{color:white;}");
        frame_zoom_factor->setFont(font);

    QHBoxLayout *frame_zoom= new QHBoxLayout();
        frame_zoom->addWidget(frame_zoom_label);
        frame_zoom->addWidget(frame_zoom_slider);
        frame_zoom->addWidget(frame_zoom_factor);

    QObject::connect(frame_zoom_slider, SIGNAL(valueChanged(int)), this, SLOT(changeZoomFactor(int)));


    //Setting Rotation Angle
    factor_rotation = 0;
    frame_rotation_label = new QLabel("ROTATE");
        frame_rotation_label->setStyleSheet("QFrame{color:white;}");
        frame_rotation_label->setAlignment(Qt::AlignCenter);
        frame_rotation_label->setFont(font);
    frame_rotation_slider = new QSlider(Qt::Horizontal);
        frame_rotation_slider->setMinimum(-180);
        frame_rotation_slider->setMaximum(180);
        frame_rotation_slider->setValue(0);
        frame_rotation_slider->setFont(font);
    frame_rotation_grade = new QLabel("0\xB0");
        frame_rotation_grade->setStyleSheet("QFrame{color:white;}");
        frame_rotation_grade->setFont(font);

    QHBoxLayout *frame_rotation= new QHBoxLayout();
        frame_rotation->addWidget(frame_rotation_label);
        frame_rotation->addWidget(frame_rotation_slider);
        frame_rotation->addWidget(frame_rotation_grade);

    QObject::connect(frame_rotation_slider, SIGNAL(valueChanged(int)), this, SLOT(changeRotationFactor(int)));

    //Conversion Celsius/Fahrenheit
    conversion_c = new QRadioButton("Celcius");
        conversion_c->setStyleSheet("color:white;");
        conversion_c->setChecked(true);
        conversion_c->setFont(font);
    conversion_f = new QRadioButton("Fahrenheit");
        conversion_f->setStyleSheet("color:white;");
        conversion_f->setFont(font);

    QHBoxLayout *frame_conversion = new QHBoxLayout();
        frame_conversion->addWidget(conversion_c);
        frame_conversion->addWidget(conversion_f);

    QObject::connect(conversion_c, SIGNAL(clicked()), this, SLOT(changeUnit()));
    QObject::connect(conversion_f, SIGNAL(clicked()), this, SLOT(changeUnit()));

    QVBoxLayout *frame_factor_box = new QVBoxLayout();
        frame_factor_box->addLayout(frame_range_max);
        frame_factor_box->addLayout(frame_range_min);
        frame_factor_box->addLayout(frame_zoom);
        frame_factor_box->addLayout(frame_rotation);
        frame_factor_box->addLayout(frame_conversion);

    frame_factor = new QFrame;
    frame_factor->setLayout(frame_factor_box);
    frame_factor->setObjectName("frameFactor");
    frame_factor->setStyleSheet("#frameFactor { border: 1px solid white;}");


    //Edge Detection
    frame_detection_label = new QLabel("THRESHOLD");
        frame_detection_label->setStyleSheet("QFrame{color:white;}");
        frame_detection_label->setFont(font);
    frame_detection_button = new QPushButton("EDGE DETECTION: OFF");
        frame_detection_button->setStyleSheet("background-color:white;");
        frame_detection_button->setFont(font);
    frame_detection_slider = new QSlider(Qt::Horizontal);
        frame_detection_slider->setMinimum(0);
        frame_detection_slider->setMaximum(100);
        frame_detection_slider->setValue(15);
        frame_detection_slider->setFont(font);
    frame_detection_grade = new QLabel("15");
        frame_detection_grade->setStyleSheet("QFrame{color:white;}");
        frame_detection_grade->setFont(font);

    QHBoxLayout *frame_detection = new QHBoxLayout();
        frame_detection->addWidget(frame_detection_slider);
        frame_detection->addWidget(frame_detection_grade);

    detection_check=false;
    QObject::connect(frame_detection_button, SIGNAL(clicked()), this, SLOT(detectionPushed()));
    QObject::connect(frame_detection_slider, SIGNAL(valueChanged(int)), this, SLOT(detectionSliderChange(int)));

    //Save Screen shot
    frame_save_button = new QPushButton("SAVE");
        frame_save_button->setStyleSheet("background-color:white;");
        frame_save_button->setFont(font);

    QObject::connect(frame_save_button, SIGNAL(clicked()), this, SLOT(savePushed()));

    //Shutdown
    frame_shutdown_button = new QPushButton("SHUT DOWN");
        frame_shutdown_button->setStyleSheet("background-color:white;");
        frame_shutdown_button->setFont(font);

    QObject::connect(frame_shutdown_button, SIGNAL(clicked()), this, SLOT(shutDownPushed()));

    QVBoxLayout *frame_button_box = new QVBoxLayout();
        frame_button_box->addWidget(frame_detection_label);
        frame_button_box->addLayout(frame_detection);
        frame_button_box->addWidget(frame_detection_button);
        frame_button_box->addWidget(frame_save_button);
        frame_button_box->addWidget(frame_shutdown_button);

    frame_button = new QFrame;
        frame_button->setLayout(frame_button_box);
        frame_button->setObjectName("frameButton");
        frame_button->setStyleSheet("#frameButton { border: 1px solid white;}");

    setting_menu->addWidget(frame_factor);
    setting_menu->addWidget(frame_button);


    // ///////////////////////////////////////////////////////////////////////////////////////////////////
    //Color Scale and Temperature display (on the left side of the main window)
    // /////////////////////////////////////////////////////////////////////////////////////////////////

    QGridLayout *display_menu = new QGridLayout();

    //Color scale
    frame_scale = new QLabel();
    frame_scale -> setPixmap(QPixmap("/home/pi/Desktop/Thermal_Camera/Thermal_Camera_App/colorscale_jet.jpg"));
    
    temp1 = range_max->value();
    temp5 = range_min->value();

    frame_temp1 = new QLabel();
    frame_temp2 = new QLabel();
    frame_temp3 = new QLabel();
    frame_temp4 = new QLabel();
    frame_temp5 = new QLabel();

    frame_temp1->setStyleSheet("QFrame{color:white;}");
    frame_temp2->setStyleSheet("QFrame{color:white;}");
    frame_temp3->setStyleSheet("QFrame{color:white;}");
    frame_temp4->setStyleSheet("QFrame{color:white;}");
    frame_temp5->setStyleSheet("QFrame{color:white;}");

    frame_scale->setAlignment(Qt::AlignRight);
    frame_temp1->setAlignment(Qt::AlignTop);
    frame_temp2->setAlignment(Qt::AlignTop);
    frame_temp4->setAlignment(Qt::AlignBottom);
    frame_temp5->setAlignment(Qt::AlignBottom);

    frame_scale->setFont(font);
    frame_temp1->setFont(font);
    frame_temp2->setFont(font);
    frame_temp3->setFont(font);
    frame_temp4->setFont(font);
    frame_temp5->setFont(font);

    changeDisplayTemp();

    display_menu->addWidget(frame_scale,0,0,5,1);
    display_menu->addWidget(frame_temp1,0,1,1,1);
    display_menu->addWidget(frame_temp2,1,1,1,1);
    display_menu->addWidget(frame_temp3,2,1,1,1);
    display_menu->addWidget(frame_temp4,3,1,1,1);
    display_menu->addWidget(frame_temp5,4,1,1,1);

    //Display max-min Temperature and Temperature on clicked
    frame_max = new QLabel();
    frame_max->setStyleSheet("QFrame{border: 1px solid white; color:red;}");
    frame_max->setFont(font2);

    frame_min = new QLabel();
    frame_min->setStyleSheet("QFrame{border: 1px solid white; color:blue;}");
    frame_min->setFont(font2);

    frame_cursor= new QLabel("Temp:");
    frame_cursor->setStyleSheet("QFrame{border: 1px solid white; color:white;}");
    frame_cursor->setFont(font2);


    // ///////////////////////////////////////////////////////////////////////////////////////
    //Display thermal image - private information - Freeze Button (Central part of the window)
    // ///////////////////////////////////////////////////////////////////////////////////////

    thermal_display = new QLabel();
        thermal_display->setStyleSheet("QFrame{ border: 1px solid white; color:white;}");
        thermal_display->setScaledContents(false);

    QGridLayout *info_display = new QGridLayout();

    frame_info = new QLabel("Name: \nDay Of Birth: \nID-Number: ");
        frame_info->setStyleSheet("QFrame{ border: 1px solid white; color:white;}");
        frame_info->setFont(font);

    frame_freeze = new QPushButton("FREEZE");
        frame_freeze->setStyleSheet("background-color:white;");
        frame_freeze->setFont(font);
        freeze_check=false;
        QObject::connect(frame_freeze, SIGNAL(clicked()), this, SLOT(freezePushed()));
    frame_change_info = new QPushButton("Change Info");
        frame_change_info->setStyleSheet("background-color:white;");
        frame_change_info->setFont(font);
        QObject::connect(frame_change_info, SIGNAL(clicked()), this, SLOT(changeInfoPushed()));

    info_display->addWidget(frame_info,0,0,5,4);
    info_display->addWidget(frame_freeze,0,4,2,1);
    info_display->addWidget(frame_change_info,2,4,3,1);

    //Overall Layout
    QGridLayout *design = new QGridLayout();

        design->addLayout(display_menu,0,0,4,2);
        design->addWidget(frame_cursor,4,0,2,2);
        design->addWidget(frame_max,6,0,2,2);
        design->addWidget(frame_min,8,0,2,2);

        design->addWidget(thermal_display,0,2,8,6);
        design->addLayout(info_display,8,2,2,6);

        design->addLayout(setting_menu,0,8,10,2);

    setLayout(design);

}
