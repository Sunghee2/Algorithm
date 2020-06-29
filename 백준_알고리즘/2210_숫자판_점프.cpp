#include <iostream>
using namespace std;

int map[5][5];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
bool check[1000000];

void dfs(int x, int y, int num, int cnt) {
    if(cnt == 5) {
        check[num] = true;
        return;
    }

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 > nx || nx >= 5 || 0 > ny || ny >= 5) continue;

        dfs(nx, ny, (num * 10) + map[nx][ny], cnt + 1);
    }
}

void callDFS() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            dfs(i, j, map[i][j], 0);
        }
    }
}

int count() {
    int cnt = 0;
    for(int i = 0; i < 1000000; i++) {
        if(check[i]) cnt++;
    }
    return cnt;
}

int main() {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            scanf(" %d", &map[i][j]);
        }
    }

    callDFS();
    printf("%d\n", count());
}

/**
 * 완전탐색문제
 * 
 * 맨 처음에 틀렸었는데 0으로 시작되는 수를 고려하지 못해서 count int i를 100000부터 시작했었음
 * 그래서
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
 * 이런 입력이 들어오면 1이 아닌 0으로 나오게 됨.
 * 
 * 특별한 조건이 있는 건 아니였지만
 * 6자리 수 중복을 체크해야되었음 평소였으면 set을 썼겠지만..
 * 나중에 오프라인 코테 봤을 때 set을 까먹게 되는 경우를 대비해.. 배열로 중복 체크하는 방법으로 풀어봄
 * 단순히 bool 배열로 만들어서 숫자를 index로 체크하면 됨. 숫자가 크지 않은 경우에 사용하면 될 듯.
 * **/