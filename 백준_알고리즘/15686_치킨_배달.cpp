#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 51
using namespace std;

int n, m, ret = 100000000;
int map[MAX][MAX];
vector<pair<int, int> > house, shop;
bool select_shop[MAX];

void countDist() {
    int sum = 0;

    for(int i = 0; i < house.size(); i++) {
        int min_dist = 100000000;
        for(int j = 0; j < shop.size(); j++) {
            if(select_shop[j]) {
                int dist = abs(house[i].first - shop[j].first) + abs(house[i].second - shop[j].second);
                min_dist = min_dist > dist ? dist : min_dist;
            }
        }
        sum += min_dist;
    }

    ret = ret > sum ? sum : ret;
}

void dfs(int idx, int cnt) {
    if(cnt == m) {
        countDist();
        return;
    }

    for(int i = idx; i < shop.size(); i++) {
        if(select_shop[i]) continue;
        select_shop[i] = true;
        dfs(i, cnt + 1);
        select_shop[i] = false;
    }
}

void chooseShop() {
    dfs(0, 0);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) house.push_back(make_pair(i, j));
            else if(map[i][j] == 2) shop.push_back(make_pair(i, j));
        }
    }

    chooseShop();

    cout << ret << endl;
}

/**
    백트래킹, 완전탐색
    메모리 초과...
**/