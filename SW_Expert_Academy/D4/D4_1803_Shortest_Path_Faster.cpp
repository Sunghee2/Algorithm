#include <iostream>
#include <vector>
#include <cstring>
#define MAX 100001
using namespace std;

int tc, n, m, s_vertex, e_vertex, s_edge, e_edge, w;
bool visited[MAX];
long long dist[MAX];
vector<pair<int, int> > graph[MAX];

void dfs(int idx, long long sum) {
    visited[idx] = true;

    for(int i = 0; i < graph[idx].size(); i++) {
        if(dist[graph[idx][i].first] > sum + graph[idx][i].second || !visited[graph[idx][i].first]) {
            dist[graph[idx][i].first] = sum + graph[idx][i].second;
            dfs(graph[idx][i].first, sum + graph[idx][i].second);
        }
    }
}

int main() {
    cin >> tc;
    for(int t = 1; t <= tc; t++) {        
        cin >> n >> m >> s_vertex >> e_vertex;

        memset(visited, false, sizeof(visited));
        memset(graph, 0, sizeof(graph));
        for(int i = 1; i <= n; i++) {
            dist[i] = 9223372036854775806;
        }
        
        for(int i = 0; i < m; i++) {
            cin >> s_edge >> e_edge >> w;
            graph[s_edge].push_back(make_pair(e_edge, w));
            graph[e_edge].push_back(make_pair(s_edge, w));
        }

        dist[s_vertex] = 0;
        dfs(s_vertex, 0);

        cout << "#" << t << " " << dist[e_vertex] << endl;
    }
}