#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool desc(int a, int b) {
    return a > b;
}

int main() {
    int n, dough_price, topping_price, dough_calorie, all_calorie = 0, topping_num = 0;
    cin >> n >> dough_price >> topping_price >> dough_calorie;
    
    int topping_calorie[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &topping_calorie[i]);
    }

    sort(topping_calorie, topping_calorie + n, desc);

    double result = dough_calorie / dough_price;
    for(int i = 0; i < n; i++) {
        if((topping_calorie[i] / topping_price) > result) {
            all_calorie += topping_calorie[i];
            topping_num++;
        } else {
            break;
        }
        result = (all_calorie + dough_calorie) / (dough_price + (topping_price * topping_num));
    }

    printf("%d", (int) floor(result));
}

/**
 * 그리디 알고리즘
 * 
 * cin, scanf 섞어 쓴 이유는 계속 입력이 겹쳐서 나옴.. 
 * 버퍼를 비워야하는데 하나 입력하고 비우고 하기 그래서 걍 겹쳐씀..
 * 
 * 토핑 칼로리 배열 내림차순으로 정렬해줌(어차피 토핑 가격은 똑같으므로 칼로리가 중요)
 * 토핑 칼로리 배열 크키만큼 for문 돌면서 result계산함(최고값이기 때문에 계속 계산해서 비교해줘야됨)
 * 작은게 나오면 break해서 더이상 비교하지 않음.
 * **/