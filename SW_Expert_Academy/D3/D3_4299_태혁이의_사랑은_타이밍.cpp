#include <iostream>

int main() {
    int testcase, d, h, m, wind, all = 16511;
    scanf("%d", &testcase);

    for(int i = 1; i <= testcase; i++) {
        scanf("%d %d %d", &d, &h, &m);
        int input_all = (d * 1440) + (h * 60) + m;
        int wind = input_all - all >= 0? input_all - all : -1;
        printf("#%d %d\n", i, wind);
    }
}

/**
 * 그냥 단순히 11/11/11의 분을 모두 구함(변수 all)
 * 그래서 입력받은 d, h, r도 분으로 변환해서 비교하면 됨
 * **/