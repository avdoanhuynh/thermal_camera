#include <QApplication>
#include "window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window main_window;
    main_window.show();
    return app.exec();

}
