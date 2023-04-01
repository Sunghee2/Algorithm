#include <iostream>
#include <algorithm>
using namespace std;

class EDGE {
public:
    int u, v, w;
    bool operator <(const EDGE b) {
        return this->w < b.w;
    }
};

EDGE edge[200001];
int M, N, parent[200001];
long long cost = 0;

int Find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x != y) {
        parent[y] = x;
    }
}

int main() {
    while(1) {
        scanf("%d %d", &M, &N);
        if(N == 0 && M == 0) break;
        cost = 0;
        for(int i = 0; i <= M; i++) parent[i] = i;
        for(int i = 0; i < N; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            edge[i].u = x;
            edge[i].v = y;
            edge[i].w = z;
            cost += z;
        }

        sort(edge, edge + N);
        int idx = 0;
        int cnt = 0;

        while(cnt < M - 1) {
            if(Find(edge[idx].u) == Find(edge[idx].v)) {
                idx++;
                continue;
            }
            Union(edge[idx].u, edge[idx].v);
            cost -= edge[idx].w;
            idx++;
            cnt++;
        }

        printf("%lld\n", cost);
    }
}

/**
 * MST문제 kruskal로 풀었음.
 * 50퍼에서 계속 틀렸는데 알고보니 테스트케이스가 여러개일 수 있음..
 * 맨 처음에는 맨 마지막에 0 0을 왜 입력받는거지 하고 넘겼는데...ㅎㅎ....
 * 문제를 제대로 잘 읽어야겠다...
 * **/