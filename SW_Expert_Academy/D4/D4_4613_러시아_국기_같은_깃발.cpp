#include <iostream>
using namespace std;

int n, m, ans;
char arr[51][51];
char color[3] = {'W', 'B', 'R'};

void dfs(int row, int color_index, int num, int chk) {
    if(row == n) {
        if(chk == 3) {
            ans = ans > num? num : ans;
        }
        return;
    }

    for(int i = 0; i < m; i++) {
        if(arr[row][i] != color[color_index]) num++;
    }

    dfs(row + 1, color_index, num, chk);
    if((color_index != 2) && (row != n - 1)) dfs(row + 1, color_index + 1, num, chk + color_index + 1);
}

int main() {
    int testcase;
    scanf("%d", &testcase);

    for(int tc = 1; tc <= testcase; tc++) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                scanf(" %c", &arr[i][j]);
            }
        }

        ans = 2610;
        dfs(0, 0, 0, 0);

        printf("#%d %d\n", tc, ans);
    }
}

/**
 * dfs를 통해서 다음 row 넘어갈 때 2번 호출
 * 1. 다음 색으로 넘어감
 * 2. 지금 색 그대로 사용
 * 
 * chk는 색이 모두 쓰였는지 확인하는 변수임. 원래 bool 배열로 했는데 초기화문제때문에 계속 틀렸었음ㅠㅠ
 * **/