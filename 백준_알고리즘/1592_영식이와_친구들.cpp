#include <cstdio>

int n, m, l, ans = 0;
int people[1001] = { 0 };

void game(int person_num) {
    if(person_num > n) return;
    people[person_num]++;
    if(people[person_num] < m) {
        ans++;
        if(people[person_num] % 2 == 0) { // 짝수는 반시계 방향
            // 반시계 방향으로 던질 때 0을 넘어가는지
            if(person_num - l > 0) { 
                game(person_num - l);
            } else {
                game(n - ((l - person_num) % n));
            }
        } else { // 홀수는 시계방향
            // 시계 방향으로 던질 때 n을 넘어가는지
            if(person_num + l <= n) { 
                game(person_num + l);
            } else {
                game((person_num + l) % n);
            }
        }
    }
}

int main() {
    // n: 게임 인원, m: 공을 몇 번 받아야 게임을 종료할지, l: 몇 칸 던질지
    scanf("%d %d %d", &n, &m, &l);
    game(1);
    printf("%d\n", ans);
}