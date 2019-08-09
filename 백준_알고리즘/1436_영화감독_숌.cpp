#include <iostream>
#include <cmath>

int main() {
    int n, cnt = 0, num = 665;
    scanf("%d", &n);

    while(cnt < n) {
        num++;
        int six_num = 0;
        int tmp_num = num;
        int length = log10(num) + 1;
        for(int i = 0; i < length; i++) {
            if(tmp_num % 10 == 6) six_num++;
            else six_num = 0;
            if(six_num > 2) {
                cnt++; 
                break;
            }
            tmp_num = tmp_num / 10;

        }
    }

    printf("%d\n", num);
}

/**
 * 브루트 포스
 * **/