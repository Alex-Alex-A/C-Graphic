 #include <QApplication>

 #include "window.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     Window window;
     window.setMinimumWidth(640);
     window.setMinimumHeight(480);

     QPalette palette(window.palette());
     palette.setColor(QPalette::Window, QColor(228, 236, 239, 255));
     window.setPalette(palette);

     window.show();
     return app.exec();
 }
