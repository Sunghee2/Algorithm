#include <cstdio>
#include <math.h>

int main() {
    int num;
    scanf("%d", &num);

    for(int i = 0; i <= num; i++) {
        printf("%d ", (int) pow(2, i));
    }
}