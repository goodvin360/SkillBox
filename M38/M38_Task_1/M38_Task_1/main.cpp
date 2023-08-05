#include <QApplication>
#include <QMediaPlayer>
#include <QMediaContent>
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
#include "QTimer"
#include "QSound"
#include "QSoundEffect"
#include "QMultimedia"
#include "QMediaObject"
#include "QUrl"

class Circle : public QPushButton
{
    Q_OBJECT
public:
    Circle() = default;
    Circle(QWidget*parent);
    void paintEvent(QPaintEvent*e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent*e) override;

public slots:
    void setPushed();
    void setUnPushed();

private:
    QPixmap mCurrentState;
    QPixmap mPushedState;
    QPixmap mUnPushedState;
};

Circle::Circle(QWidget *parent)
{
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    mPushedState = QPixmap("../M38_Task_1/pics/red_pushed.png");
    mUnPushedState = QPixmap("../M38_Task_1/pics/red.png");
    mCurrentState = mUnPushedState;
    setGeometry(mCurrentState.rect());
    connect(this, &QPushButton::clicked, this, &Circle::setPushed);
}


void Circle::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(e->rect(), mCurrentState);
}

QSize Circle::sizeHint() const
{
    return sizeHint();
}

QSize Circle::minimumSizeHint() const
{
    return QSize(100,100);
}

void Circle::keyPressEvent(QKeyEvent *e)
{
    setPushed();
}

void Circle::setPushed()
{
    mCurrentState = mPushedState;
    update();
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("../M38_Task_1/sounds/click.wav"));
    music->play();
    QTimer::singleShot(100,this, &Circle::setUnPushed);
}

void Circle::setUnPushed()
{
    mCurrentState = mUnPushedState;
    update();
}


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Circle redButton(nullptr);
    redButton.setFixedSize(300,300);
    redButton.move(1000,400);
    redButton.show();
    return app.exec();
}

#include <main.moc>
