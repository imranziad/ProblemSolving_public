#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define LL long long
#define MAX 100005

int primes[MAX], sz;

void sieve(int n)
{
    int i, k, sqrtN, status[500005];

    for(i=2; i<=n>>1; i++) status[i] = 0;

    sqrtN = (int)sqrt( (double)n );

    for(i=3; i<=sqrtN; i+=2)
    {
        if(status[i>>1]==0)
        {
            for(k=i*i; k<=n; k+=i+i)
                status[k>>1] = 1;
        }
    }

    sz = 0;

    primes[sz++] = 2;

    for(i=3; i<=n; i+=2)
    {
        if(status[i>>1]==0)
            primes[sz++] = i;
    }
}

int divs(LL n)
{
    int i = 0;
    LL ret=1, cnt;
    LL sqrtN = sqrt(n);

    while(i < sz && primes[i] <= sqrtN && n > 1)
    {
        cnt = 0;
        while(n > 1 && n % primes[i] == 0)
        {
            n /= primes[i];
            cnt++;
        }

        ret *= (cnt+1);
        i++;
    }

    if(n > 1) ret *= 2;

    return ret;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    int n, i, k, m;

    cin >> n;

    sieve(100);

    return 0;
}
