#include <iostream>
#include <queue>
#include <cstring>
#define MAX 11
using namespace std;

int n, m, RX, RY, BX, BY;
char map[MAX][MAX];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[MAX][MAX][MAX][MAX];

void printMap() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }    
}

int bfs() {
    queue<pair<pair<int, int>, pair<int, int> > > q;
    q.push(make_pair(make_pair(RX, RY), make_pair(BX, BY)));

    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        time++;
        if(time > 10) break;

        while(size --) {
            int rx = q.front().first.first;
            int ry = q.front().first.second;
            int bx = q.front().second.first;
            int by = q.front().second.second;
            q.pop();

            if(visited[rx][ry][bx][by]) continue;
            visited[rx][ry][bx][by] = true;

            for(int i = 0; i < 4; i++) {

            }
        }
    }

    return -1;
}

int main() {    
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %c", &map[i][j]);
            if(map[i][j] == 'B') bx = i, by = j;
            else if(map[i][j] == 'R') rx = i, ry = j;
        }
    }

    memset(visited, false, sizeof(visited));
    printMap();
}