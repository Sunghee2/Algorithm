#include <iostream>
#include <cstring>
#define MAX 101
using namespace std;

int T, H, W;
char map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
    visited[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 > nx || nx >= H || 0 > ny || ny >= W) continue;
        if(visited[nx][ny] || map[nx][ny] != '#') continue;
        dfs(nx, ny);
    }
}

int callDFS() {
    int ans = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(!visited[i][j] && map[i][j] == '#') {
                dfs(i, j);
                ans++;
            }
        }
    }    
    return ans;
}

int main() {
    scanf("%d", &T);

    while(T--) {
        scanf("%d %d", &H, &W);
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                scanf(" %c", &map[i][j]);
            }
        }

        memset(visited, false, sizeof(visited));
        printf("%d\n", callDFS());
    }
}