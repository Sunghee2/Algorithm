#include <iostream>
#include <cstring>
using namespace std;

int n;
int tile[1000][5];

int tiling(int index, int state) {
    if(index > n) return 0;
    if((index == n) && (state == 0)) return 1;
    if(tile[index][state] != -1) return tile[index][state];

    // 모두 채워져 있는 경우
    if(state == 0) {
        tile[index][state] = tiling(index + 1, 0) + (2 * tiling(index + 2, 0)) + tiling(index + 1, 1) + tiling(index + 1, 2) + tiling(index + 2, 4);
    } else if(state == 1) { // 위의 2개만 채워져 있는 경우
        tile[index][state] = tiling(index + 1, 0) + tiling(index + 1, 2);
    } else if(state == 2) { // 아래 2개만 채워져 있는 경우
        tile[index][state] = tiling(index + 1, 0) + tiling(index + 1, 1);
    } else if(state == 3) { // 맨 위, 맨 아래만 채워져 있는 경우
        tile[index][state] = tiling(index + 1, 0) + tiling(index + 1, 4);
    } else if(state == 4) { // 가운데 두 개만 채워져 있는 경우
        tile[index][state] = tiling(index + 1, 3);
    }

    return tile[index][state];
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase-- > 0) {
        scanf("%d", &n);

        memset(tile, -1, sizeof(tile));

        printf("%d\n", tiling(0, 0));
    }
}

/**
 * dp문제
 * 
 * 한 줄에서 있을 수 있는 경우 아래와 같이 총 5가지 임. 돌놓기 배운 것처럼 각 경우에서 다음에 어떻게 채울지 생각하고 더하면 됨.
 * 1. 모두 채워져 있는 경우
 * 2. 위의 2개만 채워져 있는 경우
 * 3. 아래 2개만 채워져 있는 경우
 * 4. 맨 위, 맨 아래만 채워져 있는 경우
 * 5. 가운데 두 개만 채워져 있는 경우
 * 각 경우에 따라 다음에 올 수 있는 것을 계속 재귀로 돌려서 넣음.
 * index==n일 때(끝까지 간 경우) 그리고 state가 0일 때(마지막이므로 다 채워져 있어야 됨) 1을 리턴하고
 * 나머지 경우는 0을 리턴함
 * 결국 0, 0(0에서 시작하고 처음도 물론 다 채워져 있어야 하므로 state도 0)을 리턴하고 출력함.
 * 
 * 맨 처음에는 시간초과가 났는데 그 이유는 간 곳을 또 갔기 때문..visited 확인이 없어서임.
 * 그래서 초기화를 -1로 하고 11번째줄처럼 -1이 아니면 그냥 넘어가도록 하니 바로 되었음.
 * **/