#include <iostream>
using namespace std;

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    int roller_coaster[r][c];

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &roller_coaster[i][j]);
        }
    }

    if((r % 2 == 0) && (c % 2 == 0)) {
        int min = roller_coaster[0][0];
        int x, y;
        for(int i = 0; i < r; i++) {
            if(i % 2 == 0) {
                for(int j = 1; j < c; j += 2) {
                    if(min > roller_coaster[i][j]) {
                        min = roller_coaster[i][j];
                        x = i;
                        y = j;
                    }
                }
            } else {
                for(int j = 0; j < c; j += 2) {
                    if(min > roller_coaster[i][j]) {
                        min = roller_coaster[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }     



    } else if((r % 2 == 0) && (c % 2 == 1)) {
        for(int i = 0; i < r - 2; i++) {
            if(i % 2 == 0) {
                for(int j = 0; j < c - 1; j++) {
                    printf("R");
                }
                printf("D");
            } else {
                for(int j = 0; j < c - 1; j++) {
                    printf("L");
                }
                printf("D");                
            }
        }

        for(int i = 0; i < c; i++) {
            if(i % 2 == 0) {
                printf("D");
                if(i != c - 1) printf("R");
            } else {
                printf("TR");
            }
        }
    } else {
        for(int i = 0; i < r; i++) {
            if(i % 2 == 0) {
                for(int j = 0; j < c - 1; j++) {
                    printf("R");
                }
                if(i != r - 1) printf("D");
            } else {
                for(int j = 0; j < c - 1; j++) {
                    printf("L");
                }
                if(i != r - 1) printf("D");                
            }
        }
    }
}

/**
 * 그리디 알고리즘
 * 
 * 각 칸이 양의 정수이므로 최대한 많이 도는 것이 이득임.
 * 1) 행 = 홀수 열 = 홀수 -> 그냥 돌면 됨 전체
 * 2) 행 = 홀수 열 = 짝수 -> 그냥 돌면 됨 전체
 * 3) 행 = 짝수 열 = 홀수 -> 그냥 돌면 됨 전체
 * 4) 행 = 짝수 열 = 짝수 -> 
 * 
 * **/