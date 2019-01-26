#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef struct {
    int x, y;
} Point;

Point move_point[8] = {{2, 1}, {1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, 2}, {-2, -1}, {-1, -2}};

int bfs(int len, int start_x, int start_y, int end_x, int end_y) {
    queue<Point> q;
    int distance[len][len];
    bool visited[len][len];
    memset(visited, 0, len*len*sizeof(int));

    Point start_point = {start_x, start_y};
    distance[start_x][start_y] = 0;
    visited[start_x][start_y] = true;
    q.push(start_point);

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        if(x == end_x && y == end_y) {
            return distance[x][y];
        }

        for(int i = 0; i < 8; i++) {
            int next_x = x + move_point[i].x;
            int next_y = y + move_point[i].y;


            if(0 <= next_x && next_x < len && 0 <= next_y && next_y < len) {
                if((!visited[next_x][next_y])) {
                    distance[next_x][next_y] = distance[x][y] + 1;
                    visited[next_x][next_y] = true;
                    Point next_point = {next_x, next_y};
                    q.push(next_point);
                } 
            }
        }
    }

    return distance[end_x][end_y];
}


int main() {
    int testcase, len, start_x, start_y, end_x, end_y;
    scanf("%d", &testcase);

    while(testcase-- > 0) {
        scanf("%d", &len);
        scanf("%d %d", &start_x, &start_y);
        scanf("%d %d", &end_x, &end_y);

        printf("%d\n", bfs(len, start_x, start_y, end_x, end_y));
    }
}

/**
 * bfs
 * 
 * 자꾸 bfs에서 방문했는데 distance 작은 경우를 조건문으로 만듦.. bfs는 그냥 도착하면 가장 빠른 것임.. 유의
 * 
 * 테스트 데이터 넣을 때마다 값이 항상 다르게 나왔음 -> 초기화 문제.
 * 초기화가 이렇게 중요한 것을 다시 깨달음... 한참 헤매서 다시는 못까먹을 것...
 * 문제는 bool visited였음. java와 달리 맨 처음에 선언만 하면 혼자 0, 1 랜덤으로 들어가있어서 0으로 초기화해줘야됨.
 * 또 visited 에 변수로 크기를 설정했으면 단순히 {0} 과 같이 초기화 하지못하고 위와 같이 초기화해야됨.
 * 
 * 문제는 그냥 일반 bfs 쉬운 문제였음. 
 * bfs로 8칸 계속 이동하면서 도착하면 출력하면 됨.
 * 
 * **/