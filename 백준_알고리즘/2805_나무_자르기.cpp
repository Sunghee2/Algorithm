#include <iostream>
#define MAX 1000001
using namespace std;

long long N, M, l, r, max_len = 0, ans = 0;
long long tree[MAX];

int main() {
    scanf("%lld %lld", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf(" %lld", &tree[i]);
        if(max_len < tree[i]) max_len = tree[i];
    }

    l = 0, r = max_len;
    while(l <= r) {
        long long mid = (l + r) / 2;
        long long sum = 0;

        for(int i = 0; i < N; i++) {
            if(mid < tree[i]) sum += tree[i] - mid;
        }

        if(sum >= M) {
            if(ans < mid) ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    printf("%lld\n", ans);
}

/**
 * 이분탐색 이분 탐색
 * 왼쪽은 0 오른쪽은 가장 큰 나무 길이로 시작해서
 * mid값을 구한 뒤
 * 해당 mid값으로 잘랐을 때 나올 수 있는 나무길이(sum)을 구함
 * sum이 구하고자 하는 나무 길이보다 크면
 * ans 값과 비교해서 넣고 왼쪽을 미드값 + 1 만큼 옮겨줌
 * 만약 sum이 구하고자 하는 나무 길이보다 작으면
 * 오른쪽을 미드값 - 1 만큼 옮겨줌
 * **/