#include <iostream>
#include <cstring>
#include <queue>
#define MAX 1001
using namespace std;

int n, m, hx, hy, ex, ey;
int map[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[MAX][MAX][2];

typedef struct {
    int x, y, magic, dist;
} Point;

int bfs() {
    queue<Point> q;
    Point start = { hx - 1, hy - 1, 1, 0 };
    q.push(start);
    visited[hx - 1][hy - 1][1] = true;

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int magic = q.front().magic;
        int dist = q.front().dist;
        q.pop();

        if(x == ex - 1 && y == ey - 1) {
            return dist;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nm = magic;
            
            if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
            if(visited[nx][ny][nm]) continue;

            if(!map[nx][ny]) {
                visited[nx][ny][nm] = true;
                Point new_point = { nx, ny, nm, dist + 1 };
                q.push(new_point);
            } else if(map[nx][ny] && nm) {
                visited[nx][ny][0] = true;
                Point new_point = { nx, ny, 0, dist + 1 };
                q.push(new_point);                
            }
        }
    }

    return -1;
}

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d", &hx, &hy);
    scanf("%d %d", &ex, &ey);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf(" %d", &map[i][j]);
        }
    }

    memset(visited, false, sizeof(visited));
    printf("%d\n", bfs());
}


/**
 * 처음에는 벽을 하나씩 지워서 bfs 돌리는 완탐으로 했는데 시간초과가 났음
 * O(NM)개의 벽을 없애볼 때마다 O(NM) 칸을 BFS해야 하니 최대 O((NM)^2)
 * 문제 이름은 기억안나지만,, 비슷한 문제를 푼 적이 있는데(지금 찾아보니 연구소였음ㅎ) 그것은 2초였던 것으로 기억..(그래서 위와 같이 풀었었음) 
 * 그러나 지금은 1초
 * 그냥 앞으로 이 방식으로 모든 문제를 풀어야될 듯,,
 * 요즘 visited 배열에 x, y 뿐만 아니라 다른 값도 체크하는 문제를 자주 보는 듯,,
 * 
 * 현재 시간복잡도는 visited 사이즈와 동일하기 때문에 O(nm)임
 * 벽을 없앴는지의 여부를 visited에 넣어서 
 * bfs에서 벽을 만났을 때 없앴는지의 여부를 확인하고 
 * 
 * 오늘의 디버깅.. 원인
 * 1. 벽 뚫었는지의 여부를 변수 m으로 썼었는데 행렬 맨 처음 입력받은 m이랑 겹쳤었음....ㅎ..
 * 2. start를 맨처음에 큐에 넣을 때 visited[hx][hy][1]이라고 해놓고 큐에는 {hx,hy,0}을 집어넣음..ㅎ
 * 3. (가장 찾는 데 오래걸렸던..^^) 맵을 0부터 넣어서 시작점을 1씩 빼줘야했는데 까먹음^^ㅎ -> 이럴거면 맵 입력받을 때 1부터 받자;;
 * **/