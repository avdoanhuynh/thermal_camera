#ifndef WINDOW_H
#define WINDOW_H
#include <QApplication>
#include <QWidget>
#include <QtWidgets>
#include "info_window.h"
#include "widgetKeyBoard.h"



class Window : public QWidget
{

  Q_OBJECT

  public:
    Window();


  public:
    QFrame *frame_range;
    QLabel *frame_range_label;
    QSpinBox *range_max;
    QSpinBox *range_min;

    QFrame *frame_zoom;
    QLabel *frame_zoom_label;
    QLabel *frame_zoom_factor;
    QSlider *frame_zoom_slider;

    QFrame *frame_rotation;
    QLabel *frame_rotation_label;
    QLabel *frame_rotation_grade;
    QSlider *frame_rotation_slider;

    QFrame *frame_conversion;
     QLabel *frame_conversion_label;
    QRadioButton *conversion_c;
    QRadioButton *conversion_f;

    QFrame *frame_save;
    QLabel *frame_save_label;
    QPushButton *frame_save_button;

    QLabel *frame_detection;
    QLabel *frame_network;

    QLabel *frame_shutdown;


    QLabel *frame_scale;
    QLabel *frame_temp1;
    QLabel *frame_temp2;
    QLabel *frame_temp3;
    QLabel *frame_temp4;
    QLabel *frame_temp5;
    QLabel *frame_cursor;
    QLabel *frame_min;
    QLabel *frame_max;

    QLabel *thermal_display;

    QPushButton *frame_freeze;
    QPushButton *frame_change_info;
    QLabel *frame_info;

    double temp1;
    double temp5;
    double temp_interval;
    double temp2;
    double temp3;
    double temp4;



public slots:
      void changeDisplayMax(int tempe1);
      void changeDisplayMin(int tempe5);
      void changeZoomFactor(int factor);
      void changeRotationFactor(int factor);
      void changeInfoPushed();
      void keyboardPushed();



};
#endif // WINDOW_H
