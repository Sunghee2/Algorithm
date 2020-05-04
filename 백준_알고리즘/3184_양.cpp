#include <iostream>
#define MAX 251
using namespace std;

int r, c, sheep = 0, wolf = 0, tmp_sheep, tmp_wolf;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
char ground[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int x, int y) {
    if(ground[x][y] == 'v') tmp_wolf++;
    else if(ground[x][y] == 'o') tmp_sheep++;
    visited[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 > nx || nx >= r || 0 > ny || ny >= c || visited[nx][ny]) continue;
        if(ground[nx][ny] == '#') continue;

        dfs(nx, ny);
    }
}

int main() {
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf(" %1c", &ground[i][j]);
            if(ground[i][j] == 'v') wolf++;
            else if(ground[i][j] == 'o') sheep++;
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(!visited[i][j] && ground[i][j] != '#') {
                tmp_sheep = 0; tmp_wolf = 0;
                dfs(i, j); 
                if(tmp_sheep > tmp_wolf) wolf -= tmp_wolf;
                else sheep -= tmp_sheep;
            }
        }
    }

    printf("%d %d\n", sheep, wolf);
}