#include <cstdio>

int main() {
    int testcase, input;
    scanf("%d", &testcase);

    for(int i = 1; i <= testcase; i++) {
        int max = 0;
        for(int j = 0; j < 10; j++) {
            scanf("%d", &input);
            if(max < input) max = input;
        }
        printf("#%d %d\n", i, max);
    }
}