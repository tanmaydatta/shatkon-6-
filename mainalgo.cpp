#include <cmath>
#include <stdio.h>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cassert>
using namespace std;


// 0 = empty cell
// 1 = player's piece
// 2 = computer's piece


int MIND=10000;
pair<int,int> P;
int X,Y;
int dir;
int array[4]={10000,10000,10000,10000};
queue<pair<pair<int,int>,int> >Q;

class Board;
void bfs(int x,int y,int visited[20][20],Board b,int c);
void isConnectedToEdge(int x,int y,int arr[20][20],Board b);
class Board
{
public:
    int arr[20][20];

    Board()
    {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
                arr[i][j] = 0;
        }
    }
    int check(int x,int y)
    {
        if(arr[x][y+2]==0||arr[x][y-2]==0||arr[x-2][y-2]==0||arr[x-2][y+2]==0||arr[x+2][y-2]==0||arr[x+2][y+2]==0)
            return 1;
        return 0;
    }
    vector<pair<int,int> > connectedPoints(int x,int y,int z)
    {
        vector<pair<int,int> > v,v1;
//        int flag=0;
        int x1,y1;
        x1=x;y1=y+2;
        if(x1<=7&&x1>=0&&y1>=0&&y1<=15&&arr[x1][y1]==z)
                v.push_back(make_pair(x1,y1));
        x1=x;y1=y-2;
        if(x1<=7&&x1>=0&&y1>=0&&y1<=15&&arr[x1][y1]==z)
            v.push_back(make_pair(x1,y1));
        if(x!=0&&x!=7) {
            if(x%2==0) {
            x1=x+1;y1=y+3;
            if(x1<=7&&x1>=0&&y1>=0&&y1<=15&&arr[x1][y1]==z)
                v.push_back(make_pair(x1,y1));
            }
            else
            {
                x1=x+1;y1=y-1;
                if(x1<=7&&x1>=0&&y1>=0&&y1<=15&&arr[x1][y1]==z)
                    v.push_back(make_pair(x1,y1));
            }
            x1=x+1;y1=y+1;
            if(x1<=7&&x1>=0&&y1>=0&&y1<=15&&arr[x1][y1]==z)
                v.push_back(make_pair(x1,y1));
            if(x%2==0){
                x1=x-1;y1=y+1;
                if(x1<=7&&x1>=0&&y1>=0&&y1<=15&&arr[x1][y1]==z)
                    v.push_back(make_pair(x1,y1));
            }
            else
            {
                x1=x-1;y1=y-3;
                if(x1<=7&&x1>=0&&y1>=0&&y1<=15&&arr[x1][y1]==z)
                    v.push_back(make_pair(x1,y1));
            }
            x1=x-1;y1=y-1;
            if(x1<=7&&x1>=0&&y1>=0&&y1<=15&&arr[x1][y1]==z)
                v.push_back(make_pair(x1,y1));
        }
        else if(x==0||x==7)
        {
            if(x!=7) {
                x1=x+1;y1=y+1;
                if(x1<=7&&x1>=0&&y1>=0&&y1<=15&&arr[x1][y1]==z)
                    v.push_back(make_pair(x1,y1));
                x1=x+1;y1=y+3;
                if(x1<=7&&x1>=0&&y1>=0&&y1<=15&&arr[x1][y1]==z)
                    v.push_back(make_pair(x1,y1));
            }
            else if(x==7&&y==1)
            {
                x1=x-1;y1=y-1;
                if(x1<=7&&x1>=0&&y1>=0&&y1<=15&&arr[x1][y1]==z)
                    v.push_back(make_pair(x1,y1));
            }
            else if(x==7&&y!=1)
            {
                x1=x-1;y1=y-1;
                if(x1<=7&&x1>=0&&y1>=0&&y1<=15&&arr[x1][y1]==z)
                    v.push_back(make_pair(x1,y1));
                x1=x-1;y1=y-3;
                if(x1<=7&&x1>=0&&y1>=0&&y1<=15&&arr[x1][y1]==z)
                    v.push_back(make_pair(x1,y1));
            }
        }

        // if(v.size())
        // cout<<"from func"<<v.size()<<endl;
        return v;
    }

    vector <int> closestEdgeDistance(int x,int y,Board b)
    {
        vector<int> v;
        int a[20][20]={0};
        array[0]=array[1]=array[2]=array[3]=10000;
        while (!Q.empty())
        {
            Q.pop();
        }
        Q.push(make_pair(make_pair(x,y),0));
        isConnectedToEdge(x,y,a,b);
        bfs(x,y,a,b,0);
        v.push_back(array[0]);
        v.push_back(array[1]);
        v.push_back(array[2]);
        v.push_back(array[3]);
        // v.push_back(x);
        // v.push_back(y);
        // v.push_back((7-x)/2);
        // v.push_back((15-y)/2);
        return v;
    }
    int isConnected(int x1,int y1,int x2,int y2,int a[20][20]);

};
void isConnectedToEdge(int x,int y,int arr[20][20],Board b)
{
    if(x==0)
        array[0]=0;
    if(x==7)
        array[2]=0;
    if(y==0||y==1)
        array[1]=0;
    if(y==14||y==15)
        array[3]=0;
    vector<pair<int,int> > v=b.connectedPoints(x,y,b.arr[x][y]);
    arr[x][y]=1;
    for(int i=0;i<v.size();i++)
    {
        if(arr[v[i].first][v[i].second]==0)
        {
            isConnectedToEdge(v[i].first,v[i].second,arr,b);
        }
    }
}

