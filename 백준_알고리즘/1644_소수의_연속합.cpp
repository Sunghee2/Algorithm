#include <iostream>
#include <cstring>
#include <math.h>
#define MAX 4000001
using namespace std;

int N, cnt = 0;
bool arr[MAX];

int main() {    
    scanf("%d", &N);
    memset(arr, true, sizeof(arr));

    for(int i = 2; i < MAX; i++) {
        if(!arr[i]) continue;
        for(int j = i + i; j < MAX; j += i) {
            arr[j] = false;
        }
    }

    int s = 2, e = 2, sum = 2;
    while(1) {
        if(sum > N) {
            sum -= s;
            while(1) {
                s++;
                if(arr[s] || s == N) break;
            }
        }
        else if(e > N) break;
        else {
            while(1) {
                e++;
                if(arr[e]) {
                    sum += e;
                    break;
                } else if(e == N) break;
            }
        }

        if(sum == N) cnt++;
    }

    printf("%d\n", N == 2? 1 : cnt);
}

/**
에라토스테네스의 체로 소수를 MAX값까지 구함.
다른 투포인트와 달리 인덱스가 값임.
합이 N보다 클 때 sum에 시작값을 빼주고 시작값을 소수가 있는 곳까지 옮김(while무한루프)
마찬가지로 N보다 작을 때 다음 소수 e값을 찾고 sum에 더함
e가 N을 넘어가면 정지함(N넘어가면 합이 N일 수 없음.)
**/