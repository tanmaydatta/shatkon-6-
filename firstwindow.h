#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
#include <QObject>
#include <QDebug>
#include "won.h"


class firstwindow : QWidget {
    Q_OBJECT
private:
    QPushButton *player1;
    QPushButton *player2;
    QPushButton *instruc;
    QApplication *prog;
    QWidget *fwin;
    QWidget *nextwidget;

public:
    firstwindow(QWidget *,QApplication *);
//    firstwindow(QApplication *);
//    inline void open_ins();
    virtual ~firstwindow();
   // friend void winappret(firstwindow &,won &);

public slots:
    void click_ins();
    void click_pla1();
    void click_pla2();
};


#endif // FIRSTWINDOW_H
