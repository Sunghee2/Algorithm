#include <iostream>
using namespace std;

int k;
int arr_num[12];
int result_num[6];

void print_route() {
    for(int i = 0; i < 6; i ++) {
        printf("%d ", result_num[i]);
    }
    printf("\n");
}

void dfs(int start, int num) {
    if(num == 6) return print_route();

    for(int i = start; i < k; i++) {
        result_num[num] = arr_num[i];
        dfs(i + 1, num + 1);
    }
} 

int main() {
    while(1) {
        scanf("%d", &k);
        if(k == 0) break;

        for(int i = 0; i < k; i++) {
            scanf("%d", &arr_num[i]);
        }

        dfs(0, 0);

        printf("\n");
    }
}

/**
 * dfs로 풀었음.
 * 
 * 처음에는 dfs하나하나 visited 넣어서 들어오면 true 식으로 했었는데
 * 리턴되면서 실행되야하는데 visited가 똑같다보니 중간에 끊겼음.
 * 리턴된 곳까지 다시 초기화했으면 되었을텐데 그건 너무 복잡해지는 것 같아서 바꿈.
 * 
 * 그래서 지금처럼 숫자 자체를 배열(result_num)에 넣는 것으로 바꿈.
 * 입력받은 배열 처음부터 끝까지 그냥 dfs 돌면서
 * 6개가 다 채워지면 print_route()로 가서 출력함.
 * **/