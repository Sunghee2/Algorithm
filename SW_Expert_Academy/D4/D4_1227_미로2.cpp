#include <iostream>
#include <cstring>
using namespace std;

int tc, sx, sy, ans;
int map[101][101];
bool visited[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
    if(map[x][y] == 3) {
        ans = 1;
        return;
    }

    visited[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < 100 && 0 <= ny && ny < 100 && map[nx][ny] != 1 && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    for(int t = 0; t < 10; t++) {
        cin >> tc;
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        ans = 0;

        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++) {
                scanf("%1d", &map[i][j]);
                if(map[i][j] == 2) {
                    sx = i;
                    sy = j;
                }
            }
        }

        dfs(sx, sy);

        cout << "#" << tc << " " << ans << endl;
    }
}