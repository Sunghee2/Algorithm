#include <iostream>
#define MAXN ((int)1e5)
#define MAXT ((int)1e5) * 4
using namespace std;

int N, M;
int arr[MAXN + 10], tree[MAXT];

void InputData() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) scanf(" %d", &arr[i]);
}

int InitTree(int n, int s, int e) {
    if(s == e) {
        return tree[n] = arr[s];
    }

    int m = (s + e) / 2;
    int l = InitTree(n * 2, s, m);
    int r = InitTree((n * 2) + 1, m + 1, e);
    return tree[n] = l + r;
}

int query(int n, int s, int e, int qs, int qe) {
    if((e < qs) || (qe < s)) return 0;
    if((qs <= s) && (e <= qe)) return tree[n];

    int m = (s + e) / 2;
    int l = query(n * 2, s, m, qs, qe);
    int r = query((n * 2) + 1, m + 1, e, qs, qe);
    return l + r;
}

void Solve() {
    InitTree(1, 1, N);
    while(M--) {
        int qs, qe;
        scanf("%d %d", &qs, &qe);
        int ans = query(1, 1, N, qs, qe);
        printf("%d\n", ans);
    }
}

int main() {
    InputData();
    Solve();
}

/**
 * 세그먼트 트리
 * 
 * 트리 크기
 * 1) 간편하게 * 4
 * 2) int h = (int)ceil(log2(n))
 *    int size = (1 << (h + 1))
 * 
 * 왼쪽 자식노드를 n*2위치로 하려면 1부터 배열이 시작해야한다!(잊지 말기)
 * **/