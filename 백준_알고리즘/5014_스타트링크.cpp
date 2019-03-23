#include <cstdio>
#include <queue>
using namespace std;

int f, s, g, u, d;
bool visited[1000001] = { 0 };
int num[1000001] = { 0 };

int bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty()) {
        int s = q.front();
        q.pop();

        if(s == g) {
            return num[s];
        }

        int next_s = s + u;
        if(1 <= next_s && next_s <= f && !visited[next_s]) {
            num[next_s] = num[s] + 1;
            visited[next_s] = true;
            q.push(next_s);
        } 

        next_s = s - d;
        if(1 <= next_s && next_s <= f && !visited[next_s]) {
            num[next_s] = num[s] + 1;
            visited[next_s] = true;
            q.push(next_s);
        }
    }

    return -1;
}

int main() {
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

    int ans = bfs(s);
    if(ans == -1) printf("use the stairs\n");
    else printf("%d\n", ans);

}

/**
 * 현재 위치를 큐에 넣고 뽑으면서 +u, -d함
 * 해당 좌표 방문하지 않았으면 큐에 넣고 num(거리)도 현재 위치 거리 + 1 해서 넣음.
 * 계속 반복.
 * **/