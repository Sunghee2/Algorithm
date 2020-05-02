#include <iostream>
#include <queue>
#include <cstring>
#define MAX 1001
using namespace std;

int t, w, h, sx, sy;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
char map[MAX][MAX];
bool visited[MAX][MAX];
queue<pair<int, int> > fire;

void printMap() {
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }    
}


void spread() {
    int size = fire.size();
    while(size--) {
        int x = fire.front().first;
        int y = fire.front().second;
        fire.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 > nx || nx >= h || 0 > ny || ny >= w) continue;
            if(map[nx][ny] != '.') continue;

            visited[nx][ny] = true;
            map[nx][ny] = '*';
            fire.push(make_pair(nx, ny));
        }       
    }
}

int bfs() {
    queue<pair<int, int> > person;
    person.push(make_pair(sx, sy));

    int time = 0;
    while(!person.empty()) {
        int size = person.size();
        spread();
        time++;
        while(size--) {
            int x = person.front().first;
            int y = person.front().second;
            person.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(0 > nx || nx >= h || 0 > ny || ny >= w) return time;
                if(map[nx][ny] != '.' || visited[nx][ny]) continue;

                visited[nx][ny] = true;
                person.push(make_pair(nx, ny));
            }
        }
    }

    return -1;
}

int main() {
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++) {
        while(!fire.empty()) fire.pop();
        memset(visited, false, sizeof(visited));

        scanf("%d %d", &w, &h);
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                scanf(" %1c", &map[i][j]);
                if(map[i][j] == '@') {
                    sx = i, sy = j;
                    map[i][j] = '.';
                    visited[i][j] = true;
                } else if(map[i][j] == '*') {
                    fire.push(make_pair(i, j));
                    visited[i][j] = true;
                }
            }
        }

        int ans = bfs();
        if(ans > 0) printf("%d\n", ans);
        else printf("IMPOSSIBLE\n");
    }
}

/**
 * 문제가 너무 익숙했는데 
 * 똑같은 문제가 있었음 .. 4179 불
 * **/