void dfs(int x,int y, vector<pair<int,int> > vec,int a[20][20],Board b,int z)
{
    int i, j;
    a[x][y] = 1;
    // i = v;
    if(b.check(x,y))
    {
        // if(z==2){
        // cout<<"yes from check\n";
        // cout<<vec.size()<<endl;}
        for (j = 0; j < vec.size(); j++)
        {
            if(vec[j].first>=0&&vec[j].first<=7&&vec[j].second<=15&&vec[j].second>=0) {
                if (a[vec[j].first][vec[j].second] == 0)
                {
//                    cout<<vec[j].first<<" "<<vec[j].second<<endl;
                    vector <int> v1,v2;
                    v1=b.closestEdgeDistance(x,y,b);
                    v2=b.closestEdgeDistance(vec[j].first,vec[j].second,b);
                    int temp=10000;
                    for(i=0;i<4;i++)
                    {
                        for(int k=0;k<4;k++)
                        {
                            if(i==z||(i+z)%2==0) {
                                if(i!=k&&((i+k)%2==0))
                                {
                                    if(v1.size()==4&&v2.size()==4)
                                    temp=v1[i]+v2[k];
                                    // if(vec[j].first==0||vec[j].first==7||vec[j].second==15||vec[j].second==0||vec[j].second==14)
                                    // 	temp=0;
                                    if(temp<=MIND)
                                    {
                                        // cout<<"kwhbcjvwekckwebvcjkvwerjcv";
                                        MIND=temp;
                                        // P=make_pair(x,y);
                                        X=vec[j].first;Y=vec[j].second;
                                        dir=k;
                                    }
                                }
                            }
                        }
                    }
                    vector<pair<int,int> > v = b.connectedPoints(vec[j].first,vec[j].second,z);
                    dfs(vec[j].first,vec[j].second,v, a,b,z);
                }
            }
        }
    }
}

