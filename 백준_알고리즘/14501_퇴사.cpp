#include <iostream>
#include <algorithm>
using namespace std;

int n, max_price = 0;
int consulting[15][2];
int incld[15], excld[15];

void dfs(int index, int sum) {
    if(index > n) return;
    if(index == n) {
        max_price = max(max_price, sum);
        return;
    }

    dfs(index + consulting[index][0], sum + consulting[index][1]);
    dfs(index + 1, sum);
}

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &consulting[i][0], &consulting[i][1]);
    }

    dfs(0, 0);

    printf("%d\n", max_price);
}

/**
 * 처음에는 incld, excld를 만들어서 하나하나 메모이제이션하려했는데 필요 없었음.
 * 그냥 현재 날짜를 포함하는지 안포함하는 지에 따라 재귀를 돌리면 됨.
 * 포함하는 경우(16번째줄)는 상담 기간을 더해서 index를 넣고 sum에 해당 날짜 상담료를 더해줌.
 * 포함하지 않는 경우(17번째줄)는 그냥 다음 날짜로 넘어가고 sum도 그대로 넘기면 되는 것.
 * **/