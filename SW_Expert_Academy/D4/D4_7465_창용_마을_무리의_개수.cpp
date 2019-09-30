#include <iostream>
#include <vector>
#include <cstring>
#define MAX 101
using namespace std;

int t, n, m, p1, p2, ret;
bool visited[MAX];
vector<int> people[MAX];

void dfs(int idx) {
    visited[idx] = true;

    for(int i = 0; i < people[idx].size(); i++) {
        if(!visited[people[idx][i]]) {
            dfs(people[idx][i]);
        }
    }
}

int main() {
    cin >> t;
    for(int tc = 1; tc <= t; tc++) {
        cin >> n >> m;
        ret = 0;
        memset(people, 0, sizeof(people));
        memset(visited, false, sizeof(visited));
        for(int i = 0; i < m; i++) {
            cin >> p1 >> p2;
            people[p1].push_back(p2);
            people[p2].push_back(p1);
        }

        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                ret++;
                dfs(i);
            }
        }

        cout << "#" << tc << " " << ret << endl;
    }
}