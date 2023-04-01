#include <iostream>
using namespace std;

int T, H, W, N;


int main() {
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        scanf("%d %d %d", &H, &W, &N);


        for(int i = 1; i <= W; i++) {
            bool flag = false;
            for(int j = 1; j <= H; j++) {
                if(--N == 0) {
                    flag = true;
                    printf("%d%02d\n", j, i);
                    break;
                }
            }
            if(flag) break;
        }
    }


}