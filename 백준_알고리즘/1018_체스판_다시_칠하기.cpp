#include <iostream>
#include <algorithm>
#define MAX 51
using namespace std;

int n, m;
char map[MAX][MAX];

int check(int x, int y, int x_end, int y_end, bool is_w) {
    int paint = 0;
    if((is_w && map[x][y] == 'B') || (!is_w && map[x][y] == 'W')) {
        paint = 1;
    }

    int ret = 0; 
    if(x + 1 < x_end) {
        ret = check(x + 1, y, x_end, y_end, is_w? 0 : 1) + paint;
    } else {
        if(y == y_end - 1) return paint;
        ret = check(x_end - 8, y + 1, x_end, y_end, is_w) + paint;
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

    int ans = 2501;
    for(int i = 0; i <= n - 8; i++) {
        for(int j = 0; j <= m - 8; j++) {
            ans = min(ans, min(check(i, j, i + 8, j + 8, 1), check(i, j, i + 8, j + 8, 0)));
        }
    }
    cout << ans << endl;
}

/**
 * 여전히 문제 대충 읽는 버릇때문에 8*8로 자른다는 것을 못보고 다시 처음부터 풀었음ㅠ
 * for문으로 8*8 자르고
 * 간단하게 B, W로 출발하는 2 경우만 보면 됨.
 * **/