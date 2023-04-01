#include <stdio.h>
#include <algorithm>
using namespace std;

const int LM = 100010;
int N, A[LM], B[LM], ans[LM], tree[LM * 4];

void build(int now, int s, int e) {
    if(s == e) {
        tree[now] = 1;
        return;
    }
    int m = (s + e)/2;
    build(now * 2, s, m);
    build(now * 2 + 1, m + 1, e);
    tree[now] = tree[now * 2] + tree[now * 2 + 1];
}

void update(int now, int s, int e, int cnt, int idx) {
    tree[now]--;
    if(s >= e) {
        ans[idx] = A[s];
        return;
    }
    int lch = now * 2, rch = now * 2 + 1, m = (s + e) / 2;
    if(tree[lch] >= cnt) update(lch, s, m, cnt, idx);
    else update(rch, m + 1, e, cnt - tree[lch], idx);
}

int main() {
    int i;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) scanf("%d", &A[i]);
    for(i = 1; i <= N; i++) scanf("%d", &B[i]);
    sort(A+1, A+1+N);
    build(1, 1, N);
    for(i = N; i > 0; i--) {
        update(1, 1, N, B[i] + 1, i);
    }
    for(i = 1; i <= N; i++) printf("%d\n", ans[i]);
    return 0;
}