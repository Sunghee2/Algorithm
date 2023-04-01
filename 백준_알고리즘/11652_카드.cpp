#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

long long n, num;
map<long long, int> m;
vector<pair<long long, int> > v;

bool cmp(pair<long long, int> &p1, pair<long long, int> &p2) {
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second > p2.second;
}

int main()
{
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &num);
        m[num]++;
    }

    map<long long, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++)
    {
        v.push_back(make_pair(iter->first, iter->second));
    }

    sort(v.begin(), v.end(), cmp);
    
    printf("%lld\n", v[0].first);
}