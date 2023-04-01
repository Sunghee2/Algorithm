#include <iostream>
#include <queue>

using namespace std;

int n, m, x, y, min_time = 2147483647, min_num = 0;
int map[25][25];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

typedef struct {
    int x, y, time;
} Point;

void bfs() {
    queue<Point> q;
    Point start = {0, 0, 0};
    q.push(start);
    
    while(!q.empty()) {
        int cur_x = q.front().x;
        int cur_y = q.front().y;
        int cur_time = q.front().time;
        q.pop();
        
        if(cur_x == x && cur_y && y) {
            if(min_time > cur_time) {
                min_time = cur_time;
                min_num = 1;
            } else if(min_time == cur_time) {
                min_num++;
            } else break;
        }
        
        for(int i = 0; i < 4; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if((0 <= nx) && (nx < n) && (0 <= ny) && (ny < m)) {
                Point np = {nx, ny, cur_time + 1};
                q.push(np);
            }
        }
    }
}

int main(void) {
    cin >> n >> m >> x >> y;
    
    if((x == 0 && y == 0)) cout << "0" << endl;
    else if((0 <= x) && (x < n) && (0 <= y) && (y < m)) {
        bfs();
        cout << min_time << "\n" << min_num << endl;
    }
    else cout << "fail" << endl;
}