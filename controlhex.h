#ifndef CONTROLHEX_H
#define CONTROLHEX_H
#include "boardhexagon.h"


class controlhex: public BoardHexagon {
//    BoardHexagon *link;

    int posx;
    int posy;
    int colorstat;
   // QApplication *prog;

public:
    controlhex(int i);
    static int pla;
    int retcol();
    void setposit(int x,int y);
    void setstatuscol(int color);
    void focusInEvent(QFocusEvent*);
    void focusOutEvent(QFocusEvent*);
    void hoverEnterEvent(QGraphicsSceneHoverEvent*);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent*);
    void hoverMoveEvent(QGraphicsSceneHoverEvent*);
    int move();
    int move(int i);
};



#endif // CONTROLHEX_H
