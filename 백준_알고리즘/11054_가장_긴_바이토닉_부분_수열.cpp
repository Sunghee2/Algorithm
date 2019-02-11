#include <iostream>
#include <algorithm>
using namespace std;

int len;
int arr[1000], lis[1000] = { 0 }, lds[1000] = { 0 };

void get_lis(int arr[], int lis[], bool is_lis) {
    int index = 0, add_idx;
    int tmp[len];

    tmp[0] = arr[0];
    for(int i = 1; i < len; i++) {
        if(tmp[index] < arr[i]) {
            tmp[++index] = arr[i];
            if(is_lis) lis[i] = index;
            else lis[len - i - 1] = index;
            continue;
        }
        add_idx = lower_bound(tmp, tmp + index, arr[i]) - tmp;
        tmp[add_idx] = arr[i];
        if(is_lis) lis[i] = index;
        else lis[len - i - 1] = index;
    }
}

int main() {
    int max = 0;
    scanf("%d", &len);

    for(int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    
    get_lis(arr, lis, true);
    reverse(arr, arr + len);
    get_lis(arr, lds, false);

    for(int i = 0; i < len; i++) {
        if(max < lis[i] + lds[i] + 1) max = lis[i] + lds[i] + 1;
    }

    printf("%d\n", max);
}

/**
 * get_lis는 lis 구하는 함수.
 * 36번째 줄에 입력받은 숫자 배열을 역순으로 바꾸어서 lis하면 lds를 알 수 있음.
 * 각각 idx별로 lis, lds 구해서 저장한 다음 더해서 가장 큰 값을 찾아서 출력함.
 * **/