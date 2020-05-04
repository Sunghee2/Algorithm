#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 51
using namespace std;

typedef struct {
    int x, y;
} Point;

int N, M, min_dist = 987654321;
int map[MAX][MAX];
bool visited[MAX];
vector<Point> chicken, house;

void calculateDist() {
    int total_dist = 0;
    for(int i = 0; i < house.size(); i++) {
        int dist = 987654321;
        for(int j = 0; j < chicken.size(); j++) {
            if(visited[j]) {
                int tmp = abs(house[i].x - chicken[j].x) + abs(house[i].y - chicken[j].y);
                dist = dist > tmp ? tmp : dist;
            }
        }
        total_dist += dist;
    }

    min_dist = total_dist < min_dist ? total_dist : min_dist;
}

void choiceChicken(int idx, int num) {
    if(num == M) {
        calculateDist();
        return;
    }

    for(int i = idx; i < chicken.size(); i++) {
        if(visited[i]) continue;
        visited[i] = true;
        choiceChicken(i, num + 1);
        visited[i] = false;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            scanf(" %d", &map[i][j]);
            if(map[i][j] == 2) {
                Point p = { i, j };
                chicken.push_back(p);
            } else if(map[i][j] == 1) {
                Point p = { i, j };
                house.push_back(p);
            }
        }
    }

    choiceChicken(0, 0);
    printf("%d\n", min_dist);
}

/**
 * 이전에도 시간초과 났는데 그 방법 그대로 똑같이 해서 또 시간초과 남ㅎ
 * bfs 돌려서 찾았는데 굳이 그럴 필요가 없음ㅠ
 * **/