void bfs(int x,int y,int visited[20][20],Board b,int c)
{
    int i;
    visited[x][y] = 1;  //node has been visited
    pair<pair<int,int>,int> p=Q.front();
    if(x==0)
        array[0]=min(p.second,array[0]);
    if(x==7)
        array[2]=min(p.second,array[2]);;
    if(y==0||y==1)
        array[1]=min(p.second,array[1]);
    if(y==14||y==15)
        array[3]=min(p.second,array[3]);
    // if(array[0]!=10000&&array[1]!=10000&&array[2]!=10000&&array[3]!=10000)
    // 	return ;
    vector<pair<int,int> > v=b.connectedPoints(x,y,0),v1=b.connectedPoints(x,y,b.arr[x][y]);
    for(i=0;i<v1.size();i++)
        v.push_back(v1[i]);
    // cout<<v.size()<<endl;
    int f=0;
    if (Q.empty() == false) //queue is not empty
        for (i = 0; i < v.size(); i++)
            if (visited[v[i].first][v[i].second] == 0) //vertex i in the edge list of vertex node is unvisited
            {
                f++;
                if(b.arr[v[i].first][v[i].second]==0)
                Q.push(make_pair(make_pair(v[i].first,v[i].second),p.second+1));
                else
                    Q.push(make_pair(make_pair(v[i].first,v[i].second),p.second));
                visited[v[i].first][v[i].second] = 1;
            }
    Q.pop();
    if (Q.empty() == false) {
        pair<pair<int,int>,int> p=Q.front();
        // for(i=0;i<f;i++)
        if(b.arr[p.first.first][p.first.second]==0)
        bfs(p.first.first,p.first.second,visited,b,c+1); //run bfs from the next vertex
        else bfs(p.first.first,p.first.second,visited,b,c);
    }
}

class ComputerMove;
class PlayerMove
{
    public:
    Board b;

    ComputerMove *left,*right;
    PlayerMove(Board B)
    {
        b=B;
        left=right=NULL;
    }
    ComputerMove* newNode(Board,char);
    void generateLeft();
    void generateRight();
};

class ComputerMove
{
    public:
    Board b;
    char type;

    PlayerMove *child;

    ComputerMove(Board B,char t)
    {
        b=B;
        type=t;
        child=NULL;
    }
    PlayerMove* newNode(Board b)
    {
      PlayerMove* node = new PlayerMove(b);
      return(node);
    }
    void generateChild();
};

ComputerMove* PlayerMove::newNode(Board b,char type)
{
  ComputerMove* node = new ComputerMove(b,type);
  return(node);
}

pair<int,pair<int,int> > edgeDistance(int x,int y,int d,Board b,int visited[20][20],int c)
{
    int i;
    visited[x][y] = 1;  //node has been visited
    pair<pair<int,int>,int> p=Q.front();
    if(d==0&&x==0)
        return make_pair(p.second,make_pair(x,y));
    if(d==1&&y==0)
        return make_pair(p.second,make_pair(x,y));
    if(d==1&&y==1)
        return make_pair(p.second,make_pair(x,y));
    if(d==2&&x==7)
        return make_pair(p.second,make_pair(x,y));
    if(d==3&&y==14)
        return make_pair(p.second,make_pair(x,y));
    if(d==3&&y==15)
        return make_pair(p.second,make_pair(x,y));
    vector<pair<int,int> > v=b.connectedPoints(x,y,0);
    if(d==1||d==3)
    {
        vector<pair<int,int> > v1=b.connectedPoints(x,y,1);
        for(i=0;i<v1.size();i++)
        {
            int arr[20][20]={0};
            arr[v1[i].first][v1[i].second]=1;
            array[0]=array[1]=array[2]=array[3]=10000;
            isConnectedToEdge(v1[i].first,v1[i].second,arr,b);
            if(d==1&&array[1]==0)
                return make_pair(p.second,make_pair(x,y));
            if(d==3&&array[3    ]==0)
                return make_pair(p.second,make_pair(x,y));
        }
    }
    if (Q.empty() == false) //queue is not empty
        for (i = 0; i < v.size(); i++)
            if (visited[v[i].first][v[i].second] == 0) //vertex i in the edge list of vertex node is unvisited
            {
                Q.push(make_pair(make_pair(v[i].first,v[i].second),p.second+1));
                visited[v[i].first][v[i].second] = 1;
            }

    if(!Q.empty())
    Q.pop();
    if (Q.empty() == false) {
        pair<pair<int,int>,int> p=Q.front();
        return edgeDistance(p.first.first,p.first.second,d,b,visited,c+1); //run bfs from the next vertex
    }
    return make_pair(10000,make_pair(x,y));
}

