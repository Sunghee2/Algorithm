#include <iostream>
#define MAX 21
#define INF 10000000
using namespace std;

int n;
int min_value = INF;
bool visited[MAX];
int scores[MAX][MAX];

void checkScores() {
    int team1 = 0, team2 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(visited[i] && visited[j]) {
                team1 += scores[i][j];
            } else if(!visited[i] && !visited[j]) {
                team2 += scores[i][j];
            }
        }
    }
    int diff = team1 < team2 ? team2 - team1 : team1 - team2;
    min_value = min_value > diff ? diff : min_value;
}

void dfs(int idx, int cnt) {
    if(cnt == (n / 2)) {
        checkScores();
        return;
    }

    for(int i = idx + 1; i < n; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i, cnt + 1);
        visited[i] = false;
    }
}

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> scores[i][j];
        }
    }

    visited[0] = true;
    dfs(0, 1);

    cout << min_value << endl;
}

/**
 * 맨 처음에 점수가 대칭이 아니라고 해서 scores[i][j] 와 scores[j][i]를 모두 더했음
 * 하지만 생각해보니깐 루프돌면서 모두다 더해지게 됨
 * 
 * 일단 팀에 대한 조합을 하고 (팀은 2개인데 0으로 시작하는 조합만 구하면 나머지는 다른 팀에 속해서 결국 다 구할 수 있음)
 * 해당 조합에 대한 점수를 구함.
 * **/