#include <iostream>
#include <cstring>
#define MAX 101
using namespace std;

int ans;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[3] = { 0, 0, -1 };
int dy[3] = { 1, -1, 0 }; 

void dfs(int x, int y) {
    if(x == 0) {
        ans = y;
        return;
    }

    visited[x][y] = true;

    for(int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < 100 && 0 <= ny && ny < 100 && !visited[nx][ny] && map[nx][ny] == 1) {
            dfs(nx, ny);
            break;
        }
    }
}

void callDFS() {
    for(int i = 0; i < 100; i++) {
        if(map[99][i] == 2) dfs(99, i);
    }
}

int main() {
    int tc;
    for(int t = 0; t < 10; t++) {
        cin >> tc;
        memset(visited, false, sizeof(visited));

        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++) {
                cin >> map[i][j];
            }
        }

        callDFS();

        cout << "#" << tc << " " << ans << endl;
    }
}