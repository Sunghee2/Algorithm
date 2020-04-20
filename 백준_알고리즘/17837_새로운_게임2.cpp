#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 13
#define H_MAX 11
using namespace std;

typedef struct {
    int x, y, dir;
} Horse;

int n, k, x, y, d, ans = -1;
bool end_flag = false;
int map[MAX][MAX];
Horse horse[H_MAX];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
vector<int> h_map[MAX][MAX];

void printHourse() {
    for(int i = 1; i <= k; i++) {
        printf("%d: (%d, %d) dir: %d\n", i, horse[i].x, horse[i].y, horse[i].dir);
    }
}

void changeDirection(int i) {
    int d = horse[i].dir;

    if(d == 0) horse[i].dir = 1;
    else if(d == 1) horse[i].dir = 0;
    else if(d == 2) horse[i].dir = 3;
    else if(d == 3) horse[i].dir = 2;
}

void move(int num, int nx, int ny, bool is_reverse) {
    int idx, cx = horse[num].x, cy = horse[num].y;
    for(int i = 0; i < h_map[cx][cy].size(); i++) {
        if(h_map[cx][cy][i] == num) {
            idx = i;
            break;
        }
    }

    if(is_reverse) reverse(h_map[cx][cy].begin() + idx, h_map[cx][cy].end());

    for(int i = idx; i < h_map[cx][cy].size(); i++) {
        h_map[nx][ny].push_back(h_map[cx][cy][i]);
        if(h_map[nx][ny].size() >= 4) end_flag = true;
        horse[h_map[cx][cy][i]].x = nx;
        horse[h_map[cx][cy][i]].y = ny;
    }

    while(h_map[cx][cy].size() - idx > 0) h_map[cx][cy].pop_back();
}

void play(int turn) {
    if(turn > 1000) return;

    for(int i = 1; i <= k; i++) {
        int nx = horse[i].x + dx[horse[i].dir];
        int ny = horse[i].y + dy[horse[i].dir];

        if(0 > nx || nx >= n || 0 > ny || ny >= n || map[nx][ny] == 2) {
            changeDirection(i);
            nx = horse[i].x + dx[horse[i].dir];
            ny = horse[i].y + dy[horse[i].dir];

            if(0 > nx || nx >= n || 0 > ny || ny >= n || map[nx][ny] == 2) continue;
        }

        move(i, nx, ny, map[nx][ny] == 1? true : false);
    }

    if(end_flag) ans = turn;
    else play(turn + 1);
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf(" %d", &map[i][j]);
        }
    }

    for(int i = 1; i <= k; i++) {
        scanf("%d %d %d", &x, &y, &d);
        h_map[x - 1][y - 1].push_back(i);
        Horse h = { x - 1, y - 1, d - 1 };
        horse[i] = h;
    }

    play(1);
    printf("%d\n", ans);
}

/**
 * 확실히 struct 배열 만드는 것보다 따로 분리해서 만드는 게 나은 듯.
 * 시뮬은 코드를 빨리 짜는데 디버깅을 너무 오래해서 시간을 잡아먹음ㅠ 이 부분 고민해봐야할듯
 * 여기서는 빨강을 만났을 때 reverse하고 집어넣어서 reverse된 상태의 idx를 뽑아 넣어서 잘못되었었는데...
 * 이럴 때 어떻게 해야할지........ 
 * 그리고 디버깅한다고 turn을 5번으로 제한해놨다가 나중에 까먹고 왜 계속 -1되는지 찾고 있었음.. -> 이런 건 작성할 때 주석도 같이 작성하도록 하자
 * 
 * play로 게임 턴 증가할 때마다 실행하고 for문을 통해 말을 순서대로 움직임
 * 파랑이거나 바깥으로 벗어나는 경우(첫 번째 if문) 방향 바꾼 뒤에 다시 새로 nx, ny를 구한 뒤 또 그 값이 파랑인지 벗어난 값인지 확인
 * 만약 빨강/흰색이면 move함수에 들어가는데 빨강이면 reverse_flag를 true로 만들어 중간에 reverse할 수 있도록 함
 * move 함수는 내 위치를 구한 뒤 내 위치에서 부터 쌓인 애까지 다음 위치로 넣어주고 
 * while문을 통해 삭제해줌
 * **/