#include <QGridLayout>
#include <QString>
#include <QAbstractButton>
#include "firstwindow.h"

int check=0;

firstwindow::firstwindow(QWidget *main,QApplication *program) {

    prog=program;

    nextwidget = new QWidget;
    nextwidget = main;

    fwin = new QWidget;
    QLabel *logo = new QLabel;

    QPixmap hexlogo(":/logo/hex.bmp");
//    hexlogo = new QPixmap(":/logo/hex.bmp");
    logo->setPixmap(hexlogo);

    player1 = new QPushButton("1 Player");
        QObject::connect(player1,SIGNAL(clicked()),this,SLOT(click_pla1()));
    player2 = new QPushButton("2 Player");
        QObject::connect(player2,SIGNAL(clicked()),this,SLOT(click_pla2()));
    instruc = new QPushButton("Instructions");
    qDebug() << "break7";
        QObject::connect(instruc,SIGNAL(clicked()),this,SLOT(click_ins()));
    qDebug() << "break8";
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(logo,0,0,1,3,0);
    layout->addWidget(instruc,1,0,1,1,0);
    layout->addWidget(player1,1,1,1,1,0);
    layout->addWidget(player2,1,2,1,1,0);

/*    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget(logo);
    vlayout->addWidget(hlayout);
*/
    fwin->setLayout(layout);
    fwin->show();

}


void firstwindow::click_ins() {
    qDebug() << "break9";
    QWidget *ins = new QWidget;
    qDebug() << "break5";

    QString instructions("Hex is a strategy game played on a hexagonal grid. \nIn this game the objective is to connect the two opposite ends of the rhombical board made of hexagons via any path possible \n\nWhile in \"1 PLAYER\" mode you will have the Blue Hex and would need to connect the board Horizontally\n\nWhile in \"2 PLAYER\" mode the 1st player will have the Blue Hex and will go first and connect it horizontally \n and the 2nd player will have the Red Hex and connect vertically.\n\nHave Fun.");
    QLabel *inslabel = new QLabel;
    inslabel->setText(instructions);

    QPushButton *insclose = new QPushButton("Close");
    QObject::connect(insclose,SIGNAL(clicked()),ins,SLOT(close()));

    QVBoxLayout *inslayout = new QVBoxLayout;
    inslayout->addWidget(inslabel);
    inslayout->addWidget(insclose);

    ins->setLayout(inslayout);
    ins->show();
    qDebug() << "break6";

}

/*inline void firstwindow::open_ins() {

    QObject::connect(instruc,SIGNAL(clicked()),fwin,SLOT(firstwindow::click_ins()));

}
*/

void firstwindow::click_pla2() {
    check=2;
    qDebug() << "break10";
    nextwidget->show();
    fwin->close();
}

void firstwindow::click_pla1() {
    check=1;
    qDebug() << "break11";
    nextwidget->show();
    fwin->close();
}

firstwindow::~firstwindow() { }


