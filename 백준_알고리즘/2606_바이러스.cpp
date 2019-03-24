#include <iostream>
#include <vector>
using namespace std;

int node, edge, virus = 0;
vector<int> adj[101];
bool visited[101] = { 0 };

void dfs(int node_num) {
    visited[node_num] = true;

    for(int i = 0; i < adj[node_num].size(); i++) {
        int new_node = adj[node_num][i];
        if(!visited[new_node]) {
            dfs(new_node);
            virus++;
        }
    }
}

int main() {
    scanf("%d", &node);
    scanf("%d", &edge);

    for(int i = 0; i < edge; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    printf("%d\n", virus);
}

/**
 * 플로이드 와샬 알고리즘이라 써있었지만.. 편한 dfs로 풀었음..(실은 공부하기 귀찮은 것ㅠㅠㅠㅠ정신차리자)
 * 그래도 원래 항상 인접행렬 만들어서 풀었는데 이번에는 vector 인접리스트로 도전,,
 * 1번이 바이러스 걸리는 것이니깐 dfs(1) 호출.
 * dfs에서는 1을 방문했다고 표시하고
 * 인접리스트 1의 노드들을 돌면서 방문하지 않았으면 해당 노드번호로 dfs를 돌음.
 * dfs를 호출할 때마다 virus(웜 바이러스에 걸리게 되는 컴퓨터 수)에 1을 더해주면 됨.
 * **/