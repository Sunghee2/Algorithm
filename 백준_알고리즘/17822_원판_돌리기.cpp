#include <iostream>
#include <cstring>
#define MAX 51
using namespace std;

int n, m, t, x, d, k;
int map[MAX][MAX], temp[MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[MAX][MAX];
bool is_connect = false;

void printMap() {
    printf("=================\n");
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void rotate(int x, int d, int k) {
    for(int i = x; i <= n; i += x) {
        int idx = 0;
        int start = d == 0 ? m - k : k;
        for(int j = start; j < m; j++) temp[idx++] = map[i][j];
        for(int j = 0; j < start; j++) temp[idx++] = map[i][j];
    
        for(int j = 0; j < idx; j++) map[i][j] = temp[j];
    }
}

void dfs(int x, int y, int num) {
    visited[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 > ny) ny = m - 1;
        if(ny >= m) ny = 0;
        if(1 > nx || nx > n || visited[nx][ny] || map[nx][ny] != num) continue;

        map[nx][ny] = 0;
        map[x][y] = 0;
        is_connect = true;
        dfs(nx, ny, num);
    }
}

void remove() {
    is_connect = false;
    memset(visited, false, sizeof(visited));
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j] && map[i][j] != 0) {
                dfs(i, j, map[i][j]);
            }
        }
    }
}

double getAvg() {
    int sum = 0, num = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j]) {
                sum += map[i][j];
                num++;
            }
        }
    }

    return sum / (double) num;
}

void changeNum() {
    double avg = getAvg();

    if(avg) {
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < m; j++) {
                if(map[i][j] && map[i][j] != avg) {
                    map[i][j] = map[i][j] > avg ? map[i][j] - 1 : map[i][j] + 1;
                }
            }
        }   
    } 
}

int getSum() {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j]) sum += map[i][j];
        }
    }       

    return sum;
}

int main() {
    scanf("%d %d %d", &n, &m, &t);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %d", &map[i][j]);
        }
    }

    for(int i = 0; i < t; i++) {
        scanf("%d %d %d", &x, &d, &k);
        rotate(x, d, k);
        remove();
        if(!is_connect) changeNum();
    }

    printf("%d\n", getSum());
}

/**
 * 구현 문제
 * 
 * 원판을 2차원 배열로 만들어서 구현하면 되어서 막상 그렇게 어렵지는 않은 문제..
 * 다만 인접한 것을 어떻게 판단할 것인가가 문제인데
 * 처음에는 가로 세로 따로 확인하려고 했었으나 1 1 3 2 1 이렇게 되어 있으면 0 0 3 2 0 처럼 이전 수도 확인해야되어서 복잡해질 것 같았음
 * 2차원 배열로 구현해서 dfs로도 인접 숫자를 확인할 수 있을 것 같아 dfs사용함
 * 대신, x가 인덱스를 벗어났을 때 고쳐줘야함(x에서는 둥그렇게 인접하다고 보기 때문에)
 * 
 * 처음에 틀렸다고 나왔었는데...
 * 평균 나눠줄 때 sum / num  -> sum / (double) num 이렇게 안해서..ㅠㅠ 주의하자
 * **/