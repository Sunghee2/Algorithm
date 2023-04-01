#include <iostream>
#include <algorithm>
using namespace std;

class EDGE
{
public:
    int u, v, w;
    bool operator<(const EDGE b)
    {
        return this->w < b.w;
    }
};

int N, M, parent[100001], cost = 0;
EDGE edge[1000001];

int Find(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x != y)
    {
        parent[y] = x;
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i <= N; i++)
        parent[i] = i;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edge[i].u = u;
        edge[i].v = v;
        edge[i].w = w;
    }

    sort(edge, edge + M);
    int idx = 0;
    int cnt = 0;

    while (cnt < N - 2) {
        if (idx >= M) {
            break;
        }
        if (Find(edge[idx].u) == Find(edge[idx].v)) {
            idx++;
            continue;
        } else {
            Union(edge[idx].u, edge[idx].v);
            cost += edge[idx].w;
            idx++;
            cnt++;
        }
    }

    printf("%d\n", cost);
}

/**
 * MST문제 kruskal로 풀었음.
 * 2개의 마을로 분할해야함.
 * MST(n-1)는 모든 집을 연결하는 거라서 n-2로 연결하면 두 마을로 나눌 수 있음!
 * **/