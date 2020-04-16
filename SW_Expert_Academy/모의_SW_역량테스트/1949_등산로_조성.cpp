#include <iostream>
#include <cstring>
#include <vector>
#define MAX 9
using namespace std;

typedef struct {
    int x, y;
} Peek;

int t, n, k, max_length;
int map[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[MAX][MAX];
vector<Peek> v;

bool checkRoad(int x, int y, int height) {
    if(0 > x || x >= n || 0 > y || y >= n) return false;
    if(visited[x][y]) return false;
    if(map[x][y] >= height) return false;

    return true;
}

void dfs(int x, int y, int length) {
    visited[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(checkRoad(nx, ny, map[x][y])) {
            dfs(nx, ny, length + 1);
            visited[nx][ny] = false;
        } else {
            if(max_length < length) max_length = length;
        }
    }
}

void callDFS() {
    for(int i = 0; i < v.size(); i++) {
        memset(visited, false, sizeof(visited));

        dfs(v[i].x, v[i].y, 1);
    }
}

void cutPeak() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int tmp = map[i][j];
            for(int d = tmp; d >= (tmp > k ? tmp - k : 0); d--) {
                map[i][j] = d;
                callDFS();
            }
            map[i][j] = tmp;
        }
    }
}

int main() {
    scanf("%d", &t);
    
    for(int tc = 1; tc <= t; tc++) {
        scanf("%d %d", &n, &k);

        int max_peek = 0;
        max_length = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                scanf(" %d", &map[i][j]);

                if(max_peek < map[i][j]) {
                    max_peek = map[i][j];
                    Peek p = { i, j };
                    v.clear();
                    v.push_back(p);
                } else if(max_peek == map[i][j]) {
                    Peek p = {i, j};
                    v.push_back(p);
                }
            }
        }

        cutPeak();

        printf("#%d %d\n", tc, max_length);
    }
}

/**
 * dfs 백트래킹 문제
 * 처음에 50중에 48개 맞았다고 fail 떴는데
 * 알고보니 "최대" 공사 가능 깊이 였음.. k만큼 깎으면 되는게 아니라 안깎을 수도 있고 0~k만큼 깎는 경우를 다 봐야하는 거였음...
 * 
 * 입력 받을 때 가장 높은 봉우리를 벡터에 넣어줌
 * 그리고 cutPeak에서 차례대로 세번째 for문을 통해 봉우리를 깎아줌
 * callDFS로 가서 가장 높은 봉우리에서 dfs를 시작하도록 함
 * **/