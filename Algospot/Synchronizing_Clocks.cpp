#include <iostream>
#include <algorithm>
#define CLOCK 16
#define SWITCH 10
#define INF 100000000
using namespace std;

int t;
int clock_time[CLOCK];
char linked[SWITCH][CLOCK + 1] = {
    "xxx.............",
    "...x...x.x.x....",
    "....x.....x...xx",
    "x...xxxx........",
    "......xxx.x.x...",
    "x.x...........xx",
    "...x..........xx",
    "....xx.x......xx",
    ".xxxxx..........",
    "...xxx...x...x.."
};

// 시계가 모두 12시를 가리키는지 확인
bool isTwelve() {
    for(int i = 0; i < CLOCK; i++) {
        if(clock_time[i] != 12) {
            return false;
        }
    }
    return true;
}

// 시간을 변경하는 함수
void push(int switch_idx) {
    for(int i = 0; i < CLOCK; i++) {
        if(linked[switch_idx][i] == 'x') {
            clock_time[i] += 3;
            if(clock_time[i] == 15) clock_time[i] = 3;
        }
    }
}

int solve(int switch_idx) {
    // 끝까지 왔으면 리턴. 스위치를 누른 횟수이기 때문에 true인 경우 0임
    if(switch_idx == SWITCH) return isTwelve()? 0 : INF;

    int ret = INF;
    // 스위치는 최대 4번 누를 수 있음(4번 누르면 제자리로 돌아오는 것)
    // i(현재 스위치 누른 횟수) + solve(다음 스위치 인덱스)
    for(int i = 0; i < 4; i++) {
        ret = min(ret, i + solve(switch_idx + 1));
        push(switch_idx);
    }
    return ret;
}

int main() {
    cin >> t;
    for(int tc = 0; tc < t; tc++) {
        for(int i = 0; i < CLOCK; i++) {
            cin >> clock_time[i];
        }

        int result = solve(0);
        if(result == INF) cout << -1 << endl;
        else cout << result << endl;
    }
}

/**
 * 맨 처음에 51번 째 줄에 i + 를 넣지 않아서 제대로 된 답이 나오지 않음.
 * 현재 스위치 누른 경우도 꼭 세주기.
 * **/