#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

typedef pair<int, int> p;
bool cmp(const p& p1, const p& p2) {
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second > p2.second;
}

int main() {
    int n, k, input;
    long long price = 0;
    scanf("%d %d", &n, &k);

    p jewelry[n];
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &jewelry[i].first, &jewelry[i].second);
    }

    multiset<int> bag;
    for(int i = 0; i < k; i++) {
        scanf("%d", &input);
        bag.insert(input);
    }

    sort(jewelry, jewelry + n, cmp);

    multiset<int>:: const_iterator iter;
    for(int i = 0; i < n; i++) {
        iter = bag.lower_bound(jewelry[i].first);
        if(iter == bag.end()) {
            continue;
        }
        bag.erase(iter, next(iter));
        price += jewelry[i].second;
    }   

    printf("%lld\n", price);
}

/**
 * 그리디 알고리즘
 * 
 * 처음에는 bag를 vector에 넣어서 O(nk)로 풀었음(자바때에도..).
 * 보석 크기 큰 것부터 가방 작은 것 찾기 위해서. => 시간 초과..
 * 
 * upper_bound와 lower_bound 개념을 잘 몰라서 많이 헤맨 문제..
 * upper_bound : k보다 큰 수
 * lower_bound : k 이상인 수 
 * 
 * 여기서는 보석크기 큰 순서대로 정렬을 하고
 * 그 순서대로 맞는 가방을 찾는다 => lower_bound(왜냐하면 보석무게와 가방무게가 동일해도 넣을 수 있으므로)
 * 
 * cmp함수 인자때문에 pair<int, int> 타입을 p라고 지정함.
 * **/