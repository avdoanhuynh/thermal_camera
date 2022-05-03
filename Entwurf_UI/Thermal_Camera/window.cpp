#include "window.h"
#include "info_window.h"
#include <QDesktopWidget>
#include <QtWidgets>
#include <QApplication>
#include <QWidget>
#include <cmath>


void Window::changeDisplayMax(int tempe1)
{
    int tempe5 = range_min->value();
    double tempe_interval = (tempe1-tempe5)/4.0;
    double tempe2 = tempe1-tempe_interval;
    double tempe3 = tempe2-tempe_interval;
    double tempe4 = tempe3-tempe_interval;

    QString tempe1_string = QString::number(tempe1);
    QString tempe2_string = QString::number(tempe2);
    QString tempe3_string = QString::number(tempe3);
    QString tempe4_string = QString::number(tempe4);
    QString tempe5_string = QString::number(tempe5);


    frame_temp1->setText(tempe1_string);
    frame_temp2->setText(tempe2_string);
    frame_temp3->setText(tempe3_string);
    frame_temp4->setText(tempe4_string);
    frame_temp5->setText(tempe5_string);
}

void Window::changeDisplayMin(int tempe5)
{
    int tempe1 = range_max->value();
    double tempe_interval = (tempe1-tempe5)/4.0;
    double tempe2 = tempe1-tempe_interval;
    double tempe3 = tempe2-tempe_interval;
    double tempe4 = tempe3-tempe_interval;

    QString tempe1_string = QString::number(tempe1);
    QString tempe2_string = QString::number(tempe2);
    QString tempe3_string = QString::number(tempe3);
    QString tempe4_string = QString::number(tempe4);
    QString tempe5_string = QString::number(tempe5);


    frame_temp1->setText(tempe1_string);
    frame_temp2->setText(tempe2_string);
    frame_temp3->setText(tempe3_string);
    frame_temp4->setText(tempe4_string);
    frame_temp5->setText(tempe5_string);
}

void Window::changeZoomFactor(int factor)
{
    double factor_temp = factor/10.0;
    QString factor_temp_string = "x "+ QString::number(factor_temp);
    frame_zoom_factor->setText(factor_temp_string);
}

void Window::changeRotationFactor(int factor)
{
    QString factor_string = QString::number(factor)+"°";
    frame_rotation_grade->setText(factor_string);
}

void Window::changeInfoPushed()
{
    InfoWindow info_window;
    info_window.setModal(true);
    info_window.exec();
    if(info_window.info_check)
    {
        frame_info->setText("Name:\t\t"+info_window.name_string+"\nDate Of Birth:\t"+info_window.date_string+"\nID-Nummer:\t"+info_window.id_string);
    }
}
void keyboardPushed()
{
    widgetKeyBoard *_keyboard = new widgetKeyBoard(false, this, false, this);
    _keyboard->setZoomFacility(true);
    _keyboard->enableSwitchingEcho(true);
    _keyboard->createKeyboard();
    _keyboard->hide(true);
     _keyboard->show();
}


