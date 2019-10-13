#include <iostream>
#define MAX 21
using namespace std;

int n, s, ret;
int numbers[MAX];

void dfs(int idx, int cnt) {
    if(idx == n) {
        if(cnt == s) ret++;
        return;
    };

    dfs(idx + 1, cnt + numbers[idx]);
    dfs(idx + 1, cnt);
}

int main() {
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    dfs(0, 0);
    if(s == 0) ret--;

    cout << ret << endl;
}

/**
 * 이번 하반기.. 한 대기업 코테 3번으로 나온 문제..
 * (위와 같이 풀었지만 그 때 시간복잡도를 체크 못했었음ㅠ 아마 시간초과났었을 수도..)
 * 여기서는 완탐으로 하면 2^20(선택하거나 넘어가거나) 시간 나옴
 * 
 * 이 문제 맨 처음에는 visited 체크해서 dfs내에 for문 돌렸는데
 * 생각해보니 그냥 단순히 하나씩 넘어가면서 체크해도 되었었음..
 * **/