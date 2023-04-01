#include <cstdio>
#include <math.h>

int main() {
    int testcase, input;
    scanf("%d", &testcase);
    for(int i = 1; i <= testcase; i++) {
        double sum = 0;
        for(int j = 0; j < 10; j++) {
            scanf("%d", &input);
            sum += input;
        }
        printf("#%d %d\n", i, (int) round(sum / 10));
    }
}