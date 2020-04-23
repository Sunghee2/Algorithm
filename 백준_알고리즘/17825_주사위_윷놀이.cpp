#include <iostream>
#include <cstring>
#define MAX 33
#define GOAL 21
using namespace std;

int max_score = 0;
int map[MAX], score[MAX], blue[MAX], check[MAX];
int dice[10], horse[4];

void initMap() {
    for(int i = 0; i < MAX; i++) map[i] = i + 1;
    map[21] = 21;
    map[25] = 31;
    map[27] = 25;
    map[30] = 25;
    map[32] = 20;
}

void initBlue() {
    blue[5] = 22;
    blue[10] = 26;
    blue[15] = 28;
}

void initScore() {
    for(int i = 1; i < 21; i++) score[i] = i * 2;
    score[22] = 13;
    score[23] = 16;
    score[24] = 19;
    score[25] = 25;
    score[26] = 22;
    score[27] = 24;
    score[28] = 28;
    score[29] = 27;
    score[30] = 26;
    score[31] = 30;
    score[32] = 35;
}

void dfs(int num, int sum) {
    if(num == 10) {
        max_score = sum > max_score? sum : max_score;
        return;
    }

    for(int i = 0; i < 4; i++) {
        int cnt = dice[num];
        int np = horse[i];
        int p = np;

        if(blue[np]) {
            np = blue[np];
            cnt--;
        }

        while(cnt--) {
            np = map[np];
        }

        if(np != GOAL && check[np]) continue;

        check[p] = false;
        check[np] = true;
        horse[i] = np;

        dfs(num + 1, sum + score[np]);

        check[p] = true;
        check[np] = false;
        horse[i] = p;
    }
}

int main() {
    for(int i = 0; i < 10; i++) {
        scanf(" %d", &dice[i]);
    }

    initMap();
    initBlue();
    initScore();

    dfs(0, 0);

    printf("%d\n", max_score);
}

/**
 * 이 문제를.. 실제 시험장에서 봤으면 멘붕이었을듯...
 * 배열을 직접 만드는 방법 밖에 생각 안 났는데.. 검색해보니깐 다들 그렇게 푸셨음..
 * 이런 문제는 항상 실수로 디버깅이 오래걸림ㅠ
 * 25칸에서 다음 칸이 31인데 안 적어줘서 한참 프린트함..
 * 
 * 꼭 다시 풀어보기...
 * 윷놀이 판을 map을 이용해서 다음 칸으로 갈 수 있는 수를 적고
 * blue에는 파란색칸일 때 이동할 수 있는 수를 적고
 * score에는 점수를 적음.
 * 
 * 말 이동은 dfs(백트래킹)로 구현하였음
 * **/