#include <iostream>
using namespace std;

int T, M, N, x, y, ans;

int gcd(int a, int b) {
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d %d", &M, &N, &x, &y);
        
        m.clear();
        ans = -1;
        int max_cnt = lcm(M, N);
        int sum_x = x, sum_y = y;
        while(sum_x <= max_cnt && sum_y <= max_cnt) {
            if(sum_x == sum_y) {
                ans = sum_x;
                break;
            } else if(sum_x < sum_y) {
                sum_x += M;
            } else {
                sum_y += N;
            }
        }

        printf("%d\n", ans);
    }
}

/**
 * <M:N> 종말의 날은 M, N의 최소공배수인 해임.
 * 그리고 x에 M씩 더하고, y에 N씩 더하면서 만나는 것이 정답임
 * 
 * 맨 처음에는 x에 M씩 더한 것을 맵에 다 넣고 난 뒤
 * y에 N씩 더한 겂이 맵에 있는지 확인하는 방법을 사용했는데 시간 초과 났음..
 * 그래서 x, y 비교하면서 작은 값을 더하는 식으로 바꿨더니 해결.
 * **/