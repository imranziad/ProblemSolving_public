#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAX 202
#define xx first
#define yy second
#define pii pair<int,int>
#define pb push_back
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)

int r, c, cell[MAX][MAX];
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int d[MAX][MAX];

void take_input()
{
    int u, v;

    cin >> r >> c;

    memset(cell,0,sizeof(cell));

    while(cin >> u >> v)
        cell[u][v] = -1;
}

void bfs(int sx, int sy)
{
    int vis[MAX][MAX]={0};
    queue <pii> q;

    q.push(pii(sx, sy));
    d[sx][sy] = 0;
    vis[sx][sy] = 1;

    while( !q.empty() )
    {
        pii top = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int tx = top.xx + fx[i];
            int ty = top.yy + fy[i];

            if(tx >= 0 && tx <= r && ty >= 0 && ty <= c && cell[tx][ty] != -1 && vis[tx][ty] == 0)
            {
                d[tx][ty] = d[top.xx][top.yy] + 1;
                q.push(pii(tx, ty));
                vis[tx][ty] = 1;
            }
        }
    }
}

int main()
{
    READ("in.txt");

    take_input();

    bfs(1, 1);

    cout << d[r][c];

    return 0;
}

