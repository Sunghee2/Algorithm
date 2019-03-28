#include <iostream>
#include <algorithm>
using namespace std;

int m, n, k, num, all_num = 0;
int paper[101][101] = { 0 };
int rect_num[101] = { 0 };
bool visited[101][101] = { 0 };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void dfs(int x, int y) {
    visited[x][y] = true;
    num++;

    for(int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if((0 <= new_x) && (new_x < m) && (0 <= new_y) && (new_y < n) && (!visited[new_x][new_y]) && (paper[new_x][new_y] == 0)) {
            dfs(new_x, new_y);
        }
    }
}

void callDFS() {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if((!visited[i][j]) && (paper[i][j] == 0)) {
                num = 0;
                dfs(i, j);
                rect_num[all_num++] = num;
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &m, &n, &k);

    for(int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        for(int j = y1; j < y2; j++) {
            for(int k = x1; k < x2; k++) {
                paper[j][k] = 1;
            }
        }
    }

    callDFS();

    printf("%d\n", all_num);
    
    sort(rect_num, rect_num + all_num);
    for(int i = 0; i < all_num; i++) {
        printf("%d ", rect_num[i]);
    }
}

/**
 * m, n때문에 헷갈렸던 문제.. 그냥 m=x, n=y라고 생각하면 편함ㅠ
 * 좌표 입력 받을 때마다 paper 배열 해당 자리에 1을 입력함. 나머지는 0
 * 그리고 callDFS()통해서 0이고 방문하지 않은 것을 찾고
 * 해당 좌표가 있으면 dfs를 호출하고 상하좌우에 또 0이 있으면 dfs
 * **/