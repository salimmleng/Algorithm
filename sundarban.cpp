#include <bits/stdc++.h>
using namespace std;
const int N = 50;
char a[N][N];
bool vis[N][N];
int dis[N][N];
int n;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool valid(int ci, int cj)
{
    return !vis[ci][cj] && a[ci][cj] != 'T' && ci >= 0 && ci < n && cj >= 0 && cj < n;
}
void bfs(int si, int sj)
{
    //eta old version er format
    queue<pair<int, int> > q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        //auto update version
        //pair lekha old version

        pair<int,int> par = q.front();
        q.pop();
        int a = par.first;
        int b = par.second;
        for (int i = 0; i < 4; i++)
        {
            int ci = a + dx[i];
            int cj = b + dy[i];
            if (valid(ci, cj))
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
}
int main()
{

    while (cin >> n)
    {
        int si, sj, endi, endj;

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                if (a[i][j] == 'E')
                {
                    endi = i;
                    endj = j;
                }
            }
        }
        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));
        bfs(si, sj);
        cout << dis[endi][endj] << endl;
    }

    return 0;
}

//accepted

