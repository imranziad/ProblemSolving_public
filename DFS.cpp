#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAX 100

stack <int> stck;
vector <int> g[MAX];
int vis[MAX];

void print()
{
    stack <int> temp, temp2;
    temp = stck;

    while( !temp.empty() )
    {
        temp2.push(temp.top());
        temp.pop();
    }
    while( !temp2.empty() )
    {
        cout << (char)('A'-1+temp2.top()) << " ";
        temp2.pop();
    }
    cout << endl;
}

void dfs(int u)
{
    if(vis[u])
        return ;

    vis[u] = 1;
    stck.push(u);
    print();

    for(int i = 0; i < g[u].size(); i++)
    {
        dfs( g[u][i] );
    }

    stck.pop();
    print();
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    std::ios_base::sync_with_stdio(0);
    int n, m, i, u, v;

    cin >> n >> m;

    while( m-- )
    {
        cin >> u >> v;
        g[u].pb(v);
    }


    memset(vis,0,sizeof(vis));

    dfs(8);

    for(i = 1; i <= n; i++)
        cout << "[" << i << "]->" << vis[i] << "\n";

    return 0;
}
