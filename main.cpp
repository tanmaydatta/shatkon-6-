#include "widget.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QPushButton>
#include <QPixmap>
#include <QLabel>
#include <QPicture>
#include <iostream>
#include <QDebug>
#include "firstwindow.h"
//#include <QSound>




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QApplication *mainwin=&a;

    QWidget *mainwindow = new QWidget;
    mainwindow->setWindowTitle("Hex");

    qDebug() << "break3";
    Widget w;
//    w.show();
//    w.addfunctionality(&a);

//    firstwindow fw;
    qDebug() << "break4";

//    QSound *bgmusic = new QSound(":/backgr/Kindle_the_Prayer_edit_ (2).wav",0);
//        bgmusic->setLoops(QSound::Infinite);
//        bgmusic->play();
//        bgmusic->play(":/backgr/Kindle_the_Prayer_edit_ (2).wav");

    QPushButton *bgstop = new QPushButton("Stop Music");
//        QObject::connect(bgstop,SIGNAL(clicked()),bgmusic,SLOT(stop()));
    QPushButton *bgplay = new QPushButton("Play Music");
//        QObject::connect(bgplay,SIGNAL(clicked()),bgmusic,SLOT(play()));

    QPushButton *quitbutton = new QPushButton("Quit");
        QObject::connect(quitbutton,SIGNAL(clicked()),&a,SLOT(quit()));
//    quitbutton->show();

    QGridLayout *glayout = new QGridLayout;
    glayout->addWidget(&w,0,0,4,1,0);
    glayout->addWidget(bgstop,0,1,1,1,0);
    glayout->addWidget(bgplay,1,1,1,1,0);
    glayout->addWidget(quitbutton,2,1,1,1,0);
    mainwindow->setLayout(glayout);
//    mainwindow->show();

    firstwindow fw(mainwindow,&a);

    return a.exec();
}
