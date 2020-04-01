#include <iostream>
#include <cstring>
#include <queue>
#define MAX 21
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
using namespace std;

int n, max_block;
int map[MAX][MAX];

queue<int> q;

void addBlock(int i, int j) {
    if(map[i][j] != 0) {
        q.push(map[i][j]);
        map[i][j] = 0;
    }
}

void move(int direction) {
    switch(direction) {
        case UP:
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    addBlock(j, i);
                }
                
                int idx = 0;
                while(!q.empty()) {
                    int num = q.front();
                    q.pop();

                    if(map[idx][i] == 0) map[idx][i] = num;
                    else if(map[idx][i] == num) map[idx++][i] *= 2;
                    else map[++idx][i] = num;
                }
            }
            break;
        case DOWN:
            for(int i = 0; i < n; i++) {
                for(int j = n - 1; j >= 0; j--) {
                    addBlock(j, i);
                }

                int idx = n - 1;
                while(!q.empty()) {
                    int num = q.front();
                    q.pop();

                    if(map[idx][i] == 0) map[idx][i] = num;
                    else if(map[idx][i] == num) map[idx--][i] *= 2;
                    else map[--idx][i] = num;
                }
            }
            break;
        case LEFT:
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    addBlock(i, j);
                }

                int idx = 0;
                while(!q.empty()) {
                    int num = q.front();
                    q.pop();

                    if(map[i][idx] == 0) map[i][idx] = num;
                    else if(map[i][idx] == num) map[i][idx++] *= 2;
                    else map[i][++idx] = num;
                }
            }
            break;
        case RIGHT:
            for(int i = 0; i < n; i++) {
                for(int j = n - 1; j >= 0; j--) {
                    addBlock(i, j);
                }

                int idx = n - 1;
                while(!q.empty()) {
                    int num = q.front();
                    q.pop();

                    if(map[i][idx] == 0) map[i][idx] = num;
                    else if(map[i][idx] == num) map[i][idx--] *= 2;
                    else map[i][--idx] = num;
                }
            }
            break;
    }
}

void getMaxBlock() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(max_block < map[i][j]) max_block = map[i][j];
        }
    }
}

void play(int num) {
    if(num > 5) {
        getMaxBlock();
        return;
    }
    
    int tmp_map[MAX][MAX];
    memcpy(tmp_map, map, sizeof(map));
    for(int i = 0; i < 4; i++) {
        move(i);
        play(num + 1);
        memcpy(map, tmp_map, sizeof(tmp_map));
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf(" %d", &map[i][j]);
        }
    }

    play(1);

    printf("%d\n", max_block);
}


// 원래 처음에는 방향 경우의 수를 넥퍼뮤로 조합해서 굳이 맵 카피 없이 하려고 했으나 이렇게 함
// + 처음에 move에 vector를 clear해주면서 사용했는데 queue가 더 깔끔한 것 같아서 바꿈
// 시뮬 너무 힘들다ㅠ => 그래도 분할해서 푸는 게 좋은 방법인 듯.
// 시간이 더 있었다면 move while문도 묶어서 따로 빼는 게 좋았을 듯ㅠㅠ

// play(dfs)로 5번 재귀해서 for문, move 함수를 통해서 움직임. 5번 돌면 최댓값 찾음
// 이 때 이전 보드판을 기억해줘야해서 tmp_map에 저장해줌
// move함수에서는 큐에 0이 아닌 숫자를 넣고 큐가 빌때까지(한 줄) 보드판에 넣으면 됨
// 여기서 한 번 합쳐진 블록은 이미 합쳐질 수 없다 라는 조건이 있는데 이 조건은 합쳐질 때 인덱스를 바꿔줌으로 해결함.