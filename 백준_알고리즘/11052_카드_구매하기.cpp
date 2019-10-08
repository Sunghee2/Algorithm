#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int n;
int card[MAX], price[MAX];

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> card[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            price[i] = max(price[i], price[j] + card[i - j]);
        }
    }

    cout << price[n] << endl;
}

/**
 * 처음에는 그리디로 착각하여 (가격/개수) 로 정렬하였음
 * 절대 절대 다시는 xxxx
 * sum(부분의 최적해) != 전체의 최적해
 * **/