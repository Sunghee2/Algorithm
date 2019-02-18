#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n;
int family[101][101];
bool visited[101];

typedef struct {
    int x, distance;
} Point;

int bfs(int start, int end) {
    queue<Point> q;

    for(int i = 0; i <= n; i++) {
        if(family[start][i] == 1) {
            Point point = {i, 1};
            visited[i] = true;
            q.push(point);
        }
    }

    while(!q.empty()) {
        int x = q.front().x;
        int distance = q.front().distance;
        q.pop();

        if(x == end) return distance;

        for(int i = 0; i <= n; i++) {
            if((family[x][i] == 1) && (i != start) && (!visited[i])) {
                Point new_point = {i, distance + 1};
                visited[i] = true;
                q.push(new_point);
            }
        }
    }

    return -1;
}

int main() {
    int m, start, end, x, y;
    scanf("%d", &n);
    scanf("%d %d", &start, &end);
    scanf("%d", &m);
    memset(visited, 0, sizeof(int));

    for(int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        family[x][y] = family[y][x] = 1;
    }

    printf("%d\n", bfs(start, end));
}


/**
 * bfs로 풀었음.
 * 
 * 맨 처음에 메모리 초과났었는데 visited 체크를 안해줘서 그랬음.
 * 먼저, 53번째 줄에서 입력받은 것을 인접행렬로 만들어줌(family)
 * 그리고 찾으려고 하는 사람(start~end변수)
 * start행에서 1인 열 번호를 큐에 다 넣음.
 * pop하면서 나온 열 번호를 다시 행 번호로 생각해서 그 행에서 1인 열을 찾아서 다시 큐에 넣고
 * distance를 1더해서 넣어줌(반복)
 * 만약 pop하면서 나온 열 번호가 end와 같은 경우 종료하고 distance를 리턴함
 * 만약 큐가 빌 때까지 리턴하지 못하면 이어져있지 않는 것이므로 -1을 리턴함.
 * **/