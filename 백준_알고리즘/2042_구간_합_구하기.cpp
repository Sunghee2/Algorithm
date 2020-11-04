#include <iostream>
#define MAXN ((int)1e6)
#define MAXT MAXN * 4
using namespace std;

int N, M, K;
long long arr[MAXN + 10];
long long tree[MAXT];

void inputData() {
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 1; i <= N; i++) scanf("%lld", &arr[i]);
}

long long initTree(int n, int s, int e) {
    if(s == e) { 
        return tree[n] = arr[s];
    }

    int m = (s + e) / 2;
    return tree[n] = initTree(n * 2, s, m) + initTree((n * 2) + 1, m + 1, e);
}

long long query(int n, int s, int e, int qs, int qe) {
    if((e < qs) || (qe < s)) return 0;
    if((qs <= s) && (e <= qe)) return tree[n];

    int m = (s + e) / 2;
    return query(n * 2, s, m, qs, qe) + query((n * 2) + 1, m + 1, e, qs, qe);
}

void update(int n, int s, int e, int index, long long diff) {
    if((index < s) || (e < index)) return;

    tree[n] += diff;
    if(s == e) return;
    int m = (s + e) / 2;
    update(n * 2, s, m, index, diff);
    update((n * 2) + 1, m + 1, e, index, diff);
}

void solve() {
    long long a, b, c;
    initTree(1, 1, N);
    while(M-- + K > 0) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if(a == 1) { // b번째 수를 c로 변경
            long long diff = c - arr[b];
            arr[b] = c;
            update(1, 1, N, b, diff);
        } else { // b번째 수부터 c번째 수까지 합 출력
            long long ret = query(1, 1, N, b, c);
            printf("%lld\n", ret);
        }
    }
}

int main() {
    inputData();
    solve();
    return 0;
}

/**
 * 세그먼트 트리
 * 
 * 출력초과가 계속 나왔는데 문제는 MAXN
 * 배열을 1부터 시작해놓고서는 1e6그대로 사용해서 문제가 되었다ㅠㅠ
 * **/