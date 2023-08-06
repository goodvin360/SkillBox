#ifndef M38_TASK_3_BLURAPPLICATION_H
#define M38_TASK_3_BLURAPPLICATION_H

#include "QMainWindow"
#include "QString"
#include "iostream"
#include "QGraphicsBlurEffect"
#include "QImage"
#include "QLabel"
#include "QSlider"
#include "QFileDialog"
#include "QPainter"

class BlurApplication : public QMainWindow
{
    Q_OBJECT

public:

    QLabel*picture = nullptr;
    QSlider*sliderVal = nullptr;

    BlurApplication(QWidget*parent = nullptr) : QMainWindow(parent) {}

public slots:
    void getFile()
    {
        auto fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "../pics/", tr("Image Files (*.png)"));

        mCurrentPicture = QPixmap(fileName);
        if (!fileName.isEmpty())
        {
            mCurrentPicture = mCurrentPicture.scaled(300, 300, Qt::KeepAspectRatioByExpanding);
            picture->setPixmap(mCurrentPicture);
            picture->setScaledContents(1);
            update();
        }
    };
    void changeBlurGrade()
    {
        auto* blur = new QGraphicsBlurEffect;
        blur->setBlurRadius(sliderVal->value());
        picture->setGraphicsEffect(blur);
        update();
    };

private:
    QPixmap mCurrentPicture;
};


#endif //M38_TASK_3_BLURAPPLICATION_H
