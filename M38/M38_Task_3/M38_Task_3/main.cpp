#include <QApplication>
#include <QPushButton>
#include "QMainWindow"
#include "BlurApplication.h"
#include "./ui_appWindowClion.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    BlurApplication window(nullptr);
    Ui::MainWindow appBlur;
    appBlur.setupUi(&window);
    window.picture = appBlur.label;
    window.sliderVal = appBlur.horizontalSlider;
    window.resize(480, 680);
    window.show();
    return QApplication::exec();
}
