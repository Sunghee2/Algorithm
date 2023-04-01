#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str;
vector<string> v;

int main() {
    cin >> str;

    int j = str.length();
    for(int i = 0; i < str.length(); i++) {
        v.push_back(str.substr(i, j));
        j--;
    }

    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}