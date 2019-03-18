#include <iostream>
#include <algorithm>
using namespace std;

int n, all_num = 0, num = 0;
int house[26][26];
int house_num[676] = { 0 };
bool visited[26][26] = { 0 };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int index) {
    num++;
    visited[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if((0 <= new_x) && (new_x < n) && (0 <= new_y) && (new_y < n) && (house[new_x][new_y] == 1) && (!visited[new_x][new_y])) {
            dfs(new_x, new_y, index);
        }
    }
}

void call_dfs() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((!visited[i][j]) && (house[i][j] == 1)) {
                num = 0;
                dfs(i, j, all_num);
                house_num[all_num] = num;
                all_num++;
            }
        }
    }    
}

int main() {
    scanf("%d\n", &n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%1d", &house[i][j]);
        }
    }

    call_dfs();
    printf("%d\n", all_num);

    sort(house_num, house_num + all_num);
    for(int i = 0; i < all_num; i++) {
        printf("%d\n", house_num[i]);
    }
}

/**
 * dfs로 풀었음.
 * 이 문제는... 2~3주 전부터 풀었던 문제인데 그때 dfs, bfs를 너무 오랜만에 풀어서 엄청 어렵게 느껴져서
 * 포기하고 있었다ㅠ
 * 하지만 그냥 오늘 도전해보니.. 몇 십분 안에 풀었음ㅠㅠ역시 꾸준히가 중요하다..
 * 
 * call_dfs는 지도에서 1인 것을 찾고
 * 방문하지 않았으면 dfs를 호출하는 함수임.
 * dfs에 들어가면 num을 1 더해주고(num은 한 단지의 집의 수를 의미함) 방문 true로 바꿔줌
 * 그리고 상하좌우로 지도 밖으로 벗어나지 않고, 방문하지 않았고, 1인 경우(집이 있는 경우)
 * 또 dfs를 호출함(같은 단지이므로 all_num은 변하지 않음. all_num은 단지 번호를 의미함).
 * dfs가 끝나고 call_dfs로 돌아오면 집의 수를 센 num을 배열에 넣어줌
 * 왜냐하면 나중에 오름차순으로 정렬해야 하기 때문에 배열에 넣어주는 것임.
 * **/