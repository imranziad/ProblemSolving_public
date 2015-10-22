#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

#define MAX 102
#define pb push_back
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int n, parent[MAX];
vector <int> g[MAX];

void take_input()
{
    int u, v;

    cin >> n;

    while(cin >> u >> v)
    {
        g[u].pb(v);
        g[v].pb(u);
    }
}

void path(int n)
{
    if(n == 0)
    {
        cout << 0;
        return ;
    }

    path(parent[n]);

    cout << " -> " << n;
}

void bfs(int n, int root)
{
    int u, v, i, len, level[MAX], visited[MAX] = {0};
    queue <int> q;

    q.push(root);
    level[root] = 0;
    visited[root] = 1;

    while( !q.empty() )
    {
        u = q.front();
        len = g[u].size();

        for(i = 0; i < len; i++)
        {
            v = g[u][i];

            if( !visited[v] )
            {
                level[v] = level[u] + 1;
                parent[v] = u;
                visited[v] = 1;
                q.push(v);
            }
        }
        q.pop();
    }

    for(i = 2; i <= n; i++)
    {
        cout << "Distance between " << root << " <--> " << i << ": " << level[i] << " : ";
        path(i);
        cout << "\n";
    }
}

int main()
{
    //READ("in.txt");

    take_input();

    bfs(n, 0);

    return 0;
}
