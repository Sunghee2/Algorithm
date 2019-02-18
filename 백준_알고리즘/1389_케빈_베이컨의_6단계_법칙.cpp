#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m; // n: 유저의 수, m: 친구 관계의 수
int friends[5001][5001];
bool visited[5001][5001];

typedef struct {
    int x, y;
} Point;

void getMinPath() {
    queue<Point> q;
    memset(visited, 0, 5001*5001);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(friends[i][j] == 1) {
                visited[i][j] = visited[j][i] = true;
                Point point = {i, j};
                q.push(point);
            }
        }

        while(!q.empty()) {
            int x = q.front().x;
            int y = q.front().y;
            q.pop();

            for(int j = 1; j <= n; j++) {
                if((friends[y][j] > 0)  && (x != j) && ((!visited[x][j]) || (friends[x][j] > friends[y][j] + friends[x][y]))) {
                    friends[x][j] = friends[j][x] = friends[y][j] + friends[x][y];
                    visited[x][j] = visited[j][x] = true;
                    Point new_point = {x, j};
                    q.push(new_point);
                }
            }
        }
    }
}

int getMinUser() {
    int user, min = 5001;
    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= n; j++) {
            sum += friends[i][j];
        }
        if(sum < min) {
            min = sum;
            user = i;
        }
    }

    return user;
}

int main() {
    int tmp_a, tmp_b;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &tmp_a, &tmp_b);
        friends[tmp_a][tmp_b] = friends[tmp_b][tmp_a] = 1;
    }

    getMinPath();

    printf("%d\n", getMinUser());
}

/**
 * bfs, dfs, 플로이드와샬 문제. 이지만 내가 푼 방법은 bfs가 아닌 것 같음...ㅎ
 * 
 * visited 썼음에도 계속 메모리 초과나서...
 * 원래는 dist라는 2차원 배열을 써서 거기에 거리를 따로 저장했음.
 * 그것을 없애고 원래 입력받은 friends 배열에서 숫자를 바꾸는 것으로 변경했더니 해결함.
 * 
 * 대충 11403 경로찾기에서 조금 변경하였음.
 * 한 줄씩 1인 것들을 큐에 넣음.
 * pop할 때 만약 (3, 4)이라면 열 번호였던 4을 행으로 보아서 4행에서 0보다 큰 것들을 찾음.
 * 만약 (4, 5)가 0보다 크다면 (3, 5) = (3, 4) + (4, 5)가 됨. 
 * 왜냐하면 (3, 5)가 되기 위해서 3행에서 4번째를 통해서 5로 갔기 때문임.
 * 그리고 (3, 5)에 원래 값이 있었다면 위의 계산 값이 원래 값보다 작은지 확인해야됨. 최소거리를 구하기 때문..
 * **/