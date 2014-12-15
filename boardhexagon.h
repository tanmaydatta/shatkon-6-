#ifndef BOARDHEXAGON_H
#define BOARDHEXAGON_H

#include <QGraphicsPolygonItem>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneDragDropEvent>
#include <QFocusEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>

class BoardHexagon : public QGraphicsPolygonItem
{
public:
    BoardHexagon(QGraphicsItem *parent = 0);
    virtual ~BoardHexagon();
    virtual void focusInEvent(QFocusEvent*)=0;
    virtual void focusOutEvent(QFocusEvent*)=0;
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent*)=0;
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent*)=0;
    virtual void hoverMoveEvent(QGraphicsSceneHoverEvent*)=0;

};

#endif // BOARDHEXAGON_H
