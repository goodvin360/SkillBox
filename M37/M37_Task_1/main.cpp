#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include "CalcOperation.h"
#include "./ui_calc.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CalcOperation window(nullptr);
    Ui::MainWindow calc;
    calc.setupUi(&window);
    window.lineEdit = calc.lineEdit;
    window.lineInput1 = calc.lineEdit_2;
    window.lineInput2 = calc.lineEdit_3;
    window.resize(480,320);
    window.show();
    return QApplication::exec();
}
