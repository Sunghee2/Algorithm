#include <iostream>

int main() {
    int input, sum = 0;

    for(int i = 0; i < 5; i++) {
        scanf("%d", &input);
        sum += input * input;
    }

    printf("%d", sum % 10);
}