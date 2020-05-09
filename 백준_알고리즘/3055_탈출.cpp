#include <iostream>
#include <queue>
#include <cstring>
#define MAX 51
using namespace std;

int R, C, sr, sc, er, ec;
char map[MAX][MAX];
bool visited[MAX][MAX];
bool water_visited[MAX][MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 }; 

typedef struct {
    int x, y;
} Point;

void printMap() {
    printf("===============\n");
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }     
}

void water() {
    memset(water_visited, false, sizeof(water_visited));
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(!water_visited[i][j] && map[i][j] == '*') {
                for(int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];

                    if(0 > nx || nx >= R || 0 > ny || ny >= C) continue;
                    if(water_visited[nx][ny] || map[nx][ny] != '.') continue;
                    if(nx == er && ny == ec) continue;

                    water_visited[nx][ny] = true;
                    map[nx][ny] = '*';
                }
            }
        }
    }    
}

int bfs() {
    queue<Point> q;
    Point p = { sr, sc };
    visited[sr][sc] = true;
    q.push(p);

    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        water();
        while(size--) {
            int x = q.front().x;
            int y = q.front().y;
            q.pop();

            if(x == er && y == ec) return time;

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(0 > nx || nx >= R || 0 > ny || ny >= C) continue;
                if(visited[nx][ny] || map[nx][ny] != '.') continue;

                Point p = { nx, ny };
                visited[nx][ny] = true;
                q.push(p);
            }
        }
        time++;
    }

    return -1;
}

int main() {
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            scanf(" %c", &map[i][j]);
            if(map[i][j] == 'S') {
                sr = i, sc = j;
                map[i][j] = '.';
            } else if(map[i][j] == 'D') {
                er = i, ec = j;
                map[i][j] = '.';
            }
        }
    }

    int ans = bfs();
    if(ans > 0) printf("%d\n", ans);
    else printf("KAKTUS\n");
}

/**
 * 메모리 초과 났던 문제..
 * 62번째 줄에 visited true를 해줬는데 74번째로 바꾸니깐 해결
 * 왜냐하면 새 값이 중복될 경우가 있기 때문에.......
 * 
 * 메모리 초과되면 일단 방문체크가 제대로 되어있는지 확인하자
 * **/