#include <iostream>
#include <queue>
#define MAX 51
using namespace std;

typedef struct {
    int x, y;
} Point;

typedef struct {
    int x1, y1, x2, y2, x3, y3;
} Wood;

int N;
char map[MAX][MAX];
bool visited[MAX][MAX][2]; // 가로 0 세로 1
bool horizontal = false;
vector<Point> v, end_point;

bool check_boundary(int value) {
    if(0 > value || value >= N) return false;
    return true;
}

int move() {
    queue<Wood> q;
    visited[v[1].x][v[1].y][abs(v[0].x - v[1].x) >= 1 ? 1 : 0] = true;
    Wood sw = { v[0].x, v[0].y, v[1].x, v[1].y, v[2].x, v[2].y };
    q.push(sw);

    int time = 0;
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            bool is_rotate1 = false, is_rotate2 = false;
            Wood cur = q.front();
            q.pop();

            if(abs(cur.x1 - cur.x2) >= 1) horizontal = false;
            else horizontal = true;

            if(cur.x1 == end_point[0].x && cur.x2 == end_point[1].x && cur.x3 == end_point[2].x && cur.y1 == end_point[0].y && cur.y2 == end_point[1].y && cur.y3 == end_point[2].y) {
                return time;
            }

            // 위로
            int nx1 = cur.x1 - 1, nx2 = cur.x2 - 1, nx3 = cur.x3 - 1;
            if(check_boundary(nx1) && check_boundary(nx2) && check_boundary(nx3)) {
                if(map[nx1][cur.y1] != '1' && map[nx2][cur.y2] != '1' && map[nx3][cur.y3] != '1') {
                    is_rotate1 = true;
                    if(!visited[nx2][cur.y2][horizontal ? 0 : 1]) {
                        Wood nw = { nx1, cur.y1, nx2, cur.y2, nx3, cur.y3 };
                        visited[nx2][cur.y2][horizontal ? 0 : 1] = true;
                        q.push(nw);
                    }
                }
            }
            // 아래로
            nx1 = cur.x1 + 1, nx2 = cur.x2 + 1, nx3 = cur.x3 + 1;
            if(check_boundary(nx1) && check_boundary(nx2) && check_boundary(nx3)) {
                if(map[nx1][cur.y1] != '1' && map[nx2][cur.y2] != '1' && map[nx3][cur.y3] != '1') {
                    if(!visited[nx2][cur.y2][horizontal ? 0 : 1]) {
                        Wood nw = { nx1, cur.y1, nx2, cur.y2, nx3, cur.y3 };
                        visited[nx2][cur.y2][horizontal ? 0 : 1] = true;
                        q.push(nw);
                    }
                } else {
                    is_rotate1 = false;
                }
            }
            // 왼쪽
            int ny1 = cur.y1 - 1, ny2 = cur.y2 - 1, ny3 = cur.y3 - 1;
            if(check_boundary(ny1) && check_boundary(ny2) && check_boundary(ny3)) {
                if(map[cur.x1][ny1] != '1' && map[cur.x2][ny2] != '1' && map[cur.x3][ny3] != '1') {
                    is_rotate2 = true;
                    if(!visited[cur.x2][ny2][horizontal ? 0 : 1]) {
                        Wood nw = { cur.x1, ny1, cur.x2, ny2, cur.x3, ny3 };
                        visited[cur.x2][ny2][horizontal ? 0 : 1] = true;
                        q.push(nw);
                    }
                }
            }            
            // 오른쪽
            ny1 = cur.y1 + 1, ny2 = cur.y2 + 1, ny3 = cur.y3 + 1;
            if(check_boundary(ny1) && check_boundary(ny2) && check_boundary(ny3)) {
                if(map[cur.x1][ny1] != '1' && map[cur.x2][ny2] != '1' && map[cur.x3][ny3] != '1') {
                    if(!visited[cur.x2][ny2][horizontal ? 0 : 1]) {
                        Wood nw = { cur.x1, ny1, cur.x2, ny2, cur.x3, ny3 };
                        visited[cur.x2][ny2][horizontal ? 0 : 1] = true;
                        q.push(nw);
                    }
                } else {
                    is_rotate2 = false;
                }
            }  
            // 회전
            if(abs(cur.x1 - cur.x2) >= 1) { // 세로 -> 가로
                nx1 = cur.x2, ny1 = cur.y2 - 1, nx3 = cur.x2, ny3 = cur.y2 + 1;
                if(check_boundary(nx1) && check_boundary(ny1) && check_boundary(nx3) && check_boundary(ny3)) {
                    if(!visited[cur.x2][cur.y2][horizontal ? 1 : 0] && is_rotate2) {
                        Wood nw = { nx1, ny1, cur.x2, cur.y2, nx3, ny3 };
                        visited[cur.x2][cur.y2][horizontal ? 1 : 0] = true;
                        q.push(nw);
                    }
                }
            } else { // 가로 -> 세로
                nx1 = cur.x2 - 1, ny1 = cur.y2, nx3 = cur.x2 + 1, ny3 = cur.y2;
                if(check_boundary(nx1) && check_boundary(ny1) && check_boundary(nx3) && check_boundary(ny3)) {
                    if(!visited[cur.x2][cur.y2][horizontal ? 1 : 0] && is_rotate1) {
                        Wood nw = { nx1, ny1, cur.x2, cur.y2, nx3, ny3 };
                        visited[cur.x2][cur.y2][horizontal ? 1 : 0] = true;
                        q.push(nw);
                    }
                }
            }
        }
        time++;
    }

    return 0;
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf(" %c", &map[i][j]);
            if(map[i][j] == 'B') {
                Point p = { i, j };
                v.push_back(p);
            } else if(map[i][j] == 'E') {
                Point p = { i, j };
                end_point.push_back(p);
            }
        }
    }

    printf("%d\n", move());   
}

/**
 * 노가다..
 * 맨 처음에 visited[MAX][MAX][MAX][MAX][MAX][MAX] 이렇게 만들었는데 컴파일 에러가 났음
 * 그래서 중간점을 기준으로 가로인지 세로만 체크하면 됨
 * **/