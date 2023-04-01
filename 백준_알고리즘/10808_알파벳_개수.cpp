#include <iostream>
#include <string>
using namespace std;

string s;
int alphabet[26];

int main() {
    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        alphabet[s[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        printf("%d ", alphabet[i]);
    }
}