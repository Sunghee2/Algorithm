#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, a, b;
vector<int> friends[501];
bool card[501] = { 0 };

void invite() {
    for(int i = 0; i < friends[1].size(); i++) {
        int best_friend = friends[1][i];
        card[best_friend] = true;
        for(int j = 0; j < friends[best_friend].size(); j++) {
            card[friends[best_friend][j]] = true;
        }
    }
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    for(int tc = 1; tc <= testcase; tc++) {
        scanf("%d %d", &n, &m);
        memset(card, 0, sizeof(card));
        memset(friends, 0, sizeof(friends));
        for(int i = 0; i < m; i++) {
            scanf("%d %d", &a, &b);
            friends[a].push_back(b);
            friends[b].push_back(a);
        }

        invite();

        int ans = 0;
        for(int i = 0; i < 501; i++) {
            if(card[i]) ans++;
        }
        printf("#%d %d\n", tc, ans > 0? ans - 1 : 0);
    }
}


/**
 * 인접 리스트로 만들어서 
 * 1에 들어가있는 것 안에 다 찾아봄. 2중for문으로 해결..
 * **/