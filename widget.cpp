#include "widget.h"
#include <QGraphicsView>
#include "graphicsscene.h"
#include <QHBoxLayout>
#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <qmath.h>
#include "boardhexagon.h"
#include "controlhex.h"
#include "controlhex.cpp"
#include <QPushButton>
//using namespace MainAlgo;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout * hbox = new QHBoxLayout;
    QGraphicsView * view = new QGraphicsView;
    GraphicsScene * scene = new GraphicsScene;

//    controlhex control[8][8];

    QPolygonF polygon;
    qreal side = 30;
    qreal dx = qSqrt(3)/2 * side;
    polygon
            // standing on a point
            << QPointF(dx, -side/2)
            << QPointF(0, -side)
            << QPointF(-dx, -side/2)
            << QPointF(-dx, side/2)
            << QPointF(0, side)
            << QPointF(dx, side/2);

    //================================================================================

    int h = 8;
    int w = 22;
    int j = 0;

//    int px=1;
//    int py=1;



    for(int r = 0; r < h; r++)
        {
            j=r%2;
            for(int c = 0; c < w; c++)
            {
                if((r%2==c%2)||(r+c)<7||(r+c)>21)
                {
                    // don't add a hexagon, it isn't on the board!
                }
                else
                {
//                    controlhex * hexagon = new controlhex(0);
                    hexagon[r][j] = new controlhex(0);
                    hexagon[r][j]->setPolygon(polygon);
                    scene->addItem(hexagon[r][j]);
                    hexagon[r][j]->setposit(r,j);
                    hexagon[r][j]->setPos(dx * c, side * 1.5 * r);
                    hexagon[r][j]->setToolTip(QString::number(r) + "," + QString::number(j));// + "," + QString::number(hexagon[r][j]->retcol()) );//+ "," + hexagon[r][j]->pla);
                    hexagon[r][j]->setstatuscol(0);
                    j=j+2;
//                    hexagon[r][j]->setposit(r,j);

//                    control[px][py].setboardhex(hexagon);
//                    control[px][py].setposit(px,py);
//                    control[px][py].setstatuscol(0);
//                    py++;
                }
            }
//            px++;
        }
        hexagon[0][0]->setBrush(QBrush(Qt::red));
        hexagon[0][0]->setstatuscol(2);

    //================================================================================




    view->setRenderHint(QPainter::Antialiasing);
    view->setScene(scene);

    view->setMouseTracking(true);

    hbox->addWidget(view);
    this->setLayout(hbox);
    this->resize(900, 500);


   // hbox
}

//void Widget::makeDraggable(QGraphicsItem *item)
//{
//    item->setFlag(QGraphicsItem::ItemIsSelectable);
//    item->setFlag(QGraphicsItem::ItemIsMovable);
//    item->setFlag(QGraphicsItem::ItemSendsGeometryChanges);
//    item->setFlag(QGraphicsItem::ItemSendsScenePositionChanges);
//}

Widget::~Widget()
{

}
