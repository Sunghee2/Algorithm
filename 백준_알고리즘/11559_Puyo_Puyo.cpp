#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int ans = 0;
char map[12][6];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[12][6], flag = true;
vector<pair<int, int> > v;

void printMap() {
    printf("=============\n");
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 6; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }    
}

void downPuyo() {
    for(int i = 0; i < 6; i++) {
        for(int j = 11; j >= 0; j--) {
            if(map[j][i] != '.') {
                for(int k = 11; k > j; k--) {
                    if(map[k][i] == '.') {
                        int temp = map[k][i];
                        map[k][i] = map[j][i];
                        map[j][i] = temp;
                        break;
                    }
                }
            }
        }
    }
}

void dfs(int x, int y, char color) {
    v.push_back(make_pair(x, y));
    visited[x][y] = true;
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(0 > nx || nx >= 12 || 0 > ny || ny >= 6) continue;
        if(visited[nx][ny]) continue;
        if(color != map[nx][ny]) continue;

        dfs(nx, ny, color);
    }
}

void play() {
    while(flag) {
        flag = false;
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < 12; i++) {
            for(int j = 0; j < 6; j++) {
                if(!visited[i][j] && map[i][j] != '.') {
                    v.clear();
                    dfs(i, j, map[i][j]);

                    if(v.size() >= 4) {
                        flag = true;
                        for(int i = 0; i < v.size(); i++) {
                            map[v[i].first][v[i].second] = '.';
                        }
                        downPuyo();
                    }
                }
            }
        }

        if(flag) ans++;
    }    
}

int main() {
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 6; j++) {
            scanf(" %c", &map[i][j]);
        }
    }

    play();

    printf("%d\n", ans);
}