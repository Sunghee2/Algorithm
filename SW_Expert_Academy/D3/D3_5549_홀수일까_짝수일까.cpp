#include <iostream>
#include <string>
using namespace std;

int main() {
    int testcase;
    string num;
    string arr[2] = {"Even", "Odd"};
    cin >> testcase;
    for(int tc = 1; tc <= testcase; tc++) {
        cin >> num;
        int last_num = num.at(num.length() - 1) - '0';
        printf("#%d %s\n", tc, arr[last_num % 2].c_str());
    }
}