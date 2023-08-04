#ifndef M37_TASK_1_CALCOPERATION_H
#define M37_TASK_1_CALCOPERATION_H

#include "QMainWindow"
#include "QLineEdit"
#include "QTextBrowser"
#include "QTextEdit"
#include "QString"
#include "iostream"

class CalcOperation : public QMainWindow
{
    Q_OBJECT

public:

    QLineEdit*lineEdit = nullptr;
    QLineEdit*lineInput1 = nullptr;
    QLineEdit*lineInput2 = nullptr;

    CalcOperation(QWidget*parent = nullptr) : QMainWindow(parent) {}

public slots:
    void input1()
    {
        QString tmp = lineInput1->text();
        tmp.replace(",", ".");
        std::string tmp_str;
        tmp_str = tmp.toStdString();
        for (int i =0; i<tmp_str.size();i++)
        {
            if (((tmp_str[i]<48||tmp_str[i]>57)||tmp_str[i]==44)&&tmp_str[i]!=46)
            {
                flag=false;
                return;
            }
        }
        a = tmp.toDouble();

    };
    void input2()
    {
        QString tmp = lineInput2->text();
        tmp.replace(",", ".");
        std::string tmp_str;
        tmp_str = tmp.toStdString();
        for (int i =0; i<tmp_str.size();i++)
        {
            if (((tmp_str[i]<48||tmp_str[i]>57)||tmp_str[i]==44)&&tmp_str[i]!=46)
            {
                flag=false;
                return;
            }
        }
        b = tmp.toDouble();
    };
    void plus()
    {
        if (flag)
        {
            res = a + b;
            lineEdit->setText(QString::number(a) + " + " + QString::number(b) + " = " + QString::number(res));
            lineInput1->clear();
            lineInput2->clear();
        }
        else
        {
            lineEdit->setText("ERROR!");
            flag=true;
            lineInput1->clear();
            lineInput2->clear();
        }
    };
    void minus()
    {
        if (flag)
        {
            res = a - b;
            lineEdit->setText(QString::number(a) + " - " + QString::number(b) + " = " + QString::number(res));
            lineInput1->clear();
            lineInput2->clear();
        }
        else
        {
            lineEdit->setText("ERROR!");
            flag=true;
            lineInput1->clear();
            lineInput2->clear();
        }
    };
    void multiply()
    {
        if (flag)
        {
            res = a * b;
            lineEdit->setText(QString::number(a) + " * " + QString::number(b) + " = " + QString::number(res));
            lineInput1->clear();
            lineInput2->clear();
        }
        else
        {
            lineEdit->setText("ERROR!");
            flag=true;
            lineInput1->clear();
            lineInput2->clear();
        }
    };
    void divide()
    {
        if (flag&&b!=0)
        {
            res = a/b;
            lineEdit->setText(QString::number(a)+" / "+QString::number(b)+" = "+QString::number(res));
            lineInput1->clear();
            lineInput2->clear();}
        else
        {
            lineEdit->setText("ERROR!");
            flag=true;
            lineInput1->clear();
            lineInput2->clear();
        }
    };

private:
    double res,a,b;
    bool flag = true;
};

#endif //M37_TASK_1_CALCOPERATION_H
