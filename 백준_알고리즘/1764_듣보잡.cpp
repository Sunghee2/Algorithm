#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
string str;
vector<string> v;

int main() {
    map<string, int> mm;

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str;
        mm[str] = 1;
    }

    for(int i = 0; i < m; i++) {
        cin >> str;
        if(mm[str]) v.push_back(str);
    }

    sort(v.begin(), v.end());

    printf("%lu\n", v.size());
    for(int i = 0; i < v.size(); i++) {
        printf("%s\n", v[i].c_str());
    }
}