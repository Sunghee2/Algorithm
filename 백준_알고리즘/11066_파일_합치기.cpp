#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int cost[501][501];
int sum[501];

int main() {
    int tc, n;
    scanf("%d", &tc);
    for(int t = 0; t < tc; t++) {
        scanf("%d", &n);
        memset(cost, 0, 501*501*sizeof(int));

        for(int i = 1; i <= n; i++) {
            scanf(" %d", &cost[i][i]);
            cost[i - 1][i] = cost[i - 1][i - 1] + cost[i][i];
            if(i == 0) sum[i] = cost[i][i];
            else sum[i] = sum[i - 1] + cost[i][i];
        }

        for(int r = 2; r <= n; r++) {
            for(int i = 1; i <= n - r; i++) {
                int j = i + r;
                for(int k = i; k < j; k++) {
                    if(cost[i][j] == 0) cost[i][j] = cost[i][k] + cost[k + 1][j] + sum[j == k + 1? j - 1 : j] - sum[i == k? i : i - 1];
                    else cost[i][j] = min(cost[i][j], cost[i][k] + cost[k + 1][j] + sum[j == k + 1? j - 1 : j] - sum[i == k? i : i - 1]);
                }
            }
        }

        printf("%d\n", cost[1][n]);
    }
}