#include <iostream>
#include <algorithm>
using namespace std;

class EDGE
{
public:
    int u, v, w;
    bool operator<(const EDGE b)
    {
        this->w < b.w;
    }
};

typedef struct
{
    int num, x, y, z;
} Point;

EDGE edge[300001];
Point point[100001];
int N, parent[100001];
long long cost = 0;

int get_dist(int i, int j)
{
    return min(min(abs(point[i].x - point[j].x), abs(point[i].y - point[j].y)), abs(point[i].z - point[j].z));
}

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

bool cmp_x(Point &a, Point &b)
{
    return a.x < b.x;
}

bool cmp_y(Point &a, Point &b)
{
    return a.y < b.y;
}

bool cmp_z(Point &a, Point &b)
{
    return a.z < b.z;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &point[i].x, &point[i].y, &point[i].z);
        point[i].num = i;
    }

    for (int i = 0; i <= N; i++)
        parent[i] = i;

    int idx = 0;
    sort(point, point + N, cmp_x);
    for (int i = 0; i < N - 1; i++)
    {
        edge[idx].u = point[i].num;
        edge[idx].v = point[i + 1].num;
        edge[idx++].w = get_dist(i, i + 1);
    }
    sort(point, point + N, cmp_y);
    for (int i = 0; i < N - 1; i++)
    {
        edge[idx].u = point[i].num;
        edge[idx].v = point[i + 1].num;
        edge[idx++].w = get_dist(i, i + 1);
    }
    sort(point, point + N, cmp_z);
    for (int i = 0; i < N - 1; i++)
    {
        edge[idx].u = point[i].num;
        edge[idx].v = point[i + 1].num;
        edge[idx++].w = get_dist(i, i + 1);
    }

    sort(edge, edge + idx);
    idx = 0;
    int cnt = 0;

    while (cnt < N - 1)
    {
        if (Find(edge[idx].u) == Find(edge[idx].v))
        {
            idx++;
            continue;
        }
        Union(edge[idx].u, edge[idx].v);
        cost += edge[idx].w;
        idx++;
        cnt++;
    }

    printf("%lld\n", cost);
}

/**
 * N이 너무 커서 간선을 모두 살필 수 없음 -> 메모리초과 났음ㅠㅠ
 * 아직 XXXX
 * **/