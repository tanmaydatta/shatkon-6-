#include "won.h"
#include <QLabel>
#include <QString>
#include <QPushButton>
//#include "mainalgo.cpp"
#include <QVBoxLayout>
//#include "main.cpp"


won::won(int p) {
    player=p;
    QString *tellwin= new QString;
    QLabel *winlab = new QLabel;
    if(player==1||player==3) {
        tellwin = new QString("Congrats! BLUE, you have won");
    }
    else if(player==2) {
        tellwin = new QString("Sorry BLUE, you have lost");
    }
    else
    {
        tellwin = new QString("Congrats! RED, you have won");
    }

    winlab->setText(*tellwin);

    QWidget *windisplay = new QWidget;

    QPushButton *close = new QPushButton("Exit");
    QObject::connect(close,SIGNAL(clicked()),windisplay,SLOT(close()));

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(winlab);
    vlayout->addWidget(close);
    windisplay->setLayout(vlayout);
    windisplay->show();

}



