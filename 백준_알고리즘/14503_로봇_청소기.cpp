#include <iostream>
#define MAX 51
using namespace std;

int n, m, r, c, d, ans;
int map[MAX][MAX];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(int x, int y, int d, bool is_back) {
    int num = 0; 
    if(!is_back) {
        ans++;
        map[x][y] = 2;
    }

    int nd = d;

    for(int i = 0; i < 4; i++) {
        nd = nd - 1 >= 0? nd - 1 : 3;
        int nx = x + dx[nd];
        int ny = y + dy[nd];
        if(0 <= nx && nx < n && 0 <= ny && ny < m && map[nx][ny] == 0) {
            dfs(nx, ny, nd, false);
            break;
        } else {
            num++;
            continue;
        }
    }

    if(num == 4) {
        nd = d > 1? d - 2 : d == 1? 3 : 2;
        int nx = x + dx[nd];
        int ny = y + dy[nd];
        if(0 <= nx && nx < n && 0 <= ny && ny < m && map[nx][ny] != 1) {
            dfs(x + dx[nd], y + dy[nd], d, true);
        } else {
            return;
        }
    }
}

int main() {
    cin >> n >> m >> r >> c >> d;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    dfs(r, c, d, false);

    cout << ans << endl;
}