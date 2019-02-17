#include <iostream>
#include <queue>
using namespace std;

int n;
int matrix[101][101];

typedef struct {
    int x, y;
} Point;

void bfs() {
    queue<Point> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 1) {
                Point point = {i, j};
                q.push(point);
            }
        }

        while(!q.empty()) {
            int x = q.front().x;
            int y = q.front().y;
            q.pop();

            for(int j = 0; j < n; j++) {
                if((matrix[y][j] == 1) && (matrix[x][j] == 0)) {
                    matrix[x][j] = 1;
                    Point new_point = {x, j};
                    q.push(new_point);
                }
            }
        }
    }
}

void printMatrix() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    bfs();
    printMatrix();
}


/**
 * dfs, bfs문제인데 일단 bfs로 해결하려고 했는데 내가 푼 것이 bfs라고 할 수 있는지 모르겠다.
 * dfs는 확실히 아닌데... 솔직히 bfs라고 할 수도 없는듯..
 * 
 * 맨 처음에 첫번째 행을 봄
 * 거기서 1인 것들을 모두 큐에 넣고
 * pop할 때 만약 (1, 3)이라면 3행을 봐서 1인 것을 찾는다.
 * 만약 (3, 5)이 1이라면 (1, 5)를 0이라면 1로 바꿔주고 큐에 넣고
 * 큐가 빌 때까지 반복하고
 * 큐가 비면 다음 행으로 넘어감.
 * **/