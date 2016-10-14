#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;

#define NL '\n'
#define MAX 100005
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int a[MAX];

void solve(int n, int k)
{
    int i;
    deque<int> dq;

    FOR(i,0,k-1)
    {
        while(!dq.empty() && a[i] >= a[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    cout << a[dq.front()] << " ";

    FOR(i,k,n-1)
    {
        while(!dq.empty() && dq.front() <= i-k)
            dq.pop_front();
        while(!dq.empty() && a[i] >= a[dq.back()])
            dq.pop_back();
        dq.push_back(i);

        cout << a[dq.front()] << " ";
    }
}

int main()
{
    //READ("in2.txt");
    //WRITE("in.txt");
    int n, i, k;

    cin >> n >> k;

    FOR(i,0,n-1) cin >> a[i];

    solve(n, k);

    return 0;
}

