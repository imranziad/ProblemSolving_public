/**

    Algorithm:  Maximum Flow - Ford–Fulkerson Edmonds Karp
    Complexity: O(V * E * E)
    Problem:    LOJ 1153 - Internet Bandwidth

**/


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
#define MAX 105

int n, g[MAX][MAX], cap[MAX][MAX];

int max_flow(int src, int sink)
{
    int i, j, u, mn, flow = 0, vis[MAX]={0}, p[MAX];
    queue <int> q;
    bool flag;
    // storing the matrix in cap array
    FOR(i,1,n)
    {
        FOR(j,1,n)
            cap[i][j] = g[i][j];
    }
    while(1)
    {
        // BFS - discovering augmenting path
        while(!q.empty()) q.pop();
        mem(vis,0);
        q.push(src);
        vis[src] = 1;
        flag = false;

        while(!q.empty())
        {
            u = q.front();
            q.pop();

            FOR(i,1,n)
            {
                if(i == u) continue;
                if(vis[i] == 0 && cap[u][i] > 0)
                {
                    // save the parent
                    p[i] = u;
                    if(i == sink)
                    {
                        // found the sink
                        flag = true;
                        break;
                    }
                    vis[i] = 1;
                    q.push(i);
                }
            }
            if(flag) break;
        }

        if(!flag) break;
        // find the minimum of the path
        i = sink;
        mn = INT_MAX;
        while(i != src)
        {
            mn = min(mn, cap[ p[i] ][i]);
            i = p[i];
        }
        // adjust the flow
        i = sink;
        while(i != src)
        {
            cap[ p[i] ][i] -= mn;
            cap[i][ p[i] ] += mn;
            i = p[i];
        }
        // add the flow to the max flow
        flow += mn;
    }
    return flow;
}

int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int cases, caseno=0, st, en, m, u, v, w;

    scanf("%d", &cases);

    while(cases--)
    {
        scanf("%d %d %d %d", &n, &st, &en, &m);

        mem(g,0);

        while(m--)
        {
            scanf("%d %d %d", &u, &v, &w);
            g[u][v] += w;
            g[v][u] += w;
        }

        printf("Case %d: %d\n", ++caseno, max_flow(st, en));
    }

    return 0;
}
