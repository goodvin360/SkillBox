#include <QApplication>
#include <QPushButton>
#include <QMainWindow>
#include "RemoteControl.h"
#include "./ui_remote.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    RemoteControl window(nullptr);
    Ui::MainWindow remote;
    remote.setupUi(&window);
    window.textBrowser = remote.textBrowser;
    window.resize(240, 680);
    window.show();
    window.showInfo();
    return QApplication::exec();
}
