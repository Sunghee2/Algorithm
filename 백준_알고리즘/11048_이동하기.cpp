#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1001
using namespace std;

int n, m;
int maze[MAX][MAX];
int map[MAX][MAX];

void move() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            map[i][j] = maze[i][j] + max(map[i - 1][j], max(map[i][j - 1], map[i - 1][j - 1]));
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf(" %d", &maze[i][j]);
        }
    }

    memset(map, 0, sizeof(map));
    move();
    printf("%d\n", map[n][m]);
}  


/**
 * 전형적인 dp 문제
 * map 루프 돌면서 왼쪽, 왼쪽 위 대각선값, 위 값 중 max 값과 현재 값 더하면 됨
 * **/