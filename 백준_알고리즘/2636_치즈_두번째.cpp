#include <iostream>
#define MAX 101
using namespace std;

int n, m, all = 0, cheese = 0, hour = 0, idx = 0;
pair<int, int> v[MAX * MAX];
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 > nx || nx >= n || 0 > ny || ny >= m || visited[nx][ny])
            continue;

        if (map[nx][ny])
            v[idx++] = make_pair(nx, ny);
        else 
            dfs(nx, ny);
    }
}

void init_visited() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            visited[i][j] = false;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %d", &map[i][j]);
            if (map[i][j]) all++;
        }
    }

    while (all > 0) {
        init_visited();
        idx = 0;

        dfs(0, 0);

        cheese = 0;
        for (int i = 0; i < idx; i++) {
            if (map[v[i].first][v[i].second]) {
                map[v[i].first][v[i].second] = 0;
                cheese++;
            }
        }

        hour++;
        all -= cheese;
    }

    printf("%d\n%d\n", hour, cheese);
}