#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &a, &b);

        cout << "Case #" << i << ": " << a + b << "\n";
    }
}