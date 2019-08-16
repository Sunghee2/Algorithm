#include <iostream>
#include <vector>
#define MAX_LEN 101
using namespace std;

typedef struct {
    int x, y;
} Point;

typedef struct {
    int x; char c;
} Direction;

int n, k, l, cur_dir = 1, cnt;
int map[MAX_LEN][MAX_LEN];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<Point> snake;
vector<Direction> direction;

void move() {
    while(1) {
        cnt++;
        int new_x = snake[0].x + dx[cur_dir];
        int new_y = snake[0].y + dy[cur_dir];

        // 보드 내에 있는 경우
        if(0 <= new_x && new_x < n && 0 <= new_y && new_y < n) {
            for(int j = 0; j < snake.size(); j++) {
                // 자기 자신의 몸에 부딪힌 경우
                if(snake[j].x == new_x && snake[j].y == new_y) {
                    return;
                }
            }
            
            Point new_p = { new_x, new_y };
            snake.insert(snake.begin(), new_p);
            if(map[new_x][new_y] != 1) {
                snake.pop_back();
            } else {
                map[new_x][new_y] = 0;
            }
        } else {
            return;
        }

        // 방향 전환
        if(direction.size() > 0 && direction[0].x == cnt) {
            if(direction[0].c == 'L') {
                cur_dir = cur_dir - 1 < 0 ? 3 : cur_dir - 1;
            } else {
                cur_dir = cur_dir + 1 > 3 ? 0 : cur_dir + 1; 
            }
            direction.erase(direction.begin());
        }
    }
}

int main() {
    int x, y;
    char c;
    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        cin >> x >> y;
        map[x - 1][y - 1] = 1;
    }

    cin >> l;

    for(int i = 0; i < l; i++) {
        cin >> x >> c;
        Direction d = { x, c };
        direction.push_back(d);
    }

    Point p = { 0, 0 };
    snake.push_back(p);

    move();

    cout << cnt << endl;
}