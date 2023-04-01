#include<iostream>
#include<queue>
using namespace std;
int N, M, Hx, Hy, Ex, Ey, ans, flag;
queue <pair<pair<int, int>, int> > q;
int miro[1002][1002];
// x좌표, y좌표, 지팡이 사용여부
bool visited[1001][1001][2];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int main(void)
{
    cin >> N >> M;
    cin >> Hx >> Hy >> Ex >> Ey;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> miro[i][j];
        }
    }
    visited[Hx][Hy][1] = true;
    q.push(make_pair(make_pair(Hx, Hy), 1));
    while (!q.empty())
    {
        int qsz = q.size();
        while (qsz--)
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int key = q.front().second;
            q.pop();
            if (x == Ex && y == Ey) {
                flag = 1; break;
            }
            for (int i = 0; i < 4; i++)
            {
                int mx = x + dx[i];
                int my = y + dy[i];
                int nkey = key;
                if (mx < 1 || mx > N || my < 1 || my > M) continue;
                if (visited[mx][my][nkey]) continue;
                // miro가 0이면 key가 있든 없든 쓰지 않고 갈 수 있다.
                if (!miro[mx][my])
                {
                    visited[mx][my][nkey] = true;
                    q.push(make_pair(make_pair(mx, my), nkey));
                }
                // 1이면 key가 있어야 갈 수 있다.
                if(miro[mx][my] && nkey)
                {
                    nkey = 0;
                    visited[mx][my][nkey] = true;
                    q.push(make_pair(make_pair(mx, my), nkey));
                }
            }
        }
        if (flag) break;
        ans++;
    }
    if(flag) cout << ans;
    else cout << -1;
    return 0;
}
 