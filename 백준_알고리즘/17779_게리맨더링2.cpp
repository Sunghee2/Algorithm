#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 21
using namespace std;

int n, all = 0, ans = 987654321;
int map[MAX][MAX], zone[MAX][MAX];

void printZone() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("%d ", zone[i][j]);
        }
        printf("\n");
    }
}

void draw(int x, int y, int d1, int d2) {
    zone[x][y] = 5;

    for (int i = 1; i <= d1; i++) {
		zone[x + i][y - i] = 5;
	}

	for (int i = 1; i <= d2; i++) {
		zone[x + i][y + i] = 5;
	}

	for (int i = 1; i <= d2; i++) {
		zone[x + d1 + i][y - d1 + i] = 5;
	}

	for (int i = 1; i <= d1; i++) {
		zone[x + d2 + i][y + d2 - i] = 5;
	}
}

int countZone(int x, int y, int d1, int d2) {
    int people[5] = { 0, 0, 0, 0, all };

    for(int i = 1; i < x + d1; i++) {
        for(int j = 1; j <= y; j++) {
            if(zone[i][j]) break;
            people[0] += map[i][j];
            zone[i][j] = 1;
        }
    }

    for(int i = 1; i <= x + d2; i++) {
        for(int j = n; j > y; j--) {
            if(zone[i][j]) break;
            people[1] += map[i][j];
            zone[i][j] = 2;
        }
    }

    for(int i = x + d1; i <= n; i++) {
        for(int j = 1; j < y - d1 + d2; j++) {
            if(zone[i][j]) break;
            people[2] += map[i][j];
            zone[i][j] = 3;
        }
    }

    for(int i = x + d2 + 1; i <= n; i++) {
        for(int j = n; j >= y - d1 + d2; j--) {
            if(zone[i][j]) break;
            people[3] += map[i][j];
            zone[i][j] = 4;
        }
    }

    for(int i = 0; i < 4; i++) {
        people[4] -= people[i];
    }

    sort(people, people + 5);

    return people[4] - people[0];
}

void setD() {
    for(int i = 1; i <= n - 2; i++) {
        for(int j = 2; j <= n - 1; j++) {
            for(int d2 = 1; d2 <= n - j; d2++) {
                for(int d1 = 1; d1 <= j - 1; d1++) {
                    if(i + d1 + d2 <= n) {
                        memset(zone, 0, sizeof(zone));
                        draw(i, j, d1, d2);
                        int d = countZone(i, j, d1, d2);
                        ans = ans > d ? d : ans;
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf(" %d", &map[i][j]);
            all += map[i][j];
        }
    }

    setD();
    printf("%d\n", ans);
}

/**
 * 시뮬레이션..
 * 
 * 정답률은 50퍼센트인데 다른 것보다 힘들었음ㅠㅠ구현 어렵다
 * 특히 이런건 자잘자잘한 오타가 많이 나서 디버깅하는데 너무 힘듦..
 * 
 * 우선 조건에 따라서 x, y, d1, d2를 구한 후 (setD)
 * 경계선을 그리고 (draw)
 * 각 구역의 인구 수를 셈 (countZone)
 * **/