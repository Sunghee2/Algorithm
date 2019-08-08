#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef struct {
    int x, y;
} Point;

vector<Point> v;
vector<int> graph[103];
bool visited[103];

void dfs(int index) {
    visited[index] = true;

    for(int i = 0; i < graph[index].size(); i++) {
        if(!visited[graph[index][i]]) {
            dfs(graph[index][i]);
        }
    }
}

int main() {
    int t, n, x, y;
    scanf("%d", &t);
    for(int tc = 0; tc < t; tc++) {
        v.clear();
        for(int i = 0; i < 103; i++) {
            graph[i].clear();
        }
        memset(visited, false, sizeof(visited));
        scanf("%d", &n);
        for(int i = 0; i < n + 2; i++) {
            scanf("%d %d", &x, &y);
            Point p = { x, y };
            v.push_back(p);
        }

        for(int i = 0; i < n + 2; i++) {
            for(int j = i; j < n + 2; j++) {
                if(((abs(v[i].x - v[j].x) + abs(v[i].y - v[j].y)) / 50.0) <= 20) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        dfs(0);

        if(visited[n + 1]) {
            printf("happy\n");
        } else {
            printf("sad\n");
        }
    }
}

/**
 * 입력받은 순서대로만, 모든 곳을 거쳐서 가야된다고 생각해서 그런지 틀렸었음ㅠ
 * 그냥 가깝고 맥주 20병 씩 가지고 갈 수 있는 곳만 확인하면 됨.
 * --> dfs 사용.
 * 
 * 알고리즘을 너무 오랜만에 풀어서 그런지 너무 더럽다..
 * **/