#include <iostream>

int main() {
    int testcase, n, m;
    scanf("%d", &testcase);

    for(int tc = 0; tc < testcase; tc++) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++) {
            int c1, c2;
            scanf("%d %d", &c1, &c2);
        }
        printf("%d\n", n - 1);
    }
}

/**
 * MST - n개의 정점을 가지는 그래프에 대해 반드시 (n - 1)개의 간선만 사용해야함(모든 정점은 연결하되 사이클은 생기면 안되므로)
 * **/