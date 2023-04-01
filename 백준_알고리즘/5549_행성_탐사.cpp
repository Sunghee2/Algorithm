#include <iostream>
#define MAX 1001
using namespace std;

typedef struct {
    int jungle, sea, ice;
} Count;

int N, M, K, a, b, c, d;
char input;
Count map[MAX][MAX];

void calculate() {
    int res_jungle = map[c][d].jungle - map[a - 1][d].jungle - map[c][b - 1].jungle + map[a - 1][b - 1].jungle;
    int res_sea = map[c][d].sea - map[a - 1][d].sea - map[c][b - 1].sea + map[a - 1][b - 1].sea;
    int res_ice = map[c][d].ice - map[a - 1][d].ice - map[c][b - 1].ice + map[a - 1][b - 1].ice;

    printf("%d %d %d\n", res_jungle, res_sea, res_ice);
}

int main() {
    scanf("%d %d", &N, &M);
    scanf("%d", &K);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf(" %c", &input);

            map[i][j].jungle = map[i - 1][j - 1].jungle + map[i - 1][j].jungle + map[i][j - 1].jungle;
            map[i][j].sea = map[i - 1][j - 1].sea + map[i - 1][j].sea + map[i][j - 1].sea;
            map[i][j].ice = map[i - 1][j - 1].ice + map[i - 1][j].ice + map[i][j - 1].ice;

            if(input == 'J') map[i][j].jungle++;
            else if (input == 'I') map[i][j].ice++;
            else map[i][j].sea++;
        }
    }

    while(K--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        calculate();
    }
}