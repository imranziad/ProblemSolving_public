#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define MAX 1000000
#define LMT 1000

unsigned flag[MAX>>6];

#define ifc(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define isc(n) (flag[n>>6]|=(1<<((n>>1)&31)))

void sieve() {
    unsigned i, j, k;
    for(i=3; i<LMT; i+=2)
        if(!ifc(i))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                isc(j);
}

int main()
{
    sieve();

    for(int i=3; i<MAX; i+=2)
        if(!ifc(i))
            printf("%d\n", i);

    return 0;
}
