#include <iostream>
using namespace std;

int main() {
    char str[80];
    cin >> str;

    for(int i = 0; i < 80; i++) {
        if(('a' <= str[i]) && (str[i] <= 'z')) printf("%c", str[i]-32);
        else printf("%c", str[i]);
    }
}