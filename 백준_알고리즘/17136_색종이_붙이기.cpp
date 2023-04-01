#include <iostream>
using namespace std;

int map[10][10];
int paper[5] = { 0, 5, 5, 5, 5, 5 };

void dfs(int x, int y) {
    if(map[x][y] == 0) {
        return;
    }
}

void callDFS() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(map[i][j] == 1) {
                dfs();
            } 
        }
    }
}

int main() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cin >> map[i][j];
        }
    }
}