pair<int,int> closestPair(int x,int y,int d,Board b,int z)
{
    vector<pair<int,int> >v=b.connectedPoints(x,y,0);
    int m=10000;
    pair <int,int> p;
    // cout<<v.size()<<"pairf"<<endl;
    for(int i=0;i<v.size();i++)
    {
        while (!Q.empty())
        {
            Q.pop();
        }

        int a[20][20]={0};
        Q.push(make_pair(make_pair(v[i].first,v[i].second),0));
        pair<int,pair<int,int> > temp = edgeDistance(v[i].first,v[i].second,d,b,a,0);
        //cout<<v[i].first<<" "<<v[i].second<<" "<<temp<<"pair"<<endl;
        if(temp.first<m)
        {
            m=temp.first;
            if(z==1)
            p=make_pair(temp.second.first,temp.second.second);
            else p=make_pair(v[i].first,v[i].second);
        }
    }
    if(m==10000)
        p=make_pair(-1,-1);
    // else
        // p=make_pair(p.first,p.second);
    return p;
}

void PlayerMove::generateLeft()
{
    int x=-1,y=-1,mind=10000,d=-1;
    pair<int,int> p;
    dir=-1;
    int arr[20][20]={0};
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            if(b.arr[i][j]==2)
            {

                MIND = 10000;
                X=-1;Y=-1;
                arr[i][j]=1;
                vector<pair<int,int> >v=b.connectedPoints(i,j,2);
                //cout<<"left"<<v.size()<<endl;;;
                if(v.size())
                {
                    dfs(i,j,v,arr,b,2);
                    if(MIND<mind&&X>-1)
                    {
                        p=closestPair(X,Y,dir,b,2);
                        if(p.first>-1) {
                            d=dir;
                            mind=MIND;
                            x=X;y=Y;
                        }
                    }
                }
                else
                {
                    vector <int> v1;
                    v1=b.closestEdgeDistance(i,j,b);
                    int temp=v1[0]+v1[2];
                    if(temp<MIND)
                    {
                        MIND=temp;
                        mind=temp;
                        if(x!=7)
                        d=dir=2;
                        else d=dir=0;
                        p=closestPair(i,j,dir,b,2);
                    }
                }
                MIND = 10000;
            }
        }
    }
    if(d==0||d==2) {
        //cout<<"left found"<<endl;
        Board B=b;
        B.arr[p.first][p.second]=2;
        left = newNode(B,'o');
//        cout<<mind<<" "<<x<<" "<<y<<endl;
    }
    else {
        Board B=b;
        int f=0;
        for(int i=0;i<=7;i++)
        {
            for(int j=i%2;j<=15;j+=2)
            {
                if(b.arr[i][j]==0) {
                    B.arr[i][j]=2;
                    f=1;
                    break;
                }
            }
            if(f)
                break;
        }
        left = newNode(B,'o');
    }
}

