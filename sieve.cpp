#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
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

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    std::ios_base::sync_with_stdio(0);
    int n, i, k, m;

    cin >> n;

    sieve(n);

    for(i = 0; i < sz; i++) cout << primes[i] << "\n";

    return 0;
}
