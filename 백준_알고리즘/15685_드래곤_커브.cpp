#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

int n, x, y, d, g;
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int map[MAX][MAX];
vector<int> directions;

int countSquare() {
    int num = 0;
    for(int i = 0; i < MAX - 1; i++) {
        for(int j = 0; j < MAX - 1; j++) {
            if(map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) num++;
        }
    }

    return num;
}

void curve(int x, int y, int generation) {
    if(generation > g) return;

    int nx = x, ny = y;
    int size = directions.size();
    for(int i = size - 1; i >= 0; i--) {
        int nd = generation ? (directions[i] + 1) % 4 : directions[i];
        nx += dx[nd];
        ny += dy[nd];

        if(0 > nx || nx >= MAX || 0 > ny || ny >= MAX) return;

        map[nx][ny] = 1;
        if(generation) directions.push_back(nd);
    }

    curve(nx, ny, generation + 1);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf(" %d %d %d %d", &y, &x, &d, &g);
        map[x][y] = 1;
        directions.push_back(d);
        curve(x, y, 0);
        directions.clear();
    }

    printf("%d\n", countSquare());
}

/**
 * 또, x/y 방향.. 주의..!
 * 
 * 입력 받고
 * 각 n줄 입력 받을 때마다 curve 함수를 통해 0세대부터 입력받을 세대까지 재귀 돌음.
 * 세대 지날 때마다 이전 세대의 90도를 회전시키는 모양이 나오는데 
 * 이건 단순히 세대 지날 때마다 벡터에 방향을 넣어놔서 (역순으로) +1 해주면 90도 해준 모양이 나옴
 * 그렇게 돌고 1x1 정사각형을 세야 하는데 
 * 예시는 선인데 여기서는 칸으로 바꿔서 했기 때문에
 * 2x2가 방문했으면 1x1 정사각형으로 볼 수 있음. 따라서 2x2 방문했는지 체크해서 확인함.
 * 
 * 
 * 0세대 : 0
 * 1세대 : 1
 * 2세대 : 2 -> 1
 * 3세대 : 2 -> 3 -> 2 -> 1
 * 4세대 : 2 -> 3 -> 0 -> 3 -> 2 -> 3 -> 2 -> 1
 * **/