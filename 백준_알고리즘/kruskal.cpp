#include <iostream>
#define MAX 1000;
using namespace std;

class EDGE
{
public:
    int u, v, w;
    bool operator<(const EDGE b)
    {
        return this->w < b.w;
    }
    bool operator>(const EDGE b)
    {
        return this->w > b.w;
    }
}

EDGE edge[MAX];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i].u = u;
        edge[i].v = v;
        edge[i].w = w;
    }

    sort(edge, edge + n);
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
            idx++;
            cnt++;
        }
    }
}