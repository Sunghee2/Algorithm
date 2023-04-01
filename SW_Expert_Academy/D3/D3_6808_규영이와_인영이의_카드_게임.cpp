#include <iostream>
using namespace std;

int win = 0, lose = 0;
int kyu_card[9];

void game(int card[], int num, int kyuyoung, int inyoung) {
    cout << "start!\n";
    for(int i = 0; i < 19; i++) {
        printf("%d ", card[i]);
    }
    cout << endl;
    // if((num >= 5) && ((kyuyoung >= 86) || (inyoung >= 86))) {
    if(num == 9) {
        if(kyuyoung > inyoung) {
            win++;
        } else if(kyuyoung < inyoung) {
            lose++;
        } 
        return;
    }
    // } else if(num == 18) return;

    for(int i = 0; i < 19; i++) {
        if(card[i] == 0) {
            if(kyu_card[num] > i) {
                kyuyoung = kyu_card[num] + i;
            } else if(kyu_card[num] < i) {
                inyoung = kyu_card[num] + i;
            }
            printf("k = %d, i = %d, k_card = %d, i_card = %d\n", kyuyoung, inyoung, kyu_card[num], i);
            card[i] = 3;
            game(card, num + 1, kyuyoung, inyoung);
        }
    }
}

void makeLoop(int card[]) {
    int kyuyoung = 0, inyoung = 0;
    for(int i = 0; i < 19; i++) {
        printf("here??? %d real = %d\n", i, card[i]);
        if(card[i] == 0) {
            if(kyu_card[0] > i) {
                kyuyoung = kyu_card[0] + i;
            } else if(kyu_card[0] < i) {
                inyoung = kyu_card[0] + i;
            }
            card[i] = 3;
            game(card, 1, kyuyoung, inyoung);
        }
    }
}

int main() {
    int testcase, num;
    cin >> testcase;

    for(int i = 1; i <= testcase; i++) {
        int card[19] = { 0 };
        win = 0, lose = 0;
        for(int j = 0; j < 9; j++) {
            cin >> kyu_card[j];
            card[kyu_card[j]] = 1;
        }

        makeLoop(card);
        // game(card, 0, 0, 0);

        printf("#%d %d %d\n", i, win, lose);
    }
}