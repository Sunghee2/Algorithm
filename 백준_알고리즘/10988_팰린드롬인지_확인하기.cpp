#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
    cin >> str;

    bool flag = true;
    int length = str.length();
    for(int i = 0; i < length / 2; i++) {
        if(str[i] != str[length - i - 1]) {
            flag = false;
            break;
        }
    }

    cout << flag << endl;
}