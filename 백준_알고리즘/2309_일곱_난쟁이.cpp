#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;

bool is_end;
int people[MAX];
bool visited[MAX];

void dfs(int idx, int cnt) {
    if(cnt > 7) {
        if(!is_end) {
            int sum = 0;
            for(int i = 0; i < MAX; i++) {
                if(visited[i]) {
                    sum += people[i];
                }
            }

            if(sum == 100) {
                is_end = true;
                for(int i = 0; i < MAX; i++) {
                    if(visited[i]) cout << people[i] << endl;
                }
            }
        }
        return;
    }
    
    for(int i = idx; i < MAX; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(i, cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    for(int i = 0; i < MAX; i++) {
        cin >> people[i];
    }

    sort(people, people + MAX);

    for(int i = 0; i < 3; i++) {
        if(!is_end) dfs(i, 1);
    }
}

/**
 * 이 문제도 옛날.. 자바했었을 때 틀린 문제..
 * 내 생각에는 당시 조합을 잘 몰랐어서 그런 것 같음
 * 이거 제출했을 때 처음에 한 번 틀렸는데(100%에서 틀림) 그 이유가 100이 되는 결과를 다 출력했음 
 * 1번만 출력해야 됨..
 * 그리고 조합에서 재귀호출할 때 cnt++을 쓰면 cnt값 그대로 호출 되고
 * 그 다음 줄부터 +1 이 적용된다 함..
 * 그래서 ++cnt, cnt + 1을 사용해야함 < 조합 구현할 때 맨날 틀림ㅠ
 * **/