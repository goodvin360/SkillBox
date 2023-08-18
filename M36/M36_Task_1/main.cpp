#include <QApplication>
#include "QWidget"
#include "iostream"
#include "QPushButton"
#include "QVBoxLayout"
#include "QGridLayout"
#include "QSlider"
#include "QLabel"
#include "QPixmap"
#include "QPainter"
#include "QPaintEvent"

class Circle : public QWidget
{
    Q_OBJECT
public:
    Circle(QWidget*parent);
    void paintEvent(QPaintEvent*e);
    QSize minimumSizeHint() const override;

public slots:
    void setGreen();
    void setYellow();
    void setRed();
    void setColour(int val);
private:
    QPixmap mCurrentColour;
    QPixmap mGreenColour;
    QPixmap mYellowColour;
    QPixmap mRedColour;
};

Circle::Circle(QWidget *parent)
{
    setParent(parent);
    mGreenColour = QPixmap("../pics/green.png");
    mYellowColour = QPixmap("../pics/yellow.png");
    mRedColour = QPixmap("../pics/red.png");
    mCurrentColour = mGreenColour;
    setGeometry(mCurrentColour.rect());
}

void Circle::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentColour);
}

QSize Circle::minimumSizeHint() const
{
    return QWidget::sizeHint();
}

void Circle::setGreen()
{
    mCurrentColour = mGreenColour;
    update();
}

void Circle::setYellow()
{
    mCurrentColour = mYellowColour;
    update();
}

void Circle::setRed()
{
    mCurrentColour = mRedColour;
    update();
}

void Circle::setColour(int val)
{
    if (val<=33)
        setGreen();
    else if (val>33&&val<66)
        setYellow();
    else if (val>=66)
        setRed();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget*window = new QWidget;
    Circle*fig = new Circle(nullptr);
    QSlider*slider = new QSlider(Qt::Horizontal,window);
    slider->setMaximum(100);
    slider->setMinimum(0);
    auto *layout = new QGridLayout(window);
    layout->addWidget(fig,0,0,1,2);
    layout->addWidget(slider,1,0,1,2);
    window->resize(600, 600);
    QObject::connect(slider, &QSlider::valueChanged, fig, &Circle::setColour);

    window->show();

    return app.exec();
    delete fig;
    delete slider;
    delete window;
}

#include <main.moc>