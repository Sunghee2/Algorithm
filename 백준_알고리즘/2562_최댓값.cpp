#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main() {
    int input;
    vector<pair<int, int> > num;

    for(int i = 0; i < 9; i++) {
        cin >> input;
        num.push_back(make_pair(input, i + 1));
    }

    sort(num.begin(), num.end(), comp);

    cout << num[0].first << endl << num[0].second << endl;
}