#include <cstdio>

int main() {
    int testcase, num1, num2;
    scanf("%d", &testcase);

    for(int i = 1; i <= testcase; i++) {
        scanf("%d %d", &num1, &num2);
        if(num1 < num2) {
            printf("#%d <\n", i);
        } else if(num1 > num2) {
            printf("#%d >\n", i);
        } else {
            printf("#%d =\n", i);
        }
    }
}