#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> s;
int arr[4][4];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

typedef struct {
    int x, y;
} Point;

void dfs(Point p, string str, int num) {
    if(num > 6) {
        s.insert(str);
        return;
    }

    str += to_string(arr[p.x][p.y]);

    for(int i = 0; i < 4; i++) {
        int next_x = p.x + dx[i];
        int next_y = p.y + dy[i];
        if((0 <= next_x) && (next_x < 4) && (0 <= next_y) && (next_y < 4)) {
            Point next_p = { next_x, next_y };
            dfs(next_p, str, num + 1);
        }
    }
}

int main() {
    int testcase;
    cin >> testcase;

    for(int i = 1; i <= testcase; i++) {
        s.clear();
        for(int j = 0; j < 4; j++) for(int k = 0; k < 4; k++) cin >> arr[j][k];
        
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k++) {
                Point start = { j, k };
                dfs(start, "", 0);
            }
        }

        printf("#%d %lu\n", i, s.size());
    }
}