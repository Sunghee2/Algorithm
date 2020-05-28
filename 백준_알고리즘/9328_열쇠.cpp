#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

int T, H, W, cnt;
char map[MAX][MAX], K[26];
bool visited[MAX][MAX], key[26];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

typedef struct {
    int x, y;
} Point;

vector<Point> v[40];

void bfs(int sx, int sy) {
    queue<Point> q;
    Point sp = { sx, sy };
    visited[sx][sy] = true;
    q.push(sp);

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        if(map[x][y] == '$') {
            cnt++;
            map[x][y] = '.';
        } else if('a' <= map[x][y] && map[x][y] <= 'z' && !key[map[x][y] - 'a']) {
            int idx = map[x][y] - 'a';
            key[idx] = true;
            for(int i = 0; i < v[idx].size(); i++) {
                Point p = { v[idx][i].x, v[idx][i].y };
                visited[v[idx][i].x][v[idx][i].y] = true;
                q.push(p);
            }
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0 > nx || nx >= H || 0 > ny || ny >= W) continue;
            if(visited[nx][ny] || map[nx][ny] == '*') continue;
            if('A' <= map[nx][ny] && map[nx][ny] <= 'Z') {
                Point p = { nx, ny };
                v[map[nx][ny] - 'A'].push_back(p);
                if(!key[map[nx][ny] - 'A']) continue;
            }

            Point np = { nx, ny };
            visited[nx][ny] = true;
            q.push(np);
        }
    }
}

void callBFS() {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if((i == 0 || i == H - 1 || j == 0 || j == W - 1) && (map[i][j] != '*')) {
                if('A' <= map[i][j] && map[i][j] <= 'Z') {
                    Point p = { i, j };
                    v[map[i][j] - 'A'].push_back(p);
                    if(key[map[i][j] - 'A']) bfs(i, j);
                } else bfs(i, j);
            }
        }
    }
}

int main() {
    scanf("%d", &T);
    while(T--) {
        cnt = 0;
        memset(visited, false, sizeof(visited));
        memset(K, '0', sizeof(K));
        memset(key, false, sizeof(key));
        for(int i = 0; i < 40; i++) v[i].clear();

        scanf("%d %d", &H, &W);
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                scanf(" %c", &map[i][j]);
            }
        }
        scanf(" %s", K);
        for(int i = 0; i < 26; i++) {
            if(K[i] == '0') break;
            key[K[i] - 'a'] = true;
        }

        callBFS();
        
        printf("%d\n", cnt);
    }
}

/**
 * 맨 처음에 문제를 잘못 이해했는데 가장자리 + 문이면 다 들어갈 수 있는 줄 알았는데
 * 그냥 가장자리에 열려있거나 가장자리에 있는 문을 통해서만 들어갈 수 있었다..
 * 
 * 그래서 다른 사람들은 입력받는 맵 사방면에 따로 한 칸씩을 더 두어서 위를 처리함..
 * 나는 처음 문제를 잘못해석한 부분때문에 이렇게ㅠㅠ callBFS()로 따로 처리하게 되었다..
 * 
 * 그리고 문을 만나면 해당 인덱스(알파벳 순서)에 문의 위치를 넣어줌(현재 열쇠가 없지만 나중에 얻을 수 있기 때문에)
 * 그래서 열쇠를 얻게 되면 해당 문이 있는지 확인하고 문의 위치를 큐에 넣음
 * 
 * 이걸 풀면서 런타임 에러가 많이 났는데
 * 어디서 나는지 몰라서 백준에 하나씩 주석처리해서 넣어봤다...
 * 잘못된 곳은 문을 넣는 벡터에서 push_back하는 부분..(52, 69번째)
 * 원래 벡터 크기가 26이었는데 40으로 늘리니 바로 통과됨;;;;;;;
 * 왜지... 해당 부분에 A, B~ Z까지 다 넣어봤는데ㅠㅠ괜찮았었다.. 인덱스도 다 0~25사이로 들어오고...
 * **/