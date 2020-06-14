#include <iostream>
#define MAX 1000001
using namespace std;

int N, M;
int parent[MAX];

void init()
{
    for (int i = 0; i <= N; i++)
    {
        parent[i] = i;
    }
}

int find_set(int x)
{
    if (x == parent[x])
        return x;
    else
    {
        int p = find_set(parent[x]);
        parent[x] = p;
        return p;
    }
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
    scanf("%d %d", &N, &M);

    init();

    int order, a, b;
    while (M--)
    {
        scanf("%d %d %d", &order, &a, &b);
        if (order == 0)
        {
            union_set(a, b);
        }
        else if (order == 1)
        {
            int a_set = find_set(a);
            int b_set = find_set(b);

            if (a_set != b_set)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
}

/**
 * union find 기본 문제..
 * 
 * 맨 처음에는 문제를 잘못읽었음ㅠㅠ
 * 0~n까지 n+1개인데 초기화를 0~n-1까지함..
 * **/