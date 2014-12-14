#include "widget.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *mainwindow = new QWidget;
    mainwindow->setWindowTitle("Hex");

    Widget w;
    w.show();

/*  QPushButton *quitbutton = new QPushButton("Quit");
    QObject::connect(quitbutton,SIGNAL(clicked()),&a,SLOT(quit()));
    //quitbutton->show();
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(w);
    layout->addWidget(quitbutton);
    mainwindow->setLayout(layout);
    mainwindow->show();
*/
    return a.exec();
}
