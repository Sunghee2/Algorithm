#include <iostream>

int main() {
    int n;
    scanf("%d", &n);

    if(n < 0) {
        if(n % 2 == 0) printf("-1\n");
        else printf("1\n");
        n *= -1;
    } else if(n == 0) {
        printf("0\n0\n");
        return 0;
    } else {
        printf("1\n");
    }

    int arr[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    if(n > 1) {
        for(int i = 2; i <= n; i++) {
            arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000000;
        }
    }

    printf("%d\n", arr[n]);
}

/**
 * 양수든 음수든 절대값이 동일하면 값의 절대값은 같음.
 * 하지만 음수이고 짝수일 경우는 값이 -로 나옴.
 * **/