#include <iostream>
#define MAXN 1000010
#define MAXT MAXN * 4
#define MOD 1000000007
using namespace std;

int N, M, K;
int arr[MAXN];
long long tree[MAXT];

long long initTree(int n, int s, int e)
{
    if (s == e)
        return tree[n] = arr[s] % MOD;

    int m = (s + e) / 2;
    return tree[n] = ((initTree(n * 2, s, m) * initTree((n * 2) + 1, m + 1, e)) % MOD);
}

long long query(int n, int s, int e, int qs, int qe)
{
    if (s > qe || e < qs)
        return 1;
    if (qs <= s && e <= qe)
        return tree[n];

    int m = (s + e) / 2;
    return ((query(n * 2, s, m, qs, qe) * query((n * 2) + 1, m + 1, e, qs, qe)) % MOD);
}

long long update(int n, int s, int e, int index, int pre, int next)
{
    if (index < s || e < index)
        return tree[n];
    if (s == e)
        return tree[n] = next;

    int m = (s + e) / 2;
    return tree[n] = (update(n * 2, s, m, index, pre, next) * update((n * 2) + 1, m + 1, e, index, pre, next) % MOD);
}

void printTree()
{
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", tree[i]);
    }
    cout << endl;
}

void inputData()
{
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++)
        scanf(" %d", &arr[i]);
}

void solve()
{
    int a, b, c;
    initTree(1, 1, N);
    //printTree();
    for (int i = 0; i < M + K; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1)
        {
            update(1, 1, N, b, arr[b], c);
            //printTree();
        }
        else if (a == 2)
        {
            long long ret = query(1, 1, N, b, c);
            printf("%lld\n", ret);
        }
    }
}

int main()
{
    inputData();
    solve();
}

/**
세그먼트 트리 곱
구간 합과 다르게 곱이기 때문에 범위에 벗어난 값은 1, 본인 값을 넘겨줘야함(아니면 계속 값이 0으로 나타나게 됨)
**/