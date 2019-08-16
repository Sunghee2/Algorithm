#include <iostream>
#define MAX 101
using namespace std;

int m, n, x, y, end_chk = 1, cur_dir, cnt;
int map[MAX][MAX];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
    cin >> m >> n;

    map[0][0] = 1;

    while(1) {
        int new_x = x + dx[cur_dir];
        int new_y = y + dy[cur_dir];

        if(0 <= new_x && new_x < m && 0 <= new_y && new_y < n && map[new_x][new_y] == 0) {
            x = new_x;
            y = new_y;
            map[new_x][new_y] = 1;
            end_chk++;
        } else if(end_chk == m * n) {
            break;
        } else {
            cur_dir = cur_dir + 1 > 3 ? 0 : cur_dir + 1;
            cnt++;
        }
    } 

    cout << cnt << endl;
}