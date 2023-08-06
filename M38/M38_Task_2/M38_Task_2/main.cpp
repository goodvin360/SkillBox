#include<QtGui/QtGui>
#include <QWebEngineView>
#include <QApplication>
#include <QPlainTextEdit>
#include <QGridLayout>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto *appWindow = new QWidget;
    auto *plainText = new QPlainTextEdit;
    auto *webView = new QWebEngineView;
    auto layout = new QGridLayout(appWindow);

    layout->addWidget(plainText,0,0);
    layout->addWidget(webView,0,1);
    layout->setColumnStretch(0, 1);
    layout->setColumnStretch(1, 1);

    QObject::connect(plainText, &QPlainTextEdit::textChanged,[webView, plainText]()
     {
         auto textToShow = plainText->toPlainText();
        // text for example: <H1>Hello there, general Kenoby!</H1>
         webView->setHtml(textToShow);
     } );
    appWindow->resize(900,600);
    appWindow->show();
    return a.exec();
}

#include <main.moc>
