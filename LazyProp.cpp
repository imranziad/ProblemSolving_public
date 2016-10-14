/**
    Lazy Propagation - LOJ 1164
*/
#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define NL '\n'
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define pi 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx),(b),((b+e)/2)
#define rnd ((2*idx)+1),(((b+e)/2)+1),(e)

struct Node{
    LL sum, lazy;
};

Node tree[4*MAX];

void update_node(int idx, int b, int e, LL v)
{
    cnd.sum += ((e-b+1) * v);
    cnd.lazy += v;
}

void lazy_update(int idx, int b, int e)
{
    update_node(lnd, cnd.lazy);
    update_node(rnd, cnd.lazy);
    cnd.lazy = 0;
}

void update(int idx, int b, int e, int st, int en, LL v)
{
    if(st > e || en < b) return ;
    if(st <= b && en >= e)
    {
        update_node(idx, b, e, v);
        return ;
    }
    if(cnd.lazy) lazy_update(idx, b, e);
    update(lnd, st, en, v);
    update(rnd, st, en, v);
    cnd.sum = tree[2*idx].sum + tree[2*idx+1].sum;
    return ;
}

LL query(int idx, int b, int e, int st, int en)
{
    if(st > e || en < b) return 0;
    if(st <= b && en >= e) return cnd.sum;
    if(cnd.lazy) lazy_update(idx, b, e);
    LL lft = query(lnd, st, en);
    LL rgt = query(rnd, st, en);
    return (lft + rgt);
}

int main()
{
    //READ("input.txt");
    //WRITE("out.txt");
    int cases, caseno=0, n, i, j, k, x, y, q, v;

    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d %d", &n, &q);

        mem(tree,0);

        printf("Case %d:\n", ++caseno);

        while(q--)
        {
            scanf("%d", &k);

            if(!k)
            {
                scanf("%d %d %d", &x, &y, &v);
                update(1,0,n-1,x,y,v);
            }
            else
            {
                scanf("%d %d", &x, &y);
                printf("%lld\n", query(1,0,n-1,x,y));
            }
        }
    }

    return 0;
}

/*
2
10 5
0 0 9 10
1 1 6
0 3 7 2
0 4 5 1
1 5 5
20 3
0 10 12 1
1 11 12
1 19 19
*/
