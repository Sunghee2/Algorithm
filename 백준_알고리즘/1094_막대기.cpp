#include <cstdio>

int makeStick(int n) {
    int bNum = 0, ans = 0;
    for(int i = 1; n > 0; i *= 10) {
        int digit = n % 2;
        if(digit == 1) ans++;
        bNum += (i * digit);
        n /= 2;
    }
    return ans;
}

int main() {
    int x;
    scanf("%d", &x);

    printf("%d\n", makeStick(x));
}

/**
 * 문제 이해하기가.. 좀 힘들었던 문제...
 * 어차피 자르면 64 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1 라서
 * 입력받은 숫자를 이진수로 변환하는 과정(for)에서 1개수만 세면 되는 것.
 * 
 * 메모리 시간은 동일하지만 더 간단하게는
 * 아래처럼 어차피 n%2의 결과는 1 아니면 0이므로 그냥 ans에 더해주면 되는 것..
 * while(n) {
 *  ans += n % 2;
 *  n >>= 1;
 * }
 * **/