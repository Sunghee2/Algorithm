#include <iostream>
#include <cstring>
using namespace std;

int student;
int choice[100001];
int cycle[100001] = { 0, };
bool visited[100001] = { 0, };

int DFS(int student) {
    if(cycle[student] == -1) return student;
    if((visited[choice[student]]) && (cycle[choice[student]] != -1)) return 0;

    cycle[student] = -1;
    visited[student] = true;
    
    int ret_student = DFS(choice[student]);
    if(ret_student > 0) {
        cycle[student] = 1;
        if(ret_student != student) return ret_student;
        else return 0;
    } else {
        cycle[student] = -2;
        return 0;
    }
}

void callDFS() {
    for(int i = 1; i <= student; i++) {
        if(cycle[i] == 0) {
            DFS(i);
        }
    }
}

int printNum() {
    int num = 0;
    for(int i = 1; i <= student; i++) {
        if(cycle[i] != 1) num++;
    }
    return num;
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d", &student);

        memset(choice, 0, sizeof(choice));
        memset(cycle, 0, sizeof(cycle));
        memset(visited, 0, sizeof(visited));
        
        for(int i = 1; i <= student; i++) {
            scanf("%d", &choice[i]);
        }

        callDFS();
        printf("%d\n", printNum());
    }
}

/**
 * dfs로 사이클 구하는 문제(2668과 거의 동일한 문제)
 * https://github.com/Sunghee2/BOJ-Algorithm-Java/blob/edf25fd2cf359ad5b36e7e4e6700c7899e3f5c64/%EB%B0%B1%EC%A4%80_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/2668/src/Main.java
 * 그래서 2668처럼 풀었더니 98프로에서 시간 초과가 남...
 * 
 * 이것저것 예외처리 하다가 5프로에서 틀리고...
 * 알고보니 예외처리한 곳(방문했는지 체크하는 것)에서 순서를 이상하게 해서...
 * 
 * dfs 돌고 있는 중 지나온 곳은 -1로 바꾸고 만약 dfs 중에 -1을 만나면 사이클이므로 해당 학생 번호를 리턴함
 * 그 번호가 0보다 크면(사이클이라면) cycle배열에 해당 학생이 사이클이라는 표시 = 1으로 저장하고 
 * 현재 학생 번호와 리턴된 학생 번호가 다르면 또 다시 그 학생번호를 리턴하지만(20번째줄)
 * 만약 같다면 거기서 사이클이 끝난 것이므로 0을 리턴함(사이클 끝났다는 의미 21번째줄)
 * 그래서 이 0이 리턴된 cycle[해당 학생 번호]에는 -2를 저장함. 이 -2는 dfs도 끝났고 사이클도 아니라는 의미임.
 * 
 * 그리고 시간초과를 해결한 것은 12번째줄임
 * dfs를 돌기 전 다음 학생번호를 이미 방문했는지 체크하고 cycle[다음 학생 번호] 가 -1이 아닌지 확인함
 * visited만 확인하면 dfs를 돌고 있는 중에 아직 끝나지않았는데도 리턴되는 경우가 있어서 오답처리가 되었음.
 * cycle이 -1인 경우에는 아직 dfs를 돌고있다는 의미이므로 cycle배열원소가 -2 혹은 1인지 확인해야했음.
 * **/
