#include <stdio.h>
#define MAXNUM 1000001
#define MAXN 500001
#define MAXT MAXNUM * 4

int N, num;
long long sum = 0;
int a_num[MAXNUM], b_num[MAXN], tree[MAXT];

void printBNum() {
    for (int i = 0; i < N; i++)
    {
        printf("%d ", b_num[i]);
    }
    printf("\n");
}

void initTree() {
    for (int i = 0; i < MAXT; i++) {
        tree[i] = 0;
    }
}

int query(int n, int s, int e, int qs, int qe) {
    if(s > qe || qs > e) return 0;
    if(qs <= s && e <= qe) return tree[n];

    int m = (s + e) / 2;
    return query(n * 2, s, m, qs, qe) + query((n * 2) + 1, m + 1, e, qs, qe);
}

void update(int n, int s, int e, int i) {
    if(s > i || i > e) return;
    if(s == e) {
        tree[n]++;
        return;
    }

    int m = (s + e) / 2;
    tree[n]++;
    update(n * 2, s, m, i);
    update((n * 2) + 1, m + 1, e, i);
}

int main() {
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf(" %d", &num);
        a_num[num] = i;
    }
    for(int i = 0; i < N; i++) {
        scanf(" %d", &num);
        b_num[i] = a_num[num];
    }
    // printBNum();
    initTree();
    for(int i = 0; i < N; i++) {
        sum += query(1, 1, N, b_num[i] + 1, N);
        update(1, 1, N, b_num[i]);
    }
    printf("%llu\n", sum);
}