#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    scanf("%d", &n);

    while(n-- > 0) {
        scanf("%d,%d", &a, &b);
        cout << a + b << "\n";
    }
}