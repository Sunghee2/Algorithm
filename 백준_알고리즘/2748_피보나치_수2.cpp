#include <iostream>

int main() {
    int n;
    scanf("%d", &n);

    long arr[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    if(n >= 2) {
        for(int i = 2; i <= n; i++) {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
    }

    printf("%ld\n", arr[n]);
}

/**
 * dp로 피보나치 수열..
 * 처음에 틀렸었는데 90값을 넣으면 int에 쓰레기 값이ㅠㅠ
 * 항상 맨 처음, 마지막 값 확인하는 습관 기르자..
 * **/