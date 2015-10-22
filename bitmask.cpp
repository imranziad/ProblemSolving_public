#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int bit_set(int n, int pos) { return n = n | (1<<pos); }
int bit_reset(int n, int pos) { return n = n & ~(1<<pos); }
bool bit_check(int n, int pos) { return (bool)(n & (1<<pos)); }

void power_set(int arr[], int n)
{
    int i,k,z;
    z = 1<<n;

    for(i = 1; i < z; i++)
    {
        for(k = 0; k < n; k++)
        {
            if(i & (1<<k))
                cout << arr[k] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    int cases, caseno=0, n, i, k, cnt;

    int a[5] = {1,2,3,4,5};

    power_set(a,5);

    return 0;
}

