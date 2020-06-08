#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int H, W;
char map[MAX][MAX];
bool check = false;
int visited[MAX][MAX];
pair<int, int> s, e;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

typedef struct {
    int x, y, dir, cnt;
} Laser;

void bfs() {
    queue<Laser> q;
    for(int i = 0; i < 4; i++) {
        Laser sl = { s.first, s.second, i, 0 };
        q.push(sl);
    }
    visited[s.first][s.second] = 0;
    

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        int cnt = q.front().cnt;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ncnt = dir != i ? cnt + 1 : cnt;
            
            if(0 > nx || nx >= H || 0 > ny || ny >= W) continue;
            if(visited[nx][ny] < ncnt) continue;
            if(map[nx][ny] == '*') continue;

            Laser nl = { nx, ny, i, ncnt };
            q.push(nl);
            visited[nx][ny] = ncnt;
        }
    }
}

int main() {
    scanf("%d %d", &W, &H);
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            scanf(" %c", &map[i][j]);
            if(map[i][j] == 'C') {
                if(!check) {
                    s.first = i;
                    s.second = j;
                    check = true;
                } else {
                    e.first = i;
                    e.second = j;
                }
            }
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            visited[i][j] = 987654321;
        }
    }

    bfs();
    
    printf("%d\n", visited[e.first][e.second]);
}

/**
 * visited에 거울의 최소 개수를 저장
 * 방향이 바뀌었을 때 개수를 세주면 그것이 거울 개수
 * 맨 처음에 각 방향을 넣어줘야함
 * **/