#include "phystat.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PhyStat w;

    // This code centers the app on the desktop.
    //
    QDesktopWidget *desktop = a.desktop();
    int screenWidth, width;
    int screenHeight, height;
    int x, y;
    QSize windowSize;

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    windowSize = w.size();
    width = windowSize.width();
    height = windowSize.height();

    x = (screenWidth - width) / 2;
    y = (screenHeight - height) / 2;

    // Offset for task bar at bottom of screen
    //
    y -= 50;

    w.move( x, y );
    w.show();

    return a.exec();
}
