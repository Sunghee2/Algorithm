#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 1501
using namespace std;

int R, C, max_day = 0;
char input;
int map[MAX][MAX];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };
bool end_flag = true, visited[MAX][MAX];

typedef struct {
    int x, y;
} Point;

vector<Point> v;

void print_map() {
    printf("===============\n");
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }    
}

void melt() {
    queue<Point> q;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(map[i][j] == 0) {
                Point np = { i, j };
                q.push(np);
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 > nx || nx >= R || 0 > ny || ny >= C) continue;
            if(map[nx][ny] > -1) continue;
            
            Point np = { nx, ny };
            q.push(np);
            map[nx][ny] = map[x][y] + 1;
            max_day = max_day < map[nx][ny] ? map[nx][ny] : max_day;
        }
    }
}

bool move(int day) {
    memset(visited, false, sizeof(visited));
    queue<Point> q;
    Point sp = { v[0].x, v[0].y };
    visited[v[0].x][v[0].y] = true;
    q.push(sp);

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        if(x == v[1].x && y == v[1].y) {
            return true;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 > nx || nx >= R || 0 > ny || ny >= C) continue;
            if(visited[nx][ny] || map[nx][ny] > day) continue;

            Point np = { nx, ny };
            q.push(np);
            visited[nx][ny] = true;
        }
    }
    return false;
}

int main() {
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            scanf(" %c", &input);
            if(input == 'L') {
                Point p = { i, j };
                v.push_back(p);
            } else if(input == 'X') {
                map[i][j] = -1;
            }
        }
    }

    melt();

    int s = 0, e = max_day;
    while(s <= e) {
        int mid = (s + e) / 2;
        if(move(mid)) e = mid - 1;
        else s = mid + 1;
    }

    printf("%d\n", s);
}

/**
 * 정답률이 왜 이렇게 낮나 했더니 1500 입력값 때문이었다..
 * 비슷한 문제를 풀었던 적이 있었는데 1500을 생각못하고 그 때와 똑같이
 * 얼음 녹이고 -> 움직일 수 있는지 확인 -> 또 녹이고.. 이걸 반복했는데 시간초과
 * 
 * 두 번째 방법으로는 얼음녹이는 시간을 줄여보자 해서
 * 맨 처음에 map에 얼음이 녹는 날을 적음
 * 
 * 00012332100110122
    00001232211210111
    00012321122321100
    00123210012332100
    01233210012332100
    11223210001221000
    00112210001210000
    00001221101210000
 * 이런 식으로.
 * 그래서 bfs로 하나하나 확인했는데 시간초과
 * 
 * 그래서 움직일 수 있는지 확인하는 것을 줄이고자 이분탐색 사용
 * 0~최대 녹을 수 있는 날 mid값인 날에서 움직일 수 있는지 확인
 * 하면서 계속 줄여나감
 * **/