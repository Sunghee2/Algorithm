#include <cstdio>

int main() {
    int testcase, a, b;
    scanf("%d", &testcase);

    for(int i = 1; i <= testcase; i++) {
        scanf("%d %d", &a, &b);
        printf("#%d %d %d\n", i, a / b, a % b);
    }
}