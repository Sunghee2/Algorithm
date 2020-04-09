#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 21
using namespace std;

typedef struct {
    int x, y, dist;
} Fish;

typedef struct {
    int x, y, size, eat;
} Shark;

int n, t = 0;
int map[MAX][MAX];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
bool visited[MAX][MAX];
Shark s;

struct cmp {
	bool operator()(Fish &f1, Fish &f2) {
		if (f1.dist == f2.dist) {
			if (f1.x == f2.x) return f1.y > f2.y;
            else return f1.x > f2.x;
		}
		return f1.dist > f2.dist;
	}
};

bool bfs() {
    queue<Fish> q;
    priority_queue<Fish, vector<Fish>, cmp> pq;
    Fish shark = { s.x, s.y, 0 };
    visited[s.x][s.y] = true;
    q.push(shark);

    while(!q.empty()) {
        Fish fish = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = fish.x + dx[i];
            int ny = fish.y + dy[i];

            if(0 > nx || nx >= n || 0 > ny || ny >= n) continue;
            if(visited[nx][ny] || map[nx][ny] > s.size) continue;

            visited[nx][ny] = true;
            Fish f = { nx, ny, fish.dist + 1 };
            q.push(f);
            if(map[nx][ny] < s.size && map[nx][ny] != 0) {
                pq.push(f);
            }
        }
    }

    if(!pq.empty()) {
        Fish fish = pq.top();
        s.x = fish.x;
        s.y = fish.y;
        t += fish.dist;
        map[fish.x][fish.y] = 0;
        if(++s.eat == s.size) {
            s.size++;
            s.eat = 0;
        }
        memset(visited, false, sizeof(visited));

        return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 9) {
                s.x = i;
                s.y = j;
                s.size = 2;
                s.eat = 0;
                map[i][j] = 0;
            }
        }
    }

    while(bfs());
    printf("%d\n", t);    
}

/**
 * 생각없이 48번째 줄에 n이 아닌 MAX를 넣어서 한참 디버깅한 문제..
 * 우선순위 큐 + bfs를 이용해 풀이함
 * 
 * 조건
 * 1. 처음 아기상어 크기 : 2
 * 2. 아기상어는 1초에 한 칸씩 이동(상하좌우) but 자신보다 작거나 같은 곳만 지날 수 있음
 * 3. 자신보다 작은 물고기만 먹을 수 있음
 * 4. 먹을 수 있는 물고기가 여러 개인 경우 (가장 가까운 물고기 -> 가장 위쪽에 있는 물고기 -> 가장 왼쪽에 있는 물고기 순으로 먹음)
 * 5. 자신의 크기와 같은 수의 물고기를 먹으면 size++
 * 
 * 큐 q는 상하좌우로 이동할 수 있는 큐임
 * 이동할 수 있는 좌표이면 q에 넣고 만약 아기상어크기보다 물고기 크기가 작으면 우선순위 큐에 넣음
 * 우선순위 큐는 cmp 함수를 통해서 조건 4에 맞춤
 * 만약 우선순위 큐가 비어있지 않으면 가장 상위에 있는 물고기 값을 가져와
 * 아기상어 위치를 바꿔주고 eat, size를 갱신함
 * 우선순위 큐가 비어있으면 92번째의 while루프를 멈춤(먹을 수 있는 물고기가 x)
 * **/