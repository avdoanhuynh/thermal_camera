#ifndef WINDOW_H
#define WINDOW_H
#include <QApplication>
#include <QWidget>
#if QT_VERSION >= QT_VERSION_CHECK(5,0,0)
#include <QtWidgets>
#else
#include <QtGui>
#endif



class Window : public QWidget
{

  Q_OBJECT

  public:
    Window();
    void changeDisplayTemp();
    void changeSymbol();
    void mousePressEvent (QMouseEvent *ev);

  public:

    QFrame *frame_factor;

    QLabel *frame_range_max_label;
    QLabel *frame_range_max_factor;
    QSlider *range_max;

    QLabel *frame_range_min_label;
    QLabel *frame_range_min_factor;
    QSlider *range_min;

    QLabel *frame_zoom_label;
    QLabel *frame_zoom_factor;
    QSlider *frame_zoom_slider;

    QLabel *frame_rotation_label;
    QLabel *frame_rotation_grade;
    QSlider *frame_rotation_slider;

    QRadioButton *conversion_c;
    QRadioButton *conversion_f;

    QPushButton *frame_save_button;

    QPushButton *frame_detection_button;
    QLabel *frame_detection_label;
    QLabel *frame_detection_grade;
    QSlider *frame_detection_slider;

    QPushButton *frame_shutdown_button;
    QFrame *frame_button;

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
    QLabel *info_display;

    QPushButton *frame_freeze;
    QPushButton *frame_change_info;
    QLabel *frame_info;

    QPoint Coordinate;

    double temp1;
    double temp5;
    double temp_interval;
    double temp2;
    double temp3;
    double temp4;
    int factor_zoom;
    int factor_rotation;
    QString degree_symbol;
    bool freeze_check;
    bool detection_check;

public slots:
      void changeDisplayMax(int tempe1);
      void changeDisplayMin(int tempe5);
      void changeZoomFactor(int factor);
      void changeRotationFactor(int factor);
      void changeUnit();
      void freezePushed();
      void savePushed();
      void changeInfoPushed();
      void detectionPushed();
      void detectionSliderChange(int value);
      void shutDownPushed();




};
#endif // WINDOW_H
