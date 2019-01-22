#include <iostream>

int main() {
    int price, input;
    scanf("%d", &price);

    for(int i = 0; i < 9; i++) {
        scanf("%d", &input);
        price -= input;
    }

    printf("%d", price);
}