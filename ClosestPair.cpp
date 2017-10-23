/***
  UVA: 10245 - Closest Pair
  Complexity: O(n * lg n * lg n)
***/

#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define NL '\n'
#define xx first
#define yy second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%I64d",&x)
#define sd(x) scanf("%lf",&x)
#define ss(x) scanf("%s",x)
#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define cnd tree[idx]
#define lnd tree[idx*2]
#define rnd tree[(idx*2)+1]
#define lndp (idx*2),(b),((b+e)/2)
#define rndp (idx*2+1),((b+e)/2+1),(e)
#define pi 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 100005
#define EPS 0.000000001
#define pdd pair<double,double>

pdd p[MAX];
pair<double, int> vec[MAX];

double dist(pdd &a, pdd &b)
{
    return sqrt( (a.xx-b.xx)*(a.xx-b.xx) + (a.yy-b.yy)*(a.yy-b.yy) );
}

double closestPair(int b, int e)
{
    if(b>=e) return 1000000000.0;
    if(e-b == 1) return dist(p[b], p[e]);
    int mid = (b+e)>>1;
    double dl = closestPair(b, mid);
    double dr = closestPair(mid+1, e);
    double d, tempd;
    if(dl-dr < EPS) d = dl;
    else d = dr;
    int sz = 0;

    // both side
    for(int i = b; i <= mid; i++)
        if( (double)(p[mid].xx-p[i].xx) < d)
            vec[sz++] = mp(p[i].yy, i);
    for(int i = mid+1; i <= e; i++)
        if( (double)(p[i].xx-p[mid].xx) < d)
            vec[sz++] = mp(p[i].yy, i);

    sort(vec,vec+sz);

    int i = 0, j = 0, k = 0;

    while(i < sz)
    {
        k = i+1;
        while(k < sz && (double)(vec[k].xx-vec[i].xx) < d)
        {
            tempd = dist(p[vec[i].yy], p[vec[k].yy]);
            if(tempd-d < EPS) d = tempd;
            k++;
        }
        i++;
    }
    return d;
}

int main()
{
    //READ("input.txt");
    //WRITE("out.txt");
    std::ios_base::sync_with_stdio(0);
    int n, i;
    double x, y;

    while(1)
    {
        cin >> n;
        if(n == 0) break;

        FOR(i,0,n-1)
        {
            cin >> x >> y;
            p[i] = mp(x,y);
        }

        sort(p,p+n);

        double d = closestPair(0,n-1);

        if(d-10000.0 < EPS)
        {
            cout << fixed;
            cout << setprecision(4) << d << NL;
        }
        else
            cout << "INFINITY" << NL;
    }

    return 0;
}
