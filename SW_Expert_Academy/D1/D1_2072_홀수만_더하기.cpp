#include <cstdio>

int main() {
    int testcase, input;
    scanf("%d", &testcase);

    for(int i = 1; i <= testcase; i++) {
        int sum = 0;
        for(int j = 0; j < 10; j++) {
            scanf("%d", &input);
            if(input % 2 == 1) sum += input;
        }
        printf("#%d %d\n", i, sum);
    }
}