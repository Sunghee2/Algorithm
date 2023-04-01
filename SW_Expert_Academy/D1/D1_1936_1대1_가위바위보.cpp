#include <cstdio>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    if(a == 3) {
        if(b == 2) printf("A");
        else printf("B");
    } else if(a == 2) {
        if(b == 1) printf("A");
        else printf("B");
    } else {
        if(b == 3) printf("A");
        else printf("B");
    }
}