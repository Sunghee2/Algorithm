#include <iostream>
#define MAX 300001
using namespace std;

int N, B, W, B_idx, ans = 0;
char map[MAX];
int BNum[MAX], WNum[MAX];

int main() {
    scanf("%d %d %d", &N, &B, &W);
    for(int i = 1; i <= N; i++)  {
        scanf(" %c", &map[i]);
        if (map[i] == 'W') {
            BNum[i] = BNum[i - 1];
            WNum[i] = WNum[i - 1] + 1;
        } else {
            BNum[i] = BNum[i - 1] + 1;
            WNum[i] = WNum[i - 1];
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = i; j <= N; j++) {
            printf("(%d, %d) => %d %d\n", i, j, WNum[j] - WNum[i - 1], BNum[j] - BNum[i - 1]);
            int w = WNum[j] - WNum[i - 1];
            int b = BNum[j] - BNum[i - 1];
            if(B < b) i = B_idx + 1;
            if(map[j] == 'B') B_idx = j;

            if (W <= w && B >= b) {
                if (ans < j - i + 1) ans = j - i + 1;
            }
        }
    }

    printf("%d\n", ans);
}