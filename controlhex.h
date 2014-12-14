#ifndef CONTROLHEX_H
#define CONTROLHEX_H
#include "boardhexagon.h"
#include <utility>
using namespace std;
class controlhex: public BoardHexagon {
//    BoardHexagon *link;

    int posx;
    int posy;
    int colorstat;


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
    void move();
};



#endif // CONTROLHEX_H
