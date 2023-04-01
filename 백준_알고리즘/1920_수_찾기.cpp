#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;

int n, m, num;
int arr[MAX];

bool binarySearch(int num) {
    int start = 0;
    int end = n - 1;
    int mid;

    while(end - start >= 0) {
        mid = (start + end) / 2;

        if(arr[mid] == num) return true;
        else if(arr[mid] > num) end = mid - 1;
        else start = mid + 1;
    }

    return false;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf(" %d", &arr[i]);
    }

    sort(arr, arr + n);

    scanf(" %d", &m);
    for(int i = 0; i < m; i++) {
        scanf(" %d", &num);
        // printf("%d\n", binary_search(arr, arr + n, num));
        printf("%d\n", binarySearch(num));
    }
}

/**
 * 이분탐색 stl
 * binary_search(arr, arr + n, num)
 * **/