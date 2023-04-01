#include <iostream>
#include <algorithm>
#define MAX 500001
using namespace std;

int n, m, num;
int arr[MAX];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf(" %d", &arr[i]);

    sort(arr, arr + n);

    scanf(" %d", &m);
    for(int i = 0; i < m; i++) {
        scanf(" %d", &num);
        printf("%ld ", upper_bound(arr, arr + n, num) - lower_bound(arr, arr + n, num));
    }
}

/**
 * 숫자 개수를 찾기 위해서
 * 나보다 바로 작은 숫자의 인덱스, 나보다 바로 큰 숫자의 인덱스
 * 차이를 구하면 개수를 얻을 수 있음
 * **/