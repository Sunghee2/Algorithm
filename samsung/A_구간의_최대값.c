#include <stdio.h>
#define MAXN 1000001
#define MAXT MAXN * 4

int N, Q, A, B;
int arr[MAXN];
int tree[MAXT];

int getMax(int a, int b) {
    if(a > b) return a;
    return b;
}

int initTree(int n, int s, int e) {
    if(s == e) return tree[n] = arr[s];
    int m = (s + e) / 2;
    return tree[n] = getMax(initTree(n * 2, s, m), initTree((n * 2) + 1, m + 1, e));
}

int query(int n, int s, int e, int qs, int qe) {
    if(s > qe || qs > e) return 0;
    if(qs <= s && e <= qe) return tree[n];

    int m = (s + e) / 2;
    return getMax(query(n * 2, s, m, qs, qe), query((n * 2) + 1, m + 1, e, qs, qe));
}

int main() {
    scanf("%d %d", &N, &Q);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    initTree(1, 1, N);

    while (Q--) {
        scanf("%d %d", &A, &B);
        printf("%d\n", query(1, 1, N, A, B));
    }
}