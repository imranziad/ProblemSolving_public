#include <bits/stdc++.h>
using namespace std;

struct Point{
    double x,y;
};

void pointDerection(Point p0, Point p1, Point p2){
    double x1 = p1.x - p0.x;
    double x2 = p2.x - p0.x;
    double y1 = p1.y - p0.y;
    double y2 = p2.y - p0.y;
    double d = (x1*y2)-(x2*y1);
    if( d > 0 )
        cout << "P1 is clockwise (CW) to P2" << endl;
    else if( d < 0 )
        cout << "P1 is counter-clockwise (CCW) to P2" << endl;
    else
        cout << "P1 and P2 are co-liner" << endl;
}

int main(){
    Point p0, p1, p2;

    cout << "P0 (x,y) : ";
    cin >> p0.x >> p0.y;

    cout << "P1 (x,y) : ";
    cin >> p1.x >> p1.y;

    cout << "P2 (x,y) : ";
    cin >> p2.x >> p2.y;

    pointDerection(p0,p1,p2);

    return 0;
}
