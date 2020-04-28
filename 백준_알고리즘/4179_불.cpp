#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

int r, c, sx, sy;
char map[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[MAX][MAX];

queue<pair<int, int> > fq;

void fire() {
    int size = fq.size();
    while(size--) {
        int x = fq.front().first;
        int y = fq.front().second;
        fq.pop();

        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(0 > nx || nx >= r || 0 > ny || ny >= c) continue;
            if(map[nx][ny] != '.' || visited[nx][ny]) continue;

            map[nx][ny] = 'F';
            fq.push(make_pair(nx, ny));
            visited[nx][ny] = true;
        }
    } 
}

int bfs() {
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));

    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        fire();
        time++;
        while(size--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(0 > nx || nx >= r || 0 > ny || ny >= c) return time;
                if(map[nx][ny] != '.' || visited[nx][ny]) continue;

                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }

    return -1;
}

int main() {
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf(" %c", &map[i][j]);
            if(map[i][j] == 'J') {
                sx = i, sy = j;
                map[i][j] = '.';
                visited[i][j] = true;
            } else if(map[i][j] == 'F') {
                fq.push(make_pair(i, j));
                visited[i][j] = true;
            }
        }
    }

    int ans = bfs();
    if(ans == -1) printf("IMPOSSIBLE\n");
    else printf("%d\n", ans);
}

/**
 * 7%에서 메모리 초과가 계속 났던 문제....
 * visited를 제대로 체크 안해줘서 생겼음. (이전에 다녀간 곳을 계속 가게 됨)
 * 
 * 기존에 fire를 이중 for문으로 F를 찾으면 퍼뜨리는 식으로 했는데
 * 그냥 F를 큐에 넣어서 하는 게 for문 줄이고 좋은 듯.
 * 
 * 그리고 맨 처음에는 큐가 아닌 벡터에 넣고 모두 돌렸는데 생각해보니 4방면으로 퍼뜨리는 거라
 * 이전 F는 있어도 이미 퍼뜨려진 것이라 의미 없어서 큐를 사용해야함.
 * **/