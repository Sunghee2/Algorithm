#include <iostream>
#include <algorithm>
#define MAX 501
using namespace std;

int n, m;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int map[MAX][MAX];
bool visited[MAX][MAX];

int dfs(int x, int y, int cnt) {
    if(cnt == 3) {
        return map[x][y];
    }

    int sum = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < m && !visited[nx][ny]) {
            visited[nx][ny] = true;
            sum = max(sum, map[x][y] + dfs(nx, ny, cnt + 1));
            visited[nx][ny] = false;
        }
    }
    return sum;
}

int checkOther(int x, int y) {
    int ret = 0;

    // ㅗ
    if(1 <= x && x < n - 1 && 1 <= y) {
        ret = max(ret, map[x - 1][y] + map[x][y] + map[x + 1][y] + map[x][y - 1]);
    }
    // ㅓ
    if(1 <= x && 1 <= y && y < m - 1) {
        ret = max(ret, map[x - 1][y] + map[x][y] + map[x][y - 1] + map[x][y + 1]);
    }
    // ㅜ
    if(1 <= x && x < n - 1 && y < m - 1) {
        ret = max(ret, map[x - 1][y] + map[x][y] + map[x + 1][y] + map[x][y + 1]);
    }
    // ㅏ
    if(x < n - 1 && 1 <= y && y < m - 1) {
        ret = max(ret, map[x][y - 1] + map[x][y] + map[x][y + 1] + map[x + 1][y]);
    }

    return ret;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j]; 
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            visited[i][j] = true;
            ans = max(ans, dfs(i, j, 0));
            ans = max(ans, checkOther(i, j));
            visited[i][j] = false;
        }
    }

    cout << ans << endl;
}

/**
 * 처음에 저 5개 도형 모두 써야되는 줄 알았다... 
 * 하나만 쓰면 됨.. 문제 제대로 읽자ㅠ
 * 
 * ㅜ 처럼 생긴 애 빼고 모두 4번 dfs로 갈 수 있음.
 * **/