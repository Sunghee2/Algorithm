#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int set_price[m];
    int one_price[m];
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &set_price[i], &one_price[i]);
    }

    sort(set_price, set_price + m);
    sort(one_price, one_price + m);

    int min_value = 0;
    if(n <= 6) {
        if(set_price[0] < (one_price[0] * n)) {
            min_value = set_price[0];
        } else {
            min_value = one_price[0] * n;
        }
    } else {
        if(set_price[0] <= (one_price[0] * 6)) {
            min_value = min((set_price[0] * (n / 6)) + (one_price[0] * (n % 6)), set_price[0] * ((n / 6) + 1));
        } else {
            min_value = one_price[0] * n;
        }
    }

    printf("%d", min_value);
}

/**
 * 그리디 알고리즘
 * 
 * 1) 6보다 작은 경우
 *   - 세트 가격 < 낱개로 n개 샀을 때 가격  :  세트로 삼
 *   - 세트 가격 >= 낱개로 n개 샀을 때 가격  :  낱개로 n개 삼
 * 2) 6보다 큰 경우
 *   - 세트 가격 <= 낱개 6개 가격 : min값(세트로 살 수 있는 만큼 사고 나머지 낱개 구매, 세트로 사고 싶은 것보다 많이 삼)
 *   - 세트 가격 > 낱개 6 개 가격 : 낱개로 n개 삼
 * 
 * 여기서 세트 가격 <= 낱개 6개 가격일 때
 * 입력 값이
 * 9 1
 * 1 1 일 경우 세트 2개 구매가 훨씬 좋다는 것을 알 수 있음. 유의
 * **/