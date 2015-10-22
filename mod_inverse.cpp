#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define LL long long
#define MOD 1000003

LL mod_inv(LL a, LL b)
{
	LL b0 = b, t, q;
	LL x0 = 0, x1 = 1;
	if(b == 1) return 1;
	while(a > 1)
    {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if(x1 < 0) x1 += b0;
	return x1;
}

// For fermat's theorem below
LL bigmod(LL n, LL p, int m)
{
    if(p == 0) return 1;
    if(p == 1 || n == 1) return n % m;

    LL ret = bigmod(n, p/2, m);
    ret = (ret * ret) % m;
    if(p % 2) ret = (ret * n) % m;
    return ret%m;
}
// Farmat's rule requires b to be prime
LL mod_inverse(LL a, LL b)
{
    return bigmod(a, b-2, b);
}

int main()
{
    int cases, caseno=0;
    LL N, i, K, ans;

    cout << mod_inverse(10000, MOD);

    return 0;
}

