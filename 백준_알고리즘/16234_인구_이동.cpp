#include <iostream>
#include <cstring>
#include <vector>
#define MAX 51
using namespace std;

int n, l, r;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int land[MAX][MAX];
bool visited[MAX][MAX];

vector<pair<int, int> > nations;

int dfs(int x, int y) {
    int people = land[x][y];
    visited[x][y] = true;
    nations.push_back(make_pair(x, y));

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < n && 0 <= ny && ny < n) {
            int diff = abs(land[x][y] - land[nx][ny]);
            if (l <= diff && diff <= r && !visited[nx][ny]) {
                people += dfs(nx, ny);
            }
        }
    }
    return people;
}

void move(int avg) {
    for(int i = 0; i < nations.size(); i++) {
        land[nations[i].first][nations[i].second] = avg;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> land[i][j];
        }
    }

    int total = 0;
    while(1) {
        bool moved = false;
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    nations.clear();

                    int avg = dfs(i, j) / nations.size();
                    if(nations.size() > 1) {
                        move(avg);
                        moved = true;
                    }
                }
            }
        }
        if(moved) total++;
        else break;
    }

    cout << total << '\n';
}

// dfs, bfs 모두 가능
// 1. 방문하지 않은 도시 탐색(dfs)
// 2. 위, 아래, 양 옆에 인구 차이가 L 이상, R 이하일 경우 연합국이므로 nations 벡터에 넣어줌
// 3. 탐색(dfs) 결과로 받은 인구 수를 이용하여 평균을 구함
// 4. 연합국 인구 수를 평균으로 바꿈(move 함수)
// 5. 인구 이동이 없을 때까지(moved == false) 반복