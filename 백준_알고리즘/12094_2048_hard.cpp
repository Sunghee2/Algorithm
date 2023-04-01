#include <iostream>
#include <cstring>
#include <math.h>
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

    int tmp_max_block = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(tmp_max_block < map[i][j]) tmp_max_block = map[i][j];
        }
    }
    
    if(tmp_max_block * pow(2, 5 - num) < max_block) return;
    
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