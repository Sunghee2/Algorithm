#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int arr[1001][1001];

int main() {
    int testcase;
    scanf("%d", &testcase);
    for(int tc = 1; tc <= testcase; tc++) {
        scanf("%d %d", &n, &m);
        memset(arr, 0, sizeof(arr));

        int sum = n * m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] == 0) {
                    if(i + 2 < n && arr[i + 2][j] == 0) {
                        arr[i + 2][j] = 1; sum--; 
                    }
                    if(j + 2 < m && arr[i][j + 2] == 0) {
                        arr[i][j + 2] = 1; sum--;
                    }
                }
            }
        }
        printf("#%d %d\n", tc, sum);
    }
}

/**
 * 그냥 이중 for문으로 전체 돌면서 거리가 2인 것을 삭제함.
 * **/