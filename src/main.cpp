#include <iostream>

#include <qapplication.h>
#include "MainWindow.h"


int main(int argv, char** args) {
    QApplication appl(argv, args);
    MainWindow window;
    window.show();
    return appl.exec();
}
