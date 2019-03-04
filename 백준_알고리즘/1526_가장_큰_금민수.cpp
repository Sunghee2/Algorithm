#include <iostream>
using namespace std;

int n, ans = 0;

void findNum(int num) {
    if(num > n) return;
    if(ans < num) ans = num;

    findNum((num * 10) + 4);
    findNum((num * 10) + 7);
}

int main() {
    scanf("%d", &n);

    findNum(4);
    findNum(7);

    printf("%d\n", ans);
}

/**
 * 뒤에 4와 7을 붙이면서 재귀를 돌고 나보다 큰 수가 나오면 종료함..!
 * **/

/**
이거는 위 코드보다 메모리가 적었던 함수
위 함수는 4, 7부터 시작해서 올라갔던 반면 이것은 for문보면 n에서 하나하나 빼면서 실행
그리고 chk 함수에서 숫자 한자리수 4, 7인지 확인하고 아니면 중간에 나와서 false를 내뱉음
true인 것이 가장 큰 금민수가 되는 것.

bool chk(int n) {
    while(n) {
        if(!(n%10 == 4 || n%10 == 7)) return false;
        n /= 10;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = n; i >= 4; i--) {
        if(chk(i)) {
            printf("%d\n", i);
            break;
        }
    }
}

**/