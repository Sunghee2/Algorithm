#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 51
#define MAX_VAL 2501
using namespace std;

typedef struct {
    int x, y;
} Point;

int n, m, min_num = MAX_VAL, num_zero;
int map[MAX][MAX], dist[MAX][MAX];
bool visited[11];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
vector<Point> virus;
queue<Point> q;

void spreadVirus() {
    int zero = 0, time = 0;
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(0 <= new_x && new_x < n && 0 <= new_y && new_y < n && map[new_x][new_y] != 1 && dist[new_x][new_y] == -1) {
                dist[new_x][new_y] = dist[x][y] + 1;
                if(map[new_x][new_y] == 0) {
                    zero++;
                    time = dist[new_x][new_y];
                }
                Point p = { new_x, new_y };
                q.push(p);
            }
        }
    }

    if(zero == num_zero && min_num > time) min_num = time;
}

void chooseVirus(int index, int num, int size) {
    if(num == m) {
        memset(dist, -1, sizeof(dist));
        for(int i = 0; i < size; i++) {
            if(visited[i]) {
                Point p = { virus[i].x, virus[i].y };
                q.push(p);
                dist[virus[i].x][virus[i].y] = 0;
            }
        }

        spreadVirus();

        return;
    } 

    for(int i = index; i < size; i++) {
        if(!visited[i]) {
            visited[i] = true;
            chooseVirus(i + 1, num + 1, size);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i< n; i++) {
        for(int j =0; j < n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                Point p = { i, j };
                virus.push_back(p);
            }
            if(map[i][j] == 0) num_zero++;
        }
    }

    chooseVirus(0, 0, virus.size());

    if(min_num == MAX_VAL) cout << "-1" << endl;
    else cout << min_num << endl;
}