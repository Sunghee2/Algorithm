#include <iostream>
#define MAX 1001
using namespace std;

int n, m, ans;
int map[MAX], dice[MAX];

void play(int cur, int num) {
    if(cur >= n - 1) {
        ans = num;
        return;
    }

    play(cur + dice[num] + map[cur + dice[num]], num + 1);
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &map[i]);
    }

    for(int i = 0; i < m; i++) {
        scanf("%d", &dice[i]);
    }

    play(0, 0);

    printf("%d\n", ans);
}

/**
 * 전형적인 dfs, bfs 문제..
 * **/