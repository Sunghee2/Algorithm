#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

class EDGE {
public:
    int u, v, w;
    bool operator<(const EDGE b)
    {
        return this->w < b.w;
    }
};

EDGE edge[100001];
int parent[MAX], cost = 0;

int find_set(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find_set(parent[x]);
}

void union_set(int x, int y)
{
    int x_set = find_set(x);
    int y_set = find_set(y);

    if (x_set != y_set)
    {
        parent[y_set] = x_set;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i].u = u;
        edge[i].v = v;
        edge[i].w = w;
    }

    sort(edge, edge + m);
    int idx = 0;
    int cnt = 0;

    while (cnt < n - 1)
    {
        if (idx >= m)
        { // 모든 간선 확인했지만 실패
            break;
        }
        if (find_set(edge[idx].u) == find_set(edge[idx].v))
        {
            idx++;
            continue;
        }
        else
        {
            union_set(edge[idx].u, edge[idx].v);
            cost += edge[idx].w;
            idx++;
            cnt++;
        }
    }

    cout << cost << endl;
}

/**
 * 런타임에러 엄청 났었음.. 그 이유는 간선 edge를 1001개로 해서 그런데 10001로 바꿔주니 바로 해결 됨ㅠ
 * 그리고 가장 큰 문제는 class operator< 작성해서 sort하는게 vs에서 컴파일이 안됨ㅠㅠ왜지... 계속 찾아봣는데....ㅠㅠ... 더 알아봐야될 듯.....
 * **/