void PlayerMove::generateRight()
{
    int x=-1,y=-1,mind=10000,d=-1;
    pair<int,int> p;
    dir=-1;
    int arr[20][20]={0};
    MIND = 10000;
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            if(b.arr[i][j]==1)
            {
                arr[i][j]=1;
                X=-1;Y=-1;
                //cout<<"right"<<endl;;;
                vector<pair<int,int> >v=b.connectedPoints(i,j,1);
                if(v.size())
                {
                    dfs(i,j,v,arr,b,1);
                    if(MIND<mind&&X>-1)
                    {
    //                    cout<<"yes\n"<<X<<" "<<Y<<" "<<dir<<endl;
                        p=closestPair(X,Y,dir,b,1);
    //                    cout<<"yesPair\n"<<p.first<<" "<<p.second<<endl;
                        if(p.first>-1) {
                            d=dir;
                            mind=MIND;
                        }
                        // cout<<"yes"<<endl;
                    }
                }
                else
                {
                    vector <int> v1;
                    v1=b.closestEdgeDistance(i,j,b);
                    int temp=v1[1]+v1[3];
                    if(temp<MIND)
                    {
                        MIND=temp;
                        mind=temp;
                        if(j<14)
                        d=dir=3;
                        else d=dir=1;
                        p=closestPair(i,j,dir,b,1);
                    }
                }
                 MIND = 10000;
            }
        }
    }
    // cout<<"left"<<endl;;;
    if(d>-1) {

        Board B=b;
        B.arr[p.first][p.second]=2;
        right = newNode(B,'d');
//        if(right){}
//            cout<<"right found"<<mind<<endl;
    }
    else {
        Board B=b;
        int f=0;
        for(int i=0;i<=7;i++)
        {
            for(int j=0;j<=15;j+=2)
            {
                if(b.arr[i][j]==0) {
                    B.arr[i][j]=2;
                    f=1;
                    break;
                }
            }
            if(f)
                break;
        }
        right = newNode(B,'d');
    }
}

void ComputerMove::generateChild()
{
    int x=-1,y=-1,mind=10000,d=-1;
    pair<int,int> p;
    dir=-1;
    // for(int i=0;i<16;i++)
    // {
    // 	for(int j=0;j<16;j++)
    // 	{
    // 		if(b.arr[i][j]==2)
    // 		{
    // 			int arr[20][20]={0};
    // 			MIND = 10000;
    // 			X=-1;Y=-1;
    // 			vector<pair<int,int> >v=b.connectedPoints(i,j,2);
    // 			// cout<<"left"<<v.size()<<endl;;;
    // 			dfs(i,j,v,arr,b,2);
    // 			// cout<<"yes\n";
    // 			if(MIND<mind)
    // 			{
    // 				p=closestPair(X,Y,dir,b);
    // 				if(p.first>-1) {
    // 					d=dir;
    // 					mind=MIND;
    // 				}
    // 			}
    // 			MIND = 10000;
    // 		}
    // 	}
    // }
    // cout<<"yes\n";
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<16;j++)
        {
            if(b.arr[i][j]==1)
            {
                int arr[20][20]={0};
                MIND = 10000;
                X=-1;Y=-1;
                vector<pair<int,int> >v=b.connectedPoints(i,j,1);
                // cout<<"left"<<v.size()<<endl;;;
                dfs(i,j,v,arr,b,1);
                // cout<<"yes\n";
                if(MIND<mind)
                {
                    p=closestPair(X,Y,dir,b,2);
                    if(p.first>-1) {
                        d=dir;
                        mind=MIND;
                    }
                }
                MIND = 10000;
            }
        }
    }
    if(d>-1) {
//        cout<<"child found"<<endl;
        Board B=b;
        B.arr[p.first][p.second]=1;
        child = newNode(B);
    }
    else {
        Board B=b;
        int f=0;
        for(int i=0;i<=7;i++)
        {
            for(int j=0;j<=15;j+=2)
            {
                if(b.arr[i][j]==1) {
                    vector<pair<int,int> >v=b.connectedPoints(i,j,0);
                    if(v.size())
                    {
                        B.arr[v[0].first][v[0].second]=1;
                        f=1;
                        break;
                    }
                }
                else if(b.arr[i][j]==0) {
                    B.arr[i][j]=1;
                    f=1;
                    break;
                }
            }
            if(f)
                break;
        }
        child = newNode(B);
    }
}

