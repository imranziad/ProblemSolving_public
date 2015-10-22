#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define LL long long
#define MOD 1000000007

LL bigmod(LL n, LL p, int m)
{
    if(p == 0) return 1;
    if(p == 1 || n == 1) return n % m;

    LL ret = bigmod(n, p/2, m);
    ret = (ret * ret) % m;
    if(p % 2) ret = (ret * n) % m;
    return ret%m;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    std::ios_base::sync_with_stdio(0);
    int n, i, k, m;

    cin >> n >> k;

    cout << bigmod(n, k, MOD);

    return 0;
}

