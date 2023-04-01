#include <iostream>
#define MAX 16
using namespace std;

int n, ans = 0;
int map[MAX][MAX];

void dfs(int x, int y, int num) {
    if(num == 0) {
        ans += 1;
        return;
    } 

    int nx = x, ny = y + 1;
    if(0 > ny || ny >= n) {
        if(nx != n - 1) {
            nx = x + 1;
            ny = 0;
        }
    }
    
    if((x != 0 && !map[x - 1][y]) || (y != 0 && !map[x][y - 1])) {
        map[x][y] = 1;
        dfs(nx, ny, num - 1);
        map[x][y] = 0;
    }

    if(x != n - 1 && y != n - 1) dfs(nx, ny, num);
}

int main() {
    scanf("%d", &n);
    dfs(0, 0, n);
    printf("%d\n", ans);
}

/**
 * 퀸에 대한 설명이 없어서 단순히 상하좌우에 없으면 놓아도 되는 줄 알았음...
 * 하지만 열, 행, 대각선에서 딱 1개만 둘 수 있음..
 * **/