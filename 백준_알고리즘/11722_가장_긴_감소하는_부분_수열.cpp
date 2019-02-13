#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int len, index = 0, add_idx;
    scanf("%d", &len);

    int arr[len], lis[len];
    for(int i = len - 1; i >= 0; i--) {
        scanf("%d", &arr[i]);
    }

    lis[0] = arr[0];
    for(int i = 1; i < len; i++) {
        if(lis[index] < arr[i]) {
            lis[++index] = arr[i];
            continue;
        }
        add_idx = lower_bound(lis, lis + index, arr[i]) - lis;
        lis[add_idx] = arr[i];
    }

    printf("%d\n", index + 1);
}

/**
 * 간단하게 그냥 역순으로 배열에 집어넣고 lis구하면 됨.
 * **/