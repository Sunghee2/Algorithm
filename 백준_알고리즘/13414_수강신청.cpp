#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int K, L;
string str;
map<string, int> m;
vector<pair<int, string> > v;

int main() {
    cin >> K >> L;
    for(int i = 1; i <= L; i++) {
        cin >> str;
        m[str] = i;
    }

    map<string, int>:: iterator iter;
    for(iter = m.begin(); iter != m.end(); iter++) {
        v.push_back(make_pair(iter -> second, iter -> first));
    }

    sort(v.begin(), v.end());

    int num = min(K, (int) v.size());
    for(int i = 0; i < num; i++){
        cout << v[i].second << "\n";
    }
}

/**
 * 마지막에 K 만큼 출력했었는데 (시간초과)
 * K가 벡터 사이즈보다 큰 경우가 있음 
 * 그래서 27번째 줄처럼 작은 것 확인해서 출력해야함
 * **/