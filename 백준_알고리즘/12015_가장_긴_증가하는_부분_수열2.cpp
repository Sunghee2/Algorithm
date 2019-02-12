#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int len, index = 0, add_idx;
    scanf("%d", &len);

    int arr[len], lis[len];
    for(int i = 0; i < len; i++) {
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
 * lower_bound가 계속 음수로 나왔음 -> 알고보니 뒤에 - lis를 - arr로 씀ㅜ
 * 
 * 만약 lis 마지막 원소보다 크면 lis 마지막에 추가하면 됨. 그래서 index에 1추가해서 넣어주면 됨.
 * 아닌 경우 lower_bound를 통해 index찾아서 변경해줌.
 * **/