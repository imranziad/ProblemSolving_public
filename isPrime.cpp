#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define LL long long

bool isPrime(LL n){
    if(n <= 3){
        return n > 1;
    }
    if(n % 2 == 0 || n % 3 == 0){
        return false;
    }
    LL sqrtN = sqrt(n);
    for(LL i = 5; i <= sqrtN; i += 6){
        if(n % i == 0 || n % (i + 2) == 0){
            return false;
        }
    }

    return true;
}

int main()
{
    int n, i, k, m;

    cin >> n;

    if( isPrime(n) ) cout << "Prime";
    else cout << "Not Prime";

    return 0;
}


