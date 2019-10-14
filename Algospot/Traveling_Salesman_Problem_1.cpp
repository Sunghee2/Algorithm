#include <iostream>
#include <iomanip>
#include <cstring>
#define MAX 9
using namespace std;

int t, n;
double min_dist;
double dist[MAX][MAX];
bool visited[MAX];

void dfs(int idx, double cur_dist, int cnt) {
    if(cnt == n - 1) {
        min_dist = min_dist > cur_dist? cur_dist : min_dist;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(i, cur_dist + dist[idx][i], cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> t;
    for(int tc = 0; tc < t; tc++) {
        cin >> n;

        min_dist = 10000000;
        memset(dist, 0, sizeof(dist));
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> dist[i][j];
            }
        }

        for(int i = 0; i < n; i++) {
            visited[i] = true;
            dfs(i, 0, 0);
            visited[i] = false;
        }

        cout << setprecision(20) << min_dist << endl;
    }
}

/**
 * n이 8이하여서 dfs + 백트래킹으로 풀 수 있었음.
 * 여기서 맨 처음 값이 이상하게 나온게 double 값 출력할 때 소수 부분이 모두 나오지 않았음
 * #include <iomanip>으로 setprecision() 을 이용해야 전체를 볼 수 있음
 * **/