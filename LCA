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
#define cnd tree[idx]
#define lnd tree[idx*2]
#define rnd tree[(idx*2)+1]
#define lndp (idx*2),(b),((b+e)/2)
#define rndp (idx*2+1),((b+e)/2+1),(e)
#define pi 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 100005

/**
    Lowest Common Ancestor (LCA)
    - Nodes from 1 to n
    - initialized by -1
    - Process O(N lg N)
    - Query O(lg N)
**/

int par[MAX], L[MAX], p[MAX][18];
vector <int> g[MAX];

void process(int n)
{
    mem(p,-1);
    for(int i = 1; i <= n; i++)
        p[i][0] = par[i];
    for(int j = 1; (1<<j) < n; j++)
    {
        for(int i = 1; i <= n; i++)
            if(p[i][j-1] != -1)
                p[i][j] = p[ p[i][j-1] ][j-1];
    }
}

int LCA(int u, int v)
{
    if(L[u] < L[v]) swap(u,v);
    int lg = log((double)L[u])/log(2.0);

    for(int i = lg; i >= 0; i--)
    {
        if(L[u]-(1<<i) >= L[v])
            u = p[u][i];
    }

    if(u == v) return u;

    for(int i = lg; i >= 0; i--)
    {
        if(p[u][i] != -1 && p[u][i] != p[v][i])
            u = p[u][i], v = p[v][i];
    }

    return par[u];
}

void dfs(int u, int level)
{
    L[u] = level;

    for(int i = 0; i < g[u].size(); i++)
    {
        if(L[ g[u][i] ] == -1)
            dfs(g[u][i], level+1);
    }
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    std::ios_base::sync_with_stdio(0);
    int cases, caseno=0, n, i, j, k, cnt, q;

    cin >> cases;

    while(cases--)
    {
        cin >> n;

        mem(par,-1);
        mem(L,-1);

        FOR(i,1,n)
        {
            cin >> k;
            g[i].clear();
            while(k--)
            {
                cin >> j;
                par[j] = i;
                g[i].pb(j);
            }
        }

        FOR(i,1,n)
            if(par[i] == -1)
                dfs(i,0);

        process(n);

        cin >> q;
        cout << "Case " << ++caseno << ":\n";

        while(q--)
        {
            cin >> j >> k;
            cout << LCA(j,k) << NL;
        }
    }

    return 0;
}


