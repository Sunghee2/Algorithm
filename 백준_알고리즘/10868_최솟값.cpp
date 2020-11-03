#include <iostream>
#define MAXN ((int)1e5)
#define MAXT MAXN * 4
using namespace std;

int N, M;
int arr[MAXN + 10], tree[MAXT];

void inputData() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) scanf(" %d", &arr[i]);
}

int getMin(int a, int b) {
    if(a < b) return a;
    return b;
}

int initTree(int n, int s, int e) {
    if(s == e) return tree[n] = arr[s];

    int m = (s + e) / 2;
    return tree[n] = getMin(initTree(n * 2, s, m), initTree((n * 2) + 1, m + 1, e));
}

void printTree() {
    for(int i = 1; i <= N * 2; i++) {
        printf("%d ", tree[i]);
    }
    cout << endl;
}

int query(int n, int s, int e, int qs, int qe) {
    if((e < qs) || (qe < s)) return 2e9;
    if((qs <= s) && (e <= qe)) return tree[n];

    int m = (s + e) / 2;
    return getMin(query(n * 2, s, m, qs, qe), query((n * 2) + 1, m + 1, e, qs, qe));
}

void solve() {
    while(M--) {
        int qs, qe;
        scanf("%d %d", &qs, &qe);
        int ans = query(1, 1, N, qs, qe);
        printf("%d\n", ans);
    }
}

int main() {
    inputData();
    initTree(1, 1, N);
    solve();
}

/**
 * 세그먼트 트리
 * 
 * int 최대값을 987654321로 쓰는 습관때문에 한번 틀렸다.
 * 그 이상의 값이 들어올 수 있기 때문
 * 
 * 결론 = 2e9를 쓰자
 * **/