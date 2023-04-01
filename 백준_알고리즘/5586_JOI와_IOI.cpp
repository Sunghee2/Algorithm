#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
    cin >> str;
    int cnt_joi = 0, cnt_ioi = 0;
    for(int i = 0; i < str.length() - 2; i++) {
        if(str[i] == 'J' && str[i + 1] == 'O' && str[i + 2] == 'I') cnt_joi++;
        else if(str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I') cnt_ioi++;
    }

    printf("%d\n%d\n", cnt_joi, cnt_ioi);
}