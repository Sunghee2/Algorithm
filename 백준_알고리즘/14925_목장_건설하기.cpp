#include <iostream>
#include <algorithm>
#define MAX 1000
using namespace std;

int m, n, max_num = 0;
int map[MAX][MAX];
int check[MAX][MAX];

void checkSquare() {
    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(!check[i][j]) continue;

            check[i][j] = min(check[i - 1][j], min(check[i][j - 1], check[i - 1][j - 1])) + 1;   
        }
    }
}

void initCheck() {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            check[i][j] = 1;
        }
    }
}

void findMax() {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            max_num = max_num < check[i][j] ? check[i][j] : max_num;
        }
    }   
}

int main() {
    scanf("%d %d", &m, &n);
    initCheck();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf(" %d", &map[i][j]);
            if(map[i][j] != 0) check[i][j] = 0;
        }
    }
    checkSquare();
    findMax();
    printf("%d\n", max_num);
}

/**
 * 정사각형 확인하는 것 dp로 구현
 * **/