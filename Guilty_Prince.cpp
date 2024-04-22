#include <bits/stdc++.h>
using namespace std;
const int N = 25;
char a[N][N];
int n, m;
bool vis[N][N];
int cnt = 0;
vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
bool valid(int i, int j)
{
    return i >= 0 && i < m && j >= 0 && j < n;
}
void dfs(int si, int sj)
{

    vis[si][sj] = true;
    cnt++;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj) && a[ci][cj] == '.' && !vis[ci][cj])
        {
            dfs(ci, cj);
        }
    }
}

int main()
{

    int t;
    cin >> t;
    int cs = 1;
    while (t--)
    {

        cin >> n >> m;
        int si, sj;
        for (int i = 0; i < m; i++)
        {

            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == '@')
                {
                    si = i;
                    sj = j;
                }
            }
        }
        cnt = 0;
        memset(vis, false, sizeof(vis));

        dfs(si, sj);
        //ekhane cs++ mane age cs er man print korbe then tar man 1 barabe
        cout<<"Case "<<cs++<<": "<<cnt<<endl;

        //evabe o kora jai
        // cs++;
    }

    return 0;
}
// accepted 