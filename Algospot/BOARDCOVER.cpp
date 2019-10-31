#include <iostream>
#include <cstring>
#define MAX 21
using namespace std;

char input;
int t, h, w;
int board[MAX][MAX];
int cover_type[4][3][2] = {
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {1, 0}, {1, -1}}
};

bool set(int x, int y, int type, int delta) {
    bool ok = true;
    for(int i = 0; i < 3; i++) {
        int nx = x + cover_type[type][i][1];
        int ny = y + cover_type[type][i][0];
        if(nx < 0 || nx >= w || ny < 0 || ny >= h) { // 좌표 밖을 나가버린 경우
            ok = false;
        } else if((board[ny][nx] += delta) > 1 ) { // 이미 덮었는데 또 덮는 경우
            ok = false;
        }
    }
    return ok;
}

int cover() {
    int x = -1, y = -1;
    // 가장 위, 왼쪽에 있는 좌표 구함
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(board[i][j] == 0) {
                x = j;
                y = i;
                break;
            }
        }
        if(y != -1) break; // flag안하고도 쉬운 방법...
    }

    if(y == -1) return 1;
    int ret = 0;
    for(int i = 0; i < 4; i++) {
        if(set(x, y, i, 1)) {
            ret += cover();
        }
        set(x, y, i, -1);
    }

    return ret;
}

int main() {
    cin >> t;
    for(int tc = 0; tc < t; tc++) {
        memset(board, 0, sizeof(board));
        cin >> h >> w;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> input;
                if(input == '#') {
                    board[i][j] = 1;
                }
            }
        }

        cout << cover() << endl;
    }
}

/**
 * 이전 소풍 문제와 비슷했지만...ㅎ..
 * 코테보면서 이런 문제들 자주 봄
 * 
 * 맨 처음에는 cover_type을 막 넣었었는데 그러면 x
 * 맨 위, 맨 왼쪽부터 채운다는 기준으로 상대좌표를 넣어야함.
 * 그리고 항상 이중 포문 flag를 줘서 탈출했는데
 * 애초에 초기값 넣어놓고 탈출하는 게 깔끔한 것 같다(39번째줄)
 * 그리고 -1값을 줘서 다시 지우는 delta도 좋은 것 같음..
 * **/