PlayerMove * root;
void tree(int n,PlayerMove *node1,ComputerMove *node2)
{
//    cout<<n<<endl;
    if(n==0)
        return ;
    if(node1)
    {
        // cout<<n<<endl;
        node1->generateLeft();
        node1->generateRight();
        if(node1->left&&node1->right) {
        // if(1) {
            // cout<<"yes"<<endl;
            tree(n-1,NULL,node1->left);
            tree(n-1,NULL,node1->right);
        }
        else// cout<<"no\n";
        {}
    }
    else if(node2)
    {
        node2->generateChild();
        // if(n==10)
        // 	cout<<"yes from child\n";
        if(node2->child) {
            // cout<<"yes from child\n";
            tree(n-1,node2->child,NULL);
        }
    }
}

int Board::isConnected(int x1,int y1,int x2,int y2,int a[20][20])
{
    a[x1][y1]=1;
    if(x1==x2&&y1==y2)
        return 1;
    vector <pair<int,int> > vec=connectedPoints(x1,y1,2);
    for (int j = 0; j < vec.size(); j++)
        //if(a[v][i] && !vec[v][j])
        if (!a[vec[j].first][vec[j].second])
        {
            return isConnected(vec[j].first,vec[j].second, x2,y2,a);
        }
    // if(vec.size()==0)
    return 0;
}

int assignScoreToLeaf(Board b)
{
    int arr[20][20]={0};
    int m=10000;
    for(int i=0;i<=16;i++)
    {
        for(int j=0;j<=16;j++)
        {
            if(b.arr[i][j]==2)
            {
                for(int k=0;k<=16;k++)
                {
                    for(int l=0;l<=16;l++)
                    {
                        if(i==k&&j==l)
                            continue;
                        else
                        {
                            int a[20][20]={0};
                            if(b.isConnected(i,j,k,l,a))
                            {
                                int temp;
                                vector<int> v1,v2;
                                v1=b.closestEdgeDistance(i,j,b);
                                v2=b.closestEdgeDistance(k,l,b);
                                for(int i1=0;i1<4;i1++)
                                {
                                    for(int k1=0;k1<4;k1++)
                                    {
                                        if(i1!=k1&&((i1+k1)%2==0))
                                        {
                                            temp=v1[i1]+v2[k1];
                                            if(temp<m)
                                            {
                                                m=temp;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return m;
}

int maxLeaf = 10000;

void findMaxLeaf(ComputerMove * n1,PlayerMove *n2)
{
    if(n1)
    {
        if(n1->child)
            findMaxLeaf(NULL,n1->child);
        else
        {
            int temp = assignScoreToLeaf(n1->b);
            maxLeaf= min(maxLeaf,temp);
        }
    }
    else if(n2)
    {
        findMaxLeaf(n2->left,NULL);
        findMaxLeaf(n2->right,NULL);
    }
}

Board copy(ComputerMove *n)
{
    Board b;
    for(int i=0;i<=16;i++)
    {
        for(int j=0;j<=16;j++)
        {
            b.arr[i][j]=(n->b).arr[i][j];
        }
    }
    return b;
}

void deleteTree(ComputerMove * c,PlayerMove *p)
{
    if(p)
    {
        if(p->left)
        {
            deleteTree(p->left,NULL);
            deleteTree(p->right,NULL);
        }
        else
            delete p;
    }
    else if(c)
    {
        if(c->child)
        {
            deleteTree(NULL,c->child);
        }
        else delete c;
    }
}

int whoHasWon(Board b)
{
    for(int i=0;i<15;i+=2)
    {
        for(int j=1;j<=15;j+=2)
        {
            if(b.arr[0][i]==2&&b.arr[7][j]==2)
            {
                int a[20][20]={0};
                if(b.isConnected(0,i,7,j,a))
                    return 2;
            }
        }
    }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(b.arr[i][i%2]==1&&b.arr[j][14+(j%2)]==1)
            {
                int a[20][20]={0};
                if(b.isConnected(i,i%2,j,14+(j%2),a))
                    return 1;
            }
        }
    }
    return 0;
}