Window::Window() : QWidget()
{

    resize(QDesktopWidget().availableGeometry(this).size() * 1);
    this->setStyleSheet("background-color:black;");
    QFont font;
    font.setPointSize(24);




    QVBoxLayout *setting_menu = new QVBoxLayout();

        //Setting Temperatur Range
        frame_range = new QFrame;
        frame_range_label = new QLabel("TEMPERATURE RANGE");
            frame_range_label->setStyleSheet("QFrame{color:white;}");
            frame_range_label->setAlignment(Qt::AlignCenter);

        range_max = new QSpinBox();
            range_max->setPrefix("Max:  ");
            range_max->setSuffix(" °C");
            range_max->setStyleSheet("color:white;");
            range_max->setMinimum(10);
            range_max->setMaximum(50);
            range_max->setValue(42);

        range_min = new QSpinBox();
            range_min->setPrefix("Min:  ");
            range_min->setSuffix(" °C");
            range_min->setStyleSheet("color:white;");
            range_min->setMinimum(10);
            range_min->setMaximum(50);
            range_min->setValue(32);

        QHBoxLayout *frame_range_box_temp = new QHBoxLayout();
            frame_range_box_temp->addWidget(range_min);
            frame_range_box_temp->addWidget(range_max);

        QVBoxLayout *frame_range_box = new QVBoxLayout();
            frame_range_box->addWidget(frame_range_label);
            frame_range_box->addLayout(frame_range_box_temp);

        frame_range->setLayout(frame_range_box);
        frame_range->setObjectName("frameRange");
        frame_range->setStyleSheet("#frameRange { border: 3px solid white;}");

        //Range Changed --> Scale Display Changed
        QObject::connect(range_max, SIGNAL(valueChanged(int)), this, SLOT(changeDisplayMax(int)));
        QObject::connect(range_min, SIGNAL(valueChanged(int)), this, SLOT(changeDisplayMin(int)));


        //Setting Zoom Factor
        frame_zoom = new QFrame;
        frame_zoom_label = new QLabel("ZOOM");
            frame_zoom_label->setStyleSheet("QFrame{color:white;}");
            frame_zoom_label->setAlignment(Qt::AlignCenter);
        frame_zoom_slider = new QSlider(Qt::Horizontal);
            frame_zoom_slider->setMinimum(10);
            frame_zoom_slider->setMaximum(30);
        frame_zoom_factor = new QLabel("x 1");
            frame_zoom_factor->setStyleSheet("QFrame{color:white;}");

        QHBoxLayout *frame_zoom_hori = new QHBoxLayout();
            frame_zoom_hori->addWidget(frame_zoom_slider);
            frame_zoom_hori->addWidget(frame_zoom_factor);
        QVBoxLayout *frame_zoom_box = new QVBoxLayout();
            frame_zoom_box->addWidget(frame_zoom_label);
            frame_zoom_box->addLayout(frame_zoom_hori);

        frame_zoom->setLayout(frame_zoom_box);
        frame_zoom->setObjectName("frameZoom");
        frame_zoom->setStyleSheet("#frameZoom { border: 3px solid white;}");

        QObject::connect(frame_zoom_slider, SIGNAL(valueChanged(int)), this, SLOT(changeZoomFactor(int)));


        //Setting Rotation Angle
        frame_rotation = new QFrame;
        frame_rotation_label = new QLabel("ROTATION");
            frame_rotation_label->setStyleSheet("QFrame{color:white;}");
            frame_rotation_label->setAlignment(Qt::AlignCenter);
        frame_rotation_slider = new QSlider(Qt::Horizontal);
            frame_rotation_slider->setMinimum(-180);
            frame_rotation_slider->setMaximum(180);
            frame_rotation_slider->setValue(0);
        frame_rotation_grade = new QLabel("0°");
            frame_rotation_grade->setStyleSheet("QFrame{color:white;}");


        QHBoxLayout *frame_rotation_hori = new QHBoxLayout();
             frame_rotation_hori->addWidget(frame_rotation_slider);
             frame_rotation_hori->addWidget(frame_rotation_grade);
        QVBoxLayout *frame_rotation_box = new QVBoxLayout();
            frame_rotation_box->addWidget(frame_rotation_label);
            frame_rotation_box->addLayout(frame_rotation_hori);

        frame_rotation->setLayout(frame_rotation_box);
        frame_rotation->setObjectName("frameRotation");
        frame_rotation->setStyleSheet("#frameRotation { border: 3px solid white;}");

        QObject::connect(frame_rotation_slider, SIGNAL(valueChanged(int)), this, SLOT(changeRotationFactor(int)));

        //Conversion Celsius/Fahrenheit
        frame_conversion = new QFrame;
        frame_conversion_label = new QLabel("CELSIUS/FAHRENHEIT CONVERSION");
            frame_conversion_label->setStyleSheet("QFrame{color:white;}");
            frame_conversion_label->setAlignment(Qt::AlignCenter);
        conversion_c = new QRadioButton("Celcius");
            conversion_c->setStyleSheet("color:white;");
            conversion_c ->setChecked(true);
        conversion_f = new QRadioButton("Fahrenheit");
            conversion_f->setStyleSheet("color:white;");

        QHBoxLayout *frame_conversion_box_temp = new QHBoxLayout();
            frame_conversion_box_temp->addWidget(conversion_c);
            frame_conversion_box_temp->addWidget(conversion_f);

        QVBoxLayout *frame_conversion_box = new QVBoxLayout();
            frame_conversion_box->addWidget(frame_conversion_label);
            frame_conversion_box->addLayout(frame_conversion_box_temp);

        frame_conversion->setLayout(frame_conversion_box);
        frame_conversion->setObjectName("frameConversion");
        frame_conversion->setStyleSheet("#frameConversion { border: 3px solid white;}");

        //Save screen shot
        frame_save = new QFrame;
        frame_save_label = new QLabel("SCREEN SHOT");
            frame_save_label->setStyleSheet("QFrame{color:white;}");
            frame_save_label->setAlignment(Qt::AlignCenter);
        frame_save_button = new QPushButton("Save Screen Shot");
            frame_save_button->setStyleSheet("background-color:white;");


        QVBoxLayout *frame_save_box = new QVBoxLayout();
            frame_save_box->addWidget(frame_save_label);
            frame_save_box->addWidget(frame_save_button);

        frame_save->setLayout(frame_save_box);
        frame_save->setObjectName("frameSave");
        frame_save->setStyleSheet("#frameSave { border: 3px solid white;}");



        frame_detection = new QLabel("OBJECT DETECTION");

        frame_network = new QLabel("NETWORK");
        frame_shutdown = new QLabel("SHUTDOWN");



        frame_detection->setAlignment(Qt::AlignCenter);

        frame_network->setAlignment(Qt::AlignCenter);
        frame_shutdown->setAlignment(Qt::AlignCenter);




        frame_detection->setStyleSheet("QFrame{ border: 3px solid white; color:white;}");

        frame_network->setStyleSheet("QFrame{ border: 3px solid white; color:white;}");
        frame_shutdown->setStyleSheet("QFrame{ border: 3px solid white; color:white;}");








        setting_menu->addWidget(frame_range);
        setting_menu->addWidget(frame_zoom);
        setting_menu->addWidget(frame_rotation);
        setting_menu->addWidget(frame_conversion);
        setting_menu->addWidget(frame_detection);
        setting_menu->addWidget(frame_save);
        setting_menu->addWidget(frame_network);
        setting_menu->addWidget(frame_shutdown);



     QGridLayout *display_menu = new QGridLayout();

        frame_scale = new QLabel();
        frame_scale -> setPixmap(QPixmap("/Users/anhvudoanhuynh/Documents/Aufgabe/HTW/WS1920/Thermal_Camera/colorscale_jet.jpg"));

        temp1 = range_max->value();
        temp5 = range_min->value();
        temp_interval = (temp1-temp5)/4.0;
        temp2 = temp1-temp_interval;
        temp3 = temp2-temp_interval;
        temp4 = temp3-temp_interval;



        frame_temp1 = new QLabel(QString::number(temp1));
        frame_temp2 = new QLabel(QString::number(temp2));
        frame_temp3 = new QLabel(QString::number(temp3));
        frame_temp4 = new QLabel(QString::number(temp4));
        frame_temp5 = new QLabel(QString::number(temp5));


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


        display_menu->addWidget(frame_scale,0,0,5,1);
        display_menu->addWidget(frame_temp1,0,1,1,1);
        display_menu->addWidget(frame_temp2,1,1,1,1);
        display_menu->addWidget(frame_temp3,2,1,1,1);
        display_menu->addWidget(frame_temp4,3,1,1,1);
        display_menu->addWidget(frame_temp5,4,1,1,1);


        //Cursor-Min-Max
        frame_cursor= new QLabel("Cursor: 23.5");
        frame_min = new QLabel("Min: 22.5");
        frame_max = new QLabel("Max: 22.6");

        frame_cursor->setStyleSheet("QFrame{border: 3px solid white; color:white;}");
        frame_min->setStyleSheet("QFrame{border: 3px solid white; color:blue;}");
        frame_max->setStyleSheet("QFrame{border: 3px solid white; color:red;}");

        frame_cursor->setAlignment(Qt::AlignCenter);
        frame_min->setAlignment(Qt::AlignCenter);
        frame_max->setAlignment(Qt::AlignCenter);

        frame_cursor->setFont(font);
        frame_min->setFont(font);
        frame_max->setFont(font);

    //Central Part

    thermal_display = new QLabel("THERMAL PIC");
    thermal_display->setStyleSheet("QFrame{ border: 3px solid white; color:white;}");

    QGridLayout *info_display = new QGridLayout();

    frame_info = new QLabel("Name: \nDate Of Birth: \nID-Nummer: ");
        frame_info->setStyleSheet("QFrame{ border: 3px solid white; color:white;}");
        frame_info->setFont(font);

    frame_freeze = new QPushButton("Freeze");
        frame_freeze->setStyleSheet("background-color:white;");
    frame_change_info = new QPushButton("Change Information");
        frame_change_info->setStyleSheet("background-color:white;");
        QObject::connect(frame_change_info, SIGNAL(clicked()), this, SLOT(changeInfoPushed()));

    info_display->addWidget(frame_info,0,0,5,4);
    info_display->addWidget(frame_freeze,0,4,2,1);
    info_display->addWidget(frame_change_info,2,4,3,1);

    QGridLayout *design = new QGridLayout();
    design->addLayout(display_menu, 0,0,7,2);
    design->addWidget(frame_cursor,7,0,2,2);
    design->addWidget(frame_min,9,0,2,2);
    design->addWidget(frame_max,11,0,2,2);

    design->addWidget(thermal_display,0,2,11,7);
    design->addLayout(info_display,11,2,2,7);

    design->addLayout(setting_menu, 0,9,13,4);


    setLayout(design);

}
