#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

typedef struct {
    int next, cost;
} Node;

int n, v, total;
vector<Node> tree[10001];
bool visited[10001] = { 0, };

void dfs(int now, int dist) {
    visited[now] = true;

    // 현재 거리가 total보다 크면 v에 저장되어있는 정점보다 먼 거리이므로 다시 저장함
    if(total < dist) {
        total = dist;
        v = now;
    }

    // 방문하지 않은 곳 다시 dfs로 돌림
    for(int i = 0; i < tree[now].size(); i++) {
        Node node = tree[now][i];
        if(!visited[node.next]) dfs(node.next, node.cost + dist);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++) {
        int parent, child, edge;
        scanf("%d %d %d", &parent, &child, &edge);
        Node node = { child, edge };
        tree[parent].push_back(node);
        node.next = parent;
        tree[child].push_back(node); // 양방향이므로
    }

    // 임의의 정점에서 가장 먼 정점을 찾음
    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    total = 0;
    // 위의 dfs에서 찾은 가장 먼 정점에서 또 가장 먼 정점을 찾음
    dfs(v, 0);

    printf("%d\n", total);
}

/**
 * 트리라서 인접행렬을 만들면 
 * 각 행마다 열 번호가 겹칠 수 없음. 그래서 계단식처럼 내려감(부모 번호가 작은 것부터 입력)
 * ---------------------------------------------------------------------------
 * 
 * 그리디 - 
 * 1. 트리에서 임의의 정점 v1에서 가장 먼 정점 v2 을 찾음 -> 어느 점에서도 가장 먼 정점이 리프노드가 됨. 루트노드인 경우에도 동일
 * 2. v2와 v2에서 가장 먼 정점 v3사이의 거리를 찾으면 그게 트리의 지름.(경로가 1개 이므로)
 * 
 * 그래서 1, 2를 위해 dfs를 두 번 돌림. dfs내의 if문을 통해 정점과 거리를 갱신하고 for문을 통해 이동함
 * **/