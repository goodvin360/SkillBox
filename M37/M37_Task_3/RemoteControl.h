#ifndef M37_TASK_3_REMOTECONTROL_H
#define M37_TASK_3_REMOTECONTROL_H

#include "QWidget"
#include "QMainWindow"
#include "QLineEdit"
#include "QTextBrowser"


class RemoteControl : public QMainWindow
{
    Q_OBJECT

public:
    QTextBrowser*textBrowser = nullptr;
    RemoteControl(QWidget*parent= nullptr) : QMainWindow(parent) {}

    void showInfo()
    {
        textBrowser->setText("Current volume: " + QString::number(volume*10) + "%" + "\n" + "Current channel: " + QString::number(channel));
    };

public slots:

    void ch1()
    {
        channel = 1;
        showInfo();
    };
    void ch2()
    {
        channel = 2;
        showInfo();
    };
    void ch3()
    {
        channel = 3;
        showInfo();
    };
    void ch4()
    {
        channel = 4;
        showInfo();
    };
    void ch5()
    {
        channel = 5;
        showInfo();
    };
    void ch6()
    {
        channel = 6;
        showInfo();
    };
    void ch7()
    {
        channel = 7;
        showInfo();
    };
    void ch8()
    {
        channel = 8;
        showInfo();
    };
    void ch9()
    {
        channel = 9;
        showInfo();
    };
    void ch0()
    {
        channel = 0;
        showInfo();
    };
    void vol_plus()
    {
        volume++;
        if (volume>10)
            volume=10;
        showInfo();
    };
    void vol_minus()
    {
        volume--;
        if (volume<0)
            volume=0;
        showInfo();
    };
    void ch_plus()
    {
        channel++;
        if (channel>9)
            channel=0;
        showInfo();
    };
    void ch_minus()
    {
        channel--;
        if (channel<0)
            channel=9;
        showInfo();
    };


private:
    int channel=0;
    int volume=5;

};

#endif //M37_TASK_3_REMOTECONTROL_H
