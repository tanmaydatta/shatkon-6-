#include "controlhex.h"
#include <QDebug>
#include <QBrush>
#include <QMouseEvent>
#include <QCoreApplication>
#include <QWidget>
#include "firstwindow.cpp"
#include "mainalgo.cpp"

int controlhex::pla = 1;
int win = 0;
controlhex *hexagon[8][20];
controlhex::controlhex(int i)
{
    colorstat = i;
    //prog=p;
}

/*void controlhex::setplayer(int i) {
    player=i;
}*/

int controlhex::retcol()
{
    return colorstat;
}

void controlhex::setposit(int x, int y)
{
    posx = x;
    posy = y;
}

//void controlhex::setboardhex(controlhex *tobelinked) {
//    this->link=tobelinked;
//}

void controlhex::setstatuscol(int color)
{
    colorstat = color;
}


int controlhex::move(int i)
{
    cout << "whoiswinnig" << endl;
    Board b;
    for (int i = 0; i < 8; i++)
    {
        for (int j = i % 2; j < 16; j += 2)
        {
            b.arr[i][j] = hexagon[i][j]->colorstat;
        }
    }
    win = whoHasWon(b);
    cout << win << endl;
    return win + 2;
}

int controlhex::move()
{
    cout << "nga" << endl;
    Board b;
    for (int i = 0; i < 8; i++)
    {
        for (int j = i % 2; j < 16; j += 2)
        {
            b.arr[i][j] = hexagon[i][j]->colorstat;
        }
    }

    //    Board b1;
    //    b1.arr[0][0]=2;
    //    b1.arr[1][3]=1;
    //    PlayerMove *p1=new PlayerMove(b1);
    //    p1->generateLeft();
    //    MIND = 10000;
    //    X=-1;Y=-1;
    //    int arr1[20][20]={0};
    //    arr1[0][2]=1;
    //    vector<pair<int,int> >v1=b1.connectedPoints(0,2,2);
    //    dfs(0,2,v1,arr1,b1,2);
    //    cout<<MIND<<" "<<X<<endl;
    //    pair<int,int> p11=closestPair(1,3,1,b1,1);
    //    cout<<p11.first<<" "<<p11.second<<endl;
    PlayerMove *p = new PlayerMove(b);
    root = p;
    tree(11, root, NULL);
    ComputerMove *l, *r;
    l = root->left;
    r = root->right;
    findMaxLeaf(l, NULL);
    int l1 = maxLeaf;
    maxLeaf = 10000;
    int f = 0, f1 = 0;
    findMaxLeaf(r, NULL);
    int r1 = maxLeaf;
    ComputerMove *n;
    if (l1 < r1)
    {
        n = root->left;
        cout << "left" << endl;
        f = 0;
    }
    else
    {
        n = root->right;
        cout << "right" << endl;
        f = 1;
    }
    //    n=root->right;
    if (whoHasWon(root->left->b) == 2)
        n = root->left;
    // if(n1==2)

    int flag = 0;
    int flag1 = 0, flag2 = 0;
    for (int i = 0; i <= 7; i++)
    {
        // for(int j=i%2;j<=15;j+=2)
        // {
        if (b.arr[i][i % 2] == 1)
            flag1++;
        else if (b.arr[i][i % 2] == 2)
            flag2++;

        // }
    }
    if (flag1 > 2 && flag2 < 1)
    {
        for (int i = 0; i <= 7; i++)
        {
            // for(int j=i%2;j<=15;j+=2)
            // {
            if (b.arr[i][i % 2] == 0)
            {
                b.arr[i][i % 2] = 2;
                flag = 1;
                break;
            }
        }
    }
    flag1 = 0; flag2 = 0;
    for (int i = 0; i <= 7; i++)
    {
        // for(int j=i%2;j<=15;j+=2)
        // {
        if (b.arr[i][i % 2 + 14] == 1)
            flag1++;
        else if (b.arr[i][i % 2 + 14] == 2)
            flag2++;

        // }
    }
    if (flag1 > 2 && flag2 < 1)
    {
        for (int i = 0; i <= 7; i++)
        {
            // for(int j=i%2;j<=15;j+=2)
            // {
            if (b.arr[i][i % 2 + 14] == 0)
            {
                b.arr[i][i % 2 + 14] = 2;
                flag = 1;
                break;
            }
        }
    }
    flag1 = 0; flag2 = 0;

    for (int i = 0; i <= 14; i += 2)
    {
        // for(int j=i%2;j<=15;j+=2)
        // {
        if (b.arr[7][i] == 1)
            flag1++;
        else if (b.arr[7][i] == 2)
            flag2++;

        // }
    }
    if (flag1 > 2 && flag2 < 1)
    {
        for (int i = 0; i <= 7; i++)
        {
            // for(int j=i%2;j<=15;j+=2)
            // {
            if (b.arr[7][i] == 0)
            {
                b.arr[7][i] = 2;
                flag = 1;
                break;
            }
        }
    }
    flag1 = 0; flag2 = 0;
    if (!flag)
        b = n->b;
    int xx = 2;
    try
    {
        while (xx--)
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = i % 2; j < 16; j += 2)
                {
                    if (b.arr[i][j] != hexagon[i][j]->colorstat && b.arr[i][j] == 0)
                    {
                        f1 = 1;
                        hexagon[i][j]->setBrush(QBrush(Qt::red));
                        hexagon[i][j]->colorstat = b.arr[i][j];
                    }
                }
                if (f1)
                    break;
            }
            if (f1 == 0)
            {
                if (f == 0)
                    n = root->right;
                else n = root->left;
                b = n->b;
            }
            else break;
        }
        if (xx == 1)
            throw 1;
    }
    catch (int i)
    {
        if (f1 == 0 && i)
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = i % 2; j < 16; j += 2)
                {
                    if (hexagon[i][j]->colorstat == 1)
                    {
                        pair<int, int> p = closestPair(i, j, dir, b, 1);
                        if (p.first > -1)
                        {
                            f1 = 1;
                            hexagon[p.first][p.second]->setBrush(QBrush(Qt::red));
                            hexagon[p.first][p.second]->colorstat = b.arr[i][j];
                            break;
                        }
                        else
                        {
                            pair<int, int> p = closestPair(i, j, dir, b, 3);
                            if (p.first > -1)
                            {
                                f1 = 1;
                                hexagon[p.first][p.second]->setBrush(QBrush(Qt::red));
                                hexagon[p.first][p.second]->colorstat = b.arr[i][j];
                                break;
                            }
                            else
                            {

                            }
                        }

                    }
                }
                if (f1)
                    break;
            }
        }
        if (f1 == 0)
        {
            for (int i = 0; i < 8; i++)
            {
                for (int j = i % 2; j < 16; j += 2)
                {
                    if (hexagon[i][j]->colorstat == 0)
                    {

                        hexagon[p.first][p.second]->setBrush(QBrush(Qt::red));
                        hexagon[p.first][p.second]->colorstat = b.arr[i][j];
                        f1 = 1;
                        break;
                    }
                }

                if (f1)

                    break;
            }
        }

    }




    //if(controlhex::count>14)
    win = whoHasWon(b);
    cout << win << endl;
    deleteTree(NULL, root);
    return win;
}



