#include <iostream>
#include <string>
using namespace std;

int main() {
    int testcase;
    string str;
    cin >> testcase;

    while(testcase--) {
        cin >> str;
        string ans[5] = { "" };
        for(int i = 0; i < str.length(); i++) {
            if(i == 0) {
                ans[0] += "..#..";
                ans[1] += ".#.#.";
                ans[2] += "#.";
                ans[2] += str.at(i);
                ans[2] += ".#";
                ans[3] += ".#.#.";
                ans[4] += "..#..";
            } else {
                ans[0] += ".#..";
                ans[1] += "#.#.";
                ans[2] += ".";
                ans[2] += str.at(i);
                ans[2] += ".#";
                ans[3] += "#.#.";
                ans[4] += ".#..";
            }
        }

        for(int i = 0; i < 5; i++) {
            cout << ans[i] << endl;
        }
    }

}