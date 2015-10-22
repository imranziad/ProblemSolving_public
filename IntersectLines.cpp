#include <bits/stdc++.h>
using namespace std;

struct Point{
    double x,y;
};
double direction(Point p0, Point p1, Point p2){
    double x1 = p1.x - p0.x;
    double x2 = p2.x - p0.x;
    double y1 = p1.y - p0.y;
    double y2 = p2.y - p0.y;
    return (x1*y2)-(x2*y1);
}
bool coliner(Point p1, Point p2, Point p0){
    return ( min(p1.x,p2.x) <= p0.x && p0.x <= max(p1.x,p2.x) && min(p1.y,p2.y) <= p0.y && p0.y <= max(p1.y,p2.y) );
}
bool Intersect(Point p1,Point p2,Point p3,Point p4){
    double d1 = direction(p1,p2,p3);
    double d2 = direction(p1,p2,p4);
    double d3 = direction(p3,p4,p1);
    double d4 = direction(p3,p4,p2);
    if( ((d1>0 && 0>d2) || (d1<0 && 0<d2)) && ((d3>0 && 0>d4) || (d3<0 && 0<d4)) )
        return true;
    else if(d1==0 && coliner(p1,p2,p3)) return true;
    else if(d2==0 && coliner(p1,p2,p4)) return true;
    else if(d3==0 && coliner(p3,p4,p1)) return true;
    else if(d4==0 && coliner(p3,p4,p2)) return true;
    else false;
}

int main(){
    Point p1,p2,p3,p4;

    cout << "P1 (x,y) : ";
    cin >> p1.x >> p1.y;

    cout << "P2 (x,y) : ";
    cin >> p2.x >> p2.y;

    cout << "P3 (x,y) : ";
    cin >> p3.x >> p3.y;

    cout << "P4 (x,y) : ";
    cin >> p4.x >> p4.y;

    if(Intersect(p1,p2,p3,p4))
        cout << "P1P2 & P3P4 lines intersect." << endl;
    else
        cout << "P1P2 & P3P4 lines do not intersect." << endl;

    return 0;
}