void controlhex::focusInEvent(QFocusEvent *)
{
    qDebug() << this->toolTip() << Q_FUNC_INFO;


    cout << check << endl;
    if (check == 2)
    {
        if (controlhex::pla == 2)
        {
            if (this->colorstat == 0)
            {
                this->setBrush(QBrush(Qt::red));
                this->setstatuscol(2);
                //                move(1);
                if (move(1) == 4)
                {
                    won tellwon(4);
                }
            }
            controlhex::pla = 1;

        }
        else
        {
            if (this->colorstat == 0)
            {
                this->setBrush(QBrush(Qt::blue));
                this->setstatuscol(1);
                move(1);
                if (move(1) == 3)
                {
                    won tellwon(3);
                }
            }
            controlhex::pla = 2;

        }
    }
    else
    {
        if (this->colorstat == 0)
        {
            this->setBrush(QBrush(Qt::blue));
            this->setstatuscol(1);
            int a;
        }
    }
}

void controlhex::focusOutEvent(QFocusEvent *)
{
    int a;
    qDebug() << this->toolTip() << Q_FUNC_INFO;
    if (check == 1)
    {
        a = move();
        if (a == 1)
        {
            won tellwon(1);
        }
        else if (a == 2)
        {
            won tellwon(2);
        }
    }
}


void controlhex::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    //    qDebug() << this->toolTip() << Q_FUNC_INFO;
    //    if (this->colorstat==0)
    //        this->setBrush(QBrush(Qt::gray));
}

void controlhex::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    //    qDebug() << this->toolTip() << Q_FUNC_INFO;
    //    if (this->colorstat==0)
    //        this->setBrush(QBrush());
}

void controlhex::hoverMoveEvent(QGraphicsSceneHoverEvent *)
{
    //    qDebug() << this->toolTip() << Q_FUNC_INFO;
}
