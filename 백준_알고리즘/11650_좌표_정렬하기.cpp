#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    scanf("%d", &n);
    vector<pair<int, int> > v(n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &v[i].first, &v[i].second);
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++) {
        printf("%d %d\n", v[i].first, v[i].second);
    }
}