#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define MAX 1001
using namespace std;

int n, m, v, s, e;
bool visited[MAX];
vector<int> graph[MAX];

void bfs(int idx) {
    queue<int> q;
    visited[idx] = true;
    q.push(idx);

    while(!q.empty()) {
        int num = q.front();
        q.pop();

        cout << num << " ";

        for(int i = 0; i < graph[num].size(); i++) {
            if(!visited[graph[num][i]]) {
                q.push(graph[num][i]);
                visited[graph[num][i]] = true;
            }
        }
    }
}

void dfs(int idx) {
    cout << idx << " ";
    visited[idx] = true;

    for(int i = 0; i < graph[idx].size(); i++) {
        if(!visited[graph[idx][i]]) {
            dfs(graph[idx][i]);
        }
    }
}

int main() {
    cin >> n >> m >> v;

    for(int i = 0; i < m; i++) {
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    for(int i = 0; i < n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    cout << endl;
    memset(visited, false, sizeof(visited));
    bfs(v);
}

/**
 * 백준에서 내가 실패한 문제에 있길래 시도함..
 * 10달 전 자바했을 때 풀다가 틀린 것 같음..
 * 솔직히 그래프만 만들 수 있다면 쉽게 풀 수 있는 문제
 * **/