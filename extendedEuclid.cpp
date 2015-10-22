#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
#define xx first
#define yy second

pii extendedEuclid(int a, int b)
{
    if(b == 0) return pii(1,0);
    else
    {
        pii d = extendedEuclid(b, a%b);
        return pii(d.yy, d.xx - d.yy  * (a/b));
    }
}

int main()
{
    pii p = extendedEuclid(21,13);
    cout << p.xx << " " << p.yy << endl;


    return 0;
}
