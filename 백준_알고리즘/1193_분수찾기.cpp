#include <iostream>
using namespace std;

int main() {
    int x, numerator, denominator, num = 1;
    cin >> x;

    while(x > num) {
        x -= num;
        num++;
    }

    if(num % 2 == 1) {
        numerator = num;
        denominator = 1;
        while(--x > 0) {
            numerator--;
            denominator++;
        }
    } else {
        numerator = 1;
        denominator = num;
        while(--x > 0) {
            numerator++;
            denominator--;
        }
    }

    printf("%d/%d\n", numerator, denominator);
}