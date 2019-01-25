#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int hamburger[3];
    int beverage[2];

    for(int i = 0; i < 3; i++) {
        scanf("%d", &hamburger[i]);
    }

    for(int i = 0; i < 2; i++) {
        scanf("%d", &beverage[i]);
    }

    sort(hamburger, hamburger + 3);
    sort(beverage, beverage + 2);

    int min_set = hamburger[0] + beverage[0] - 50;

    printf("%d", min_set);
}