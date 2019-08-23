#include <iostream>
#include <queue>
#include <vector>
#define MAX 51
using namespace std;

typedef struct {
    int x, y, value;
} Point;

int r, c, t, ans = 0;
int map[MAX][MAX];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int dx_top[4] = { 0, -1, 0, 1 };
int dy_top[4] = { 1, 0, -1, 0 };
int dx_down[4] = { 0, 1, 0, -1 };
int dy_down[4] = { 1, 0, -1, 0 };
vector<Point> air_purifier;

void spreadFineDust() {
    queue<Point> q;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(map[i][j] > 0) {
                Point p = { i, j, map[i][j] };
                q.push(p);
                map[i][j] = 0;
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int value = q.front().value;
        int num = 0;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(0 <= new_x && new_x < r && 0 <= new_y && new_y < c && map[new_x][new_y] != -1) {
                map[new_x][new_y] += value / 5;
                num++;
            }
        }

        map[x][y] += value - ((value / 5) * num);
    }
}

void dfs(int x, int y, int value, int direction, bool is_top) {
    if(map[x][y] == -1) return;

    if(is_top) {
        int new_x = x + dx_top[direction];
        int new_y = y + dy_top[direction];
        if(0 <= new_x && new_x < r && 0 <= new_y && new_y < c) {
            dfs(new_x, new_y, map[x][y], direction, is_top);
        } else {
            dfs(x + dx_top[direction + 1], y + dy_top[direction + 1], map[x][y], direction + 1, is_top);
        }
    } else {
        int new_x = x + dx_down[direction];
        int new_y = y + dy_down[direction];
        if(0 <= new_x && new_x < r && 0 <= new_y && new_y < c) {
            dfs(new_x, new_y, map[x][y], direction, is_top);
        } else {
            dfs(x + dx_down[direction + 1], y + dy_down[direction + 1], map[x][y], direction + 1, is_top);
        }
    }

    map[x][y] = value; 
}

void cleanAir() {
    dfs(air_purifier[0].x + dx_top[0], air_purifier[0].y + dy_top[0], 0, 0, true);
    dfs(air_purifier[1].x + dx_down[0], air_purifier[1].y + dy_down[0], 0, 0, false);
}

int main() {
    cin >> r >> c >> t;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> map[i][j];
            if(map[i][j] == -1) {
                Point p = { i, j, 0 };
                air_purifier.push_back(p);
            }
        }
    }

    for(int i = 0; i < t; i++) {
        spreadFineDust();
        cleanAir();
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(map[i][j] != -1) ans += map[i][j];
        }
    }

    cout << ans << endl;
}