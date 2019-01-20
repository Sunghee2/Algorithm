#include <iostream>
using namespace std;

int main() {
    int a, b;

    scanf("%d %d", &a, &b);
    while(a != 0 && b != 0) {
        cout << a + b << "\n";
        scanf("%d %d", &a, &b);
    }
}