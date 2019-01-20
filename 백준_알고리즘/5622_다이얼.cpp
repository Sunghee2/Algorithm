#include <iostream>
using namespace std;

int main() {
    char alphabet;
    int result = 0;

    for(char alphabet; ~scanf("%c", &alphabet);) {
        switch(alphabet) {
            case 'A': case 'B': case 'C':
                result += 3;
                break;
            case 'D': case 'E': case 'F':
                result += 4;
                break;
            case 'G': case 'H': case 'I':
                result += 5;
                break;
            case 'J': case 'K': case 'L':
                result += 6;
                break;
            case 'M': case 'N': case 'O':
                result += 7;
                break;
            case 'P': case 'Q': case 'R': case 'S':
                result += 8;
                break;
            case 'T': case 'U': case 'V':
                result += 9;
                break;
            case 'W': case 'X': case 'Y': case 'Z':
                result += 10;
                break;
        }
    }

    printf("%d", result);
}