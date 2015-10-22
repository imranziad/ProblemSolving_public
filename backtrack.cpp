#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[]={1,2,3,4,5,6},t[30]={0};
vector<int>v;

void F(int n)
{
    if(v.size()==n)
    {
        for(int i=0; i<n; i++)
            printf("%d ",v[i]);
        puts("");
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(t[i]==0)
        {
            t[i]=1;
            v.push_back(a[i]);
            F(n);
            t[i]=0;
            v.pop_back();
        }
    }
}

int main()
{
    F(6);

    return 0;
}
