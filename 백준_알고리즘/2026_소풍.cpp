#include <iostream>
#include <cstring>
#define MAX 901
using namespace std;

int n, k, f, num1, num2;
int friend_num[MAX];
bool ok, taken[MAX], are_friends[MAX][MAX];

void printStudent() {
    for(int i = 1; i <= n; i++) {
        if(taken[i]) cout << i << endl;
    }
}

bool checkTaken(int x) {
    for(int i = 1; i <= n; i++) {
        if(taken[i]) {
            if(!are_friends[i][x]) return false;
        }
    }
    return true;
}

void checkFriends(int idx, int cnt) {
    if(ok) return;
    if(cnt == k) {
        ok = true;
        printStudent();
        return;
    }; 

    for(int i = idx + 1; i <= n; i++) {
        if(!taken[i] && are_friends[i][idx]) {
            if(!checkTaken(i)) continue;
            taken[i] = true;
            checkFriends(i, cnt + 1);
            taken[i] = false;
        }
    }
}

int main() {
    cin >> k >> n >> f;

    memset(taken, 0, sizeof(taken));
    memset(are_friends, 0, sizeof(are_friends));
    for(int i = 0; i < f; i++) {
        cin >> num1 >> num2;
        are_friends[num1][num2] = true;
        are_friends[num2][num1] = true;

        friend_num[num1]++;
        friend_num[num2]++;
    }

    for(int i = 1; i <= n; i++) {
        if(ok) break;
        if(friend_num[i] >= k - 1) {
            taken[i] = true;
            checkFriends(i, 1);
            taken[i] = false;
        }
    }

    if(!ok) cout << -1 << endl;
}

/**
 * 맨 처음에 시간초과가 났는데
 * 알고보니 문제를 그냥 잘못읽은 거였음ㅠ
 * 다른 소풍 문제 풀다가 비슷할 줄 알고 대충 읽음...
 * 여기서는 모두가 서로 친구사이여야됨.(내가 이해한 것은 2명끼리만 친구면 되는 줄 알았음 -> 우연치고 예제 답이 바로 나옴ㅎ)
 * 
 * 수정한 부분은 친구 수가 몇 명있는지 확인(friend_num)
 * 애초에 함수 호출할 때 친구 수가 k - 1(-1인 이유는 자기자신) 이상인 것만 호출함.
 * 그리고 checkTaken함수로 여태까지 선택된 것들과 친구인지 확인함.
 * **/