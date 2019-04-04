#include <iostream>
#include <cstring>
using namespace std;

int n, max_num = 0;
int arr[100001];

int main() {
    int testcase, a;
    scanf("%d", &testcase);
    for(int tc = 1; tc <= testcase; tc++) {
        scanf("%d", &n);
        max_num = 0;
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < n; i++) {
            scanf(" %d", &a);
            arr[a] = arr[a - 1] + 1;
            max_num = max_num < arr[a]? arr[a] : max_num;
        }
        printf("#%d %d\n", tc, n - max_num);
    }
}

/**
 * 숫자 배열이 입력되었을 때 1씩 증가하는 숫자가 얼마나 있냐를 찾아봐야함.
 * 예를 들어
 * 5 4 6 1 3 2 이면 5,6/1,2 2개가 있고 가장 긴 길이는 2임.
 * 1 2 6 7 3 4 5 이면 1 2 3 4 5 / 6 7로 가장 긴 길이가 5임
 * 
 * 그래서 이 배열 원소 개수에서 가장 긴 길이를 빼면 됨.
 * 위의 가장 긴 길이를 고정시켜놓고 앞, 뒤로 움직이면 됨.
 * 
 * **/