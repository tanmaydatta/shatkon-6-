#ifndef CONTROLHEX_H
#define CONTROLHEX_H
#include <boardhexagon.h>
#include <QGraphicsPolygonItem>


class controlhex {
    BoardHexagon *link;
    int posx;
    int posy;
    int colorstat;

public:
    static void setpos(int x,int y);
    static void setboard(BoardHexagon);
    static void setstatus(int color);
};

static void controlhex::setpos(int x,int y) {
    posx=x;
    posy=y;
}

static void controlhex::setboard(BoardHexagon *tobelinked) {
    this->link=tobelinked;
}

static void controlhex::setstatus(int color) {
    colorstat=color;
}

#endif // CONTROLHEX_H
