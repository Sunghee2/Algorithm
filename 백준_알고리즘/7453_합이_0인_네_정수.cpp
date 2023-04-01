#include <iostream>
#define MAX 4001
using namespace std;

int N;
long long cnt = 0;
long long A[MAX], B[MAX], C[MAX], D[MAX], AB[MAX * MAX], CD[MAX * MAX];

void SWAP(int i, int j) {
    long long tmp = CD[j];
    CD[j] = CD[i];
    CD[i] = tmp;
}

void qSort(int l, int r) {
    int L = l, R = r;
    int pv = CD[(l + r) / 2];
    while(L <= R) {
        while(pv > CD[L]) L++;
        while(pv < CD[R]) R--;
        if(L <= R) {
            SWAP(L, R);
            L++;
            R--;
        }
    }
    if(L < r) qSort(L, r);
    if(l < R) qSort(l, R);
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%lld %lld %lld %lld", &A[i], &B[i], &C[i], &D[i]);
    }

    long long idx = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            AB[idx] = A[i] + B[j];
            CD[idx++] = C[i] + D[j];
        }
    }

    qSort(0, idx - 1);

    for(int i = 0; i < idx; i++) {
        long long l = 0, r = idx;

        while(l < r) {
            long long mid = (l + r) / 2;
            if(AB[i] + CD[mid] < 0) l = mid + 1;
            else r = mid;
        }
        long long lower = r;

        l = 0, r = idx;
        while(l < r) {
            long long mid = (l + r) / 2;
            if (AB[i] + CD[mid] <= 0) l = mid + 1;
            else r = mid;
        }

        long long upper = r;
        cnt += upper - lower;
    }

    printf("%lld\n", cnt);
}

/**
 * 일반적으로 찾아나가면 n^4으로 시간초과가 남.
 * 그래서 AB, CD 합을 묶으면 n^2 여기서 이분탐색을 하면 logN => n^2 * logN 임
 * 
 * 아니면 해시테이블을 이용하는 방법!
 * AB[i] 를 해시테이블에 넣어놓고 -CD[j]를 검색하면? 검색은 O(1) => n^2 시간복잡도를 얻을 수 있음
 * **/