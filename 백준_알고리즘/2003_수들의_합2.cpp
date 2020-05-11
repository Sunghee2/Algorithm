#include <iostream>
#define MAX 10001
using namespace std;

int N, M, s = 0, e = 0, sum = 0, cnt = 0;
int arr[MAX];

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++) {
        scanf(" %d", &arr[i]);
    }

    while(1) {
        if(sum > M) sum -= arr[s++];
        else if(e == N) break;
        else sum += arr[e++];

        if(sum == M) cnt++;
    }

    printf("%d\n", cnt);
}

/**
 * 투포인터
 * **/