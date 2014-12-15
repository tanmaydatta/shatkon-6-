#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsItem>
#include <QCoreApplication>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    void makeDraggable(QGraphicsItem *);
    void addfunctionality(QApplication *);
    ~Widget();
};

#endif // WIDGET_H
