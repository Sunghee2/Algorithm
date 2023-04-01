#include <iostream>
#include <string>
using namespace std;

string str, ans = "";

int main() {
    cin >> str;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == 'C' || str[i] == 'A' || str[i] == 'M' || str[i] == 'B' || str[i] == 'R' || str[i] == 'I' || str[i] == 'D' || str[i] == 'G' || str[i] == 'E') continue;
        ans += str[i];
    }
    printf("%s\n", ans.c_str());
}