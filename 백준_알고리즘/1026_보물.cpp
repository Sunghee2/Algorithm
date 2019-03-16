#include <iostream>
#include <algorithm>
using namespace std;

int desc(int a, int b) {
    return a > b;
}

int main() {
    int n, min = 0;
    scanf("%d", &n);

    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    sort(a, a + n);
    sort(b, b + n, desc);

    for(int i = 0; i < n; i++) {
        min += a[i] * b[i];
    }

    printf("%d\n", min);
}