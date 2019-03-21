#include <iostream>
#include <cstring>
using namespace std;

int n, ans;
int map[301][301];
bool visited[301][301];
int dx[8] = { 0, 0, 1, 1, 1, -1, -1, -1 };
int dy[8] = { 1, -1, 0, 1, -1, -1, 0, 1 };

void dfs(int x, int y) {
    for(int k = 0; k < 8; k++) {
        int new_x = x + dx[k];
        int new_y = y + dy[k];
        if((0 <= new_x) && (new_x < n) && (0 <= new_y) && (new_y < n) && (!visited[new_x][new_y])) {
            visited[new_x][new_y] = true;
            if(map[new_x][new_y] == 0) {
                dfs(new_x, new_y);
            }
        }
    }    
}

void callDFS() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((map[i][j] == 0) && (!visited[i][j])) {
                visited[i][j] = true;
                ans++;
                dfs(i, j);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((map[i][j] != -5) && (!visited[i][j])) {
                visited[i][j] = true;
                ans++;
            }
        }
    }
}

void updateMap() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(map[i][j] == -1) {
                int num = 0;
                for(int k = 0; k < 8; k++) {
                    int new_x = i + dx[k];
                    int new_y = j + dy[k];
                    if((0 <= new_x) && (new_x < n) && (0 <= new_y) && (new_y < n) && (map[new_x][new_y] == -5)) {
                        num++;
                    }
                }
                map[i][j] = num;
            }
        }
    }
}

int main() {
    int testcase;
    char input;
    scanf("%d", &testcase);

    for(int i = 1; i <= testcase; i++) {
        ans = 0;
        memset(visited, 0, sizeof(visited));
        scanf("%d\n", &n);
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                scanf(" %1c", &input);
                if(input == '*') map[j][k] = -5;
                else if(input == '.') map[j][k] = -1;
            }
        }

        updateMap();
        callDFS();

        printf("#%d %d\n", i, ans);     
    }
}

/**
 * 처음에 map을 입력받을 때 *는 -5, .은 -1로 바꿔서 int배열로 입력 받음
 * 그리고 updateMap() 함수에서 -1인 것을 찾아 주위 8방향 지뢰 개수를 세어서 
 * -1을 주위 지뢰 개수로 다시 바꿈.
 * 다음으로 callDFS() 에서 처음 이중for문에서는 0(주위에 지뢰가 없는 경우)를 발견하면 dfs함수를 호출함
 * dfs에서는 8방향을 보고 8방향에 일단 방문했다고 표시하고
 * 8방향 중 0이 있으면 다시 dfs를 호출함.
 * 0인 점을 모두 방문하게 되면 callDFS()에서 두번째 이중포문으로 가게 됨
 * 여기서는 0과 지뢰가 아닌데 아직 방문하지 못한 점들의 개수를 셈.
 * **/