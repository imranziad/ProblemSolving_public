#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define LL long long
#define pb push_back
#define xx first
#define yy second

LL ncr[1000002][2];

LL nCr(int n, int r)
{
    if(r == n || r == 0)
        return 1;
    if(r == 1)
        return n;

    if(ncr[n][r] != -1)
        return ncr[n][r];

    return (ncr[n][r] = (nCr(n-1, r) + nCr(n-1, r-1)));
}

int main()
{
    memset(ncr,-1,sizeof(ncr));
    cout << nCr(6, 2);
}
