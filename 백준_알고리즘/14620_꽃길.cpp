#include <iostream>
#define MAX 10
using namespace std;

int N, min_cost = 987654321;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[5] = { 0, 0, 0, 1, -1 };
int dy[5] = { 0, 1, -1, 0, 0 };

void plantSeed(int num, int cost) {
    if(num == 3) {
        min_cost = min_cost > cost ? cost : min_cost;
        return;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            bool check = false;

            for(int k = 0; k < 5; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(0 > nx || nx >= N || 0 > ny || ny >= N || visited[nx][ny]) {
                    check = true;
                    break;
                }
            }

            if(check) continue;

            int sum = 0;
            for(int k = 0; k < 5; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(0 > nx || nx >= N || 0 > ny || ny >= N) continue;
                visited[nx][ny] = true;
                sum += map[nx][ny];
            }

            plantSeed(num + 1, cost + sum);

            for(int k = 0; k < 5; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if(0 > nx || nx >= N || 0 > ny || ny >= N) continue;
                visited[nx][ny] = false;
            }            
        }
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf(" %d", &map[i][j]);
        }
    }

    plantSeed(0, 0);
    printf("%d\n", min_cost);
}