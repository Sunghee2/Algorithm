#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    for(int i = 0; i < str.length(); i++) {
        printf("%d ", (int) str[i] - 64);
    }
}