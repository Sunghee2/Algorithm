#include <iostream>
#include <string>
using namespace std;

int arr[26] = { 2, 3, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1 };
string str1, str2;
bool flag;

int main() {
    int testcase;
    scanf("%d", &testcase);
    for(int tc = 1; tc <= testcase; tc++) {
        cin >> str1 >> str2;
        flag = false;
        if (str1.length() == str2.length()) {
            flag = true;
            for(int i = 0; i < str1.length(); i++) {
                if(arr[str1.at(i) - 'A'] != arr[str2.at(i) - 'A']) {
                    flag = false;
                    break;
                }
            }
        }

        if(flag) printf("#%d SAME\n", tc);
        else printf("#%d DIFF\n", tc);